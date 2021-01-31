#include "list.h"
int nb_client=0;
/* ----------------- LISTES CHAINEES ---------------- */

/*-------------------------------------------------------*/
/* Fonction qui retourne une list null */
List* new_list(void){

  List *liste = malloc(sizeof(*liste));
  liste->premier=NULL;
  return liste;
}


/*-------------------------------------------------------*/
/* Fonction qui renvoie la longueur de la list */
int list_length(List *li){
  int size= 0;

  Element *actuel = li->premier;

  while (actuel != NULL)
  {
    size++;
    actuel = actuel->next;
  }
  return size;
}

/*-------------------------------------------------------*/
/* Fonction qui affiche la list entière */
void print_list(List *li){
  
  if (li->premier== NULL)
  {
    printf("Impossible d'afficher une liste vide ! \n");
    return;
  }
  int i =0;
  Element *actuel = li->premier;

  while (actuel!= NULL)
  {
    printf("Valeur [%d] incide [%d]  \n", actuel->value,i);
    actuel = actuel->next;
    i++;
  }
  
}

/*-------------------------------------------------------*/
/* Fonction qui insère un nouvel élement a la fin de la liste */
void insertBack(List *li, int x){

  /*crée un nouvel element  avec allocation dynamique*/
  Element *element = malloc(sizeof(*element));/* chaque element est allouer dynamiquement */

  if (element == NULL)
  {
    printf(" Erreur lors de l'allocation dynamique \n");
  }

  element->value=x;

  Element *temp=li->premier;

  while (temp->next!=NULL)
  {
    temp=temp->next;
  }

  element->next=NULL;
  temp->next=element;
  

  
}

/*-------------------------------------------------------*/
/* Fonction qui insère un nouvel élement au debut de la liste */
void  insertFront(List *li, int x){

  /*crée un nouvel element  avec allocation dynamique*/
  Element *nouveau = malloc(sizeof(*nouveau));/* chaque element est allouer dynamiquement */

  if (nouveau == NULL)
  {
    printf(" Erreur lors de l'allocation dynamique \n");
    EXIT_FAILURE;
  }

  nouveau->value = x;

  /*la liste est vide*/
  if(li->premier==NULL){

    nouveau->next=NULL;
    li->premier=nouveau;

  }else
  {
    nouveau->next=li->premier;
    li->premier=nouveau;
  }
  nb_client++;

  
}

/*---------------------Fonctionne pas------------------------*/
/* Fonction qui supprime le dernier element en fin de liste*/
void deleteBack(List *li){

  if(li->premier==NULL){
    printf("Impossible de supprimer l'element d'une liste vide.\n");
    return;
  }



  Element *temp= li->premier;
  Element *avant = li->premier;


  while (temp->next !=NULL)
  {
    avant = temp;
    temp = temp->next;
  }

  printf("Supression de %d",temp->value);
  avant->next=NULL;
  temp=NULL;
  free(temp);

  printf("ici 1");
  
 
}

/*-------------------------------------------------------*/
/* Fonction qui supprime le premier element en debut de liste */
void deleteFront(List *li){
  
  if (li->premier== NULL)
  {
    printf("La liste est vide.\n");
    return;
  }


  
  Element *aSupprimer = li->premier;
  printf("Supression de %d \n",aSupprimer->value);
  li->premier = li->premier->next;
  aSupprimer=NULL;
  free(aSupprimer);
  

}

/*-------------------------------------------------------*/
/* Fonction qui supprime le premier element  tant que la liste n'est pas vider */
void del_list(List *li){
  if (li->premier==NULL)
  {
    printf("La liste est vide.\n");
    return;
  }

  while (li->premier!=NULL)
  {
    deleteFront(li);
  }

}

