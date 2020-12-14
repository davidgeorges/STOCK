#include "queue.h"


/*-------------------------------------------------------*/
/* Fonction qui check si la queue est vide */
int is_empty_queue(Queue *qu){
    if(qu==NULL){
      return 1;
    }

  return 0;
}

/*-------------------------------------------------------*/
/* Fonction qui retourne une queue null */
Queue *new_list(void){
  return NULL;
}

/*-------------------------------------------------------*/
/* Fonction qui retourne la taille de la queue*/
int queue_length(){
    return nb_elements;
}

/*-------------------------------------------------------*/
/* Fonction qui retourne la valeur du premier dans la queue*/
int queue_first(Queue *qu){

  if (is_empty_queue(qu)==1)
  {
    printf("La queue est vide  ! \n");
  }


  return qu->value;
  
}

/*-------------------------------------------------------*/
/* Fonction qui insère un element la fin de la liste */
Queue *push_queue(Queue *qu, int x){

  /*crée un nouvel element  avec allocation dynamique*/
  Queue *element;
  element = malloc(sizeof(*element));/* chaque element est allouer dynamiquement */

  if (element == NULL)
  {
    printf("Erreur lors de l'allocation dynamique \n");
  }
  
  element->value = x;
  element->next = NULL;
  printf("Ajout a la place [%d] la valeur [%d] \n",nb_elements,element->value);

  if (qu==NULL)
  {
    nb_elements++;
    return element;
    
  }

  Queue *temp;
  temp = qu;

  

  while (temp->next!=NULL)
  {
    temp = temp->next;
    /*Affichage pour voir le fonctionnement
    printf("Valeur avec qu [%d]  \n", qu->value);
    printf("Valeur avec temp [%d]  \n", temp->value);
    */
  }
  
  
  /* temps vaut le dernier element */
  temp->next = element;
  //printf("Elem :[%d] \n",element->value);
  //printf("Qu: [%d] \n",qu->value);


  /* ne pas retourner temp ! si nous le retournons on retourne 
  l'avant dernier element et le dernier element insérerer */
  

  nb_elements++;
  return qu;/* retourne tout la liste avec le dernier element en fin */
  
}

/*-------------------------------------------------------*/
/* Fonction qui affiche la queue */
void print_queue(Queue *qu){
    if (is_empty_queue(qu)==1)
    {
        printf("Impossible d'afficher la queue est vide  ! \n");
    }

  while (qu != NULL)
  {
    printf("Valeur [%d]  \n", qu->value);
    qu = qu->next;
  }
}

/*-------------------------------------------------------*/
/* Fonction qui efface la premier en tete de queue */
Queue *pop_queue(Queue *qu){
    if (is_empty_queue(qu)==1)
    {
      printf("Impossible d'efface le première element d'une liste vide ! \n");
      return qu;
    }

    Queue *element = malloc(sizeof(*element));
    if (element == NULL)
    {
      printf(" Erreur lors de l'allocation dynamique \n");
      exit(EXIT_FAILURE);
    }

    printf("Effacement de la valeur [%d] en tête \n",qu->value);
    element=qu->next;

    free(qu);
    nb_elements--;
    return element;

}

Queue *del_queue(Queue *qu){
    if (is_empty_queue(qu)==1)
    {
      printf("Impossible d'efface le première element d'une liste vide ! \n");
      return new_list();
    }
    
    while (qu !=NULL)
    {
      qu = pop_queue(qu);
    }

}
