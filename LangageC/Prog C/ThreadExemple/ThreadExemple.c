#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#define psleep(sec) sleep ((sec))

 
#define INITIAL_STOCK   20
#define NB_CLIENTS      3
 
 
/* Structure stockant les informations des threads clients et du magasin. */
typedef struct
{
   int stock;
 
   pthread_t thread_store;
   pthread_t thread_clients [NB_CLIENTS];
 
   pthread_mutex_t mutex_stock;
   pthread_cond_t cond_stock;
   pthread_cond_t cond_clients;
}
store_t;

/*Variable globale a eviter ! ( on l'utilise seulement pour cette exemple*/
static store_t store =
{
   .stock = INITIAL_STOCK,
   .mutex_stock = PTHREAD_MUTEX_INITIALIZER,
   .cond_stock = PTHREAD_COND_INITIALIZER,
   .cond_clients = PTHREAD_COND_INITIALIZER,
};

 
 
/* Fonction pour tirer un nombre au sort entre 0 et max. */
static int get_random (int max)
{
   double val;
 
   val = (double) max * rand ();
   val = val / (RAND_MAX + 1.0);
 
   return ((int) val); // valeur a recuperer du sotck
}
 
 
/* Fonction pour le thread du magasin. */
static void * fn_store (void * p_data)
{
   while (1)
   {
      /* on verouille , on est les seul a pouvoir modifier les données*/
      pthread_mutex_lock (& store.mutex_stock);
      /*on attend un signal pour executer le thread  ( on attend le reveil )*/
      pthread_cond_wait (& store.cond_stock, & store.mutex_stock);
 
      /* on modifie les données*/
      store.stock = INITIAL_STOCK;
      printf ("Remplissage du stock de %d articles !\n", store.stock);

      /*on reveille le thread qui a appeler cette fonction* (on reveille le thread client qui a appeler cette fonction pour qu'il execute sa fonction) */
      pthread_cond_signal (& store.cond_clients);
      pthread_mutex_unlock (& store.mutex_stock);
      /*on deverouille , un thread peut le verouiller pour modifier les données*/
   }
 
   return NULL;
}
 
 
/* Fonction pour les threads des clients. */
static void * fn_clients (void * p_data)
{
   int nb = (int) p_data;
 
   while (1)
   {
      int val = get_random (6);
 
   
      psleep (get_random (3));
      /* on verouille , on est les seul a pouvoir modifier les données*/
      pthread_mutex_lock (& store.mutex_stock);
 
      if (val > store.stock)
      {  
         /*on reveille le thread  stock pour remettre 20 element dans le stock */
         pthread_cond_signal (& store.cond_stock);
         /*on attend un signal pour executer le reste (on attend le reveil )*/
         pthread_cond_wait (& store.cond_clients, & store.mutex_stock);
      }
 
      store.stock = store.stock - val;
      printf ("Client %d prend %d du stock, reste %d en stock !\n",nb, val, store.stock);

      /*on deverouille , un thread peut le verouiller pour modifier les données*/
      pthread_mutex_unlock (& store.mutex_stock);
   }
}
 
 
 
int main (void)
{
   int i = 0;
   int ret = 0;
 
 
   /* Creation du thread du magasin. */
   printf ("Creation du thread du magasin !\n");
   ret = pthread_create (& store.thread_store, NULL,fn_store, NULL);/*creation de thread ,  fn_stire (fonction a executer pour le threads),
    pas d'argument pour cette fonction */
   /* L'exécution du thread se fait soit jusqu'à la fin de sa fonction ou bien jusqu'à son annulation*/
 
   /* Creation des threads des clients si celui du magasin a reussi. */
   if (! ret)
   {
      for (i = 0; i < NB_CLIENTS; i++)
      {
         ret = pthread_create (&store.thread_clients [i], NULL,fn_clients, (void *) i);/*creation de thread ,  fn_clients (fonction a executer pour le threads),
         ((void *) i) = argument pour la fonction, ici c'est le compteur) */
         /* L'exécution du thread se fait soit jusqu'à la fin de sa fonction ou bien jusqu'à son annulation*/
         
        printf("Creation threads clients [%d] !\n",i);
 
         if (ret)
         {
            fprintf (stderr, "%s", strerror (ret));
         }
      }
   }
   else
   {
      fprintf (stderr, "%s", strerror (ret));
   }
 
 
   /* Attente de la fin des threads. */
   i = 0;
   for (i = 0; i < NB_CLIENTS; i++)
   {
      pthread_join (store.thread_clients [i], NULL);
   }
   pthread_join (store.thread_store, NULL);
 
 
   return EXIT_SUCCESS;
}