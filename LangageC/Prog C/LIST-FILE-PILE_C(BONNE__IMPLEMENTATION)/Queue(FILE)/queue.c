#include "queue.h"


/*-------------------------------------------------------*/
/* Fonction qui retourne une queue null */
Queue* new_list(void){
  Queue *ft= malloc(sizeof(*ft));
  ft->premier=NULL;
  return ft;
}

/*-------------------------------------------------------*/
/* Fonction qui retourne la taille de la queue*/
int queue_length(){
    return nb_elements;
}


/*-------------------------------------------------------*/
/* Fonction qui insère un element la fin de la liste */
void push_queue(Queue *qu, int x){

  /*crée un nouvel element  avec allocation dynamique*/
  Element *element=malloc(sizeof(*element));/* chaque element est allouer dynamiquement */

  if (element == NULL)
  {
    printf("Erreur lors de l'allocation dynamique \n");
  }
  
  element->value = x;
  element->next = NULL;
  printf("Ajout a la place [%d] la valeur [%d] \n",nb_elements,element->value);

  if (qu->premier==NULL)
  {
    qu->premier=element;
    nb_elements++;
    
  }else
  {

  Element *temp;
  temp = qu->premier;

  while (temp->next!=NULL)
  {
    temp = temp->next;

  }
  
  /* temps vaut le dernier element */
  temp->next = element;
  
  nb_elements++;
  }
  
}

/*-------------------------------------------------------*/
/* Fonction qui affiche la queue */
void print_queue(Queue *qu){


  if (qu->premier==NULL)
  {
    printf("Impossible d'afficher la queue est vide  ! \n");
    return;
  }

  Element *actuel = qu->premier;
  while (actuel!= NULL)
  {
    printf("Valeur [%d]  \n", actuel->value);
    actuel =actuel->next;
  }
}

/*-------------------------------------------------------*/
/* Fonction qui efface la premier en tete de queue */
void pop_queue(Queue *qu){

  if (qu->premier==NULL)
  {
    printf("Impossible d'efface le premiere element d'une liste vide ! \n");
    return;
  }

    Element *aSupprimer = qu->premier;
    qu->premier = qu->premier->next;
    aSupprimer=NULL;

    free(aSupprimer);
    nb_elements--;
    
}

void del_queue(Queue *qu){ 
    if (qu->premier==NULL)
    {
      printf("Impossible d'efface le premiere element d'une liste vide ! \n");
    }
    
    while (qu->premier !=NULL)
    {
      pop_queue(qu);
    }

}
