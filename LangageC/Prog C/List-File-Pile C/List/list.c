#include "list.h"

/* ----------------- LISTES CHAINEES ---------------- */

/*-------------------------------------------------------*/
/* Fonction qui retourne une list null */
List *new_list(void){
  return NULL;
}

/*-------------------------------------------------------*/
/* Fonction qui renvoie si la list est vide */
int is_empty_list(List  *li){
  if(li == NULL)
    return 1;

  return 0;
}

/*-------------------------------------------------------*/
/* Fonction qui renvoie la longueur de la list */
int list_length(List *li){
  int size= 0;
  while (li != NULL)
  {
    size++;
    li = li->next;
  }
  return size;
}

/*-------------------------------------------------------*/
/* Fonction qui affiche la list entière */
void print_list(List *li){
  
  if (is_empty_list(li) == 1)
  {
    printf("Votre list est vide ! \n");
    return;
  }

  while (li != NULL)
  {
    printf("Valeur [%d]  \n", li->value);
    li = li->next;
  }
  
}

/*-------------------------------------------------------*/
/* Fonction qui insère un nouvel élement a la fin de la liste */
List *push_back_list(List *li, int x){

  /*crée un nouvel element  avec allocation dynamique*/
  List *element;
  element = malloc(sizeof(*element));/* chaque element est allouer dynamiquement */

  if (element == NULL)
  {
    printf(" Erreur lors de l'allocation dynamique \n");
  }

  element->value = x;
  element->next = NULL;

  if (is_empty_list(li) ==1)
  {
    return element;
  }

  /*Pour ne pas modifier directement au niveau li */
  /* Pointeur qui pointe sur un pointeur ( ils pointent au même endroit) ( comme passage par reference)*/
  /* li ne change pas de valeur */
  List *temp;
  temp = li;

  while (temp->next!=NULL)
  {
    temp = temp->next;
    /*Affichage pour voir le fonctionnement
    printf("Valeur avec li [%d]  \n", li->value);
    printf("Valeur avec temp [%d]  \n", temp->value);
    */
  }

  
  /* temps vaut le dernier element */
  temp->next = element;
  printf("elem :[%d]",element->value);
  printf(" li [%d]",li->value);

  /* Affichage pour voir le fonctionnement
  printf("Valeur avec li ici [%d]  \n", li->value);
  printf("Valeur avec ele ici [%d]  \n", element->value);
  printf("Valeur avec temp ici [%d]  \n", temp->value);
  */
  

  /* ne pas retourner temp ! si nous le retournons on retourne 
  l'avant dernier element et le dernier element insérerer */
  
  return li;/* retourne tout la liste avec le dernier element en fin */
  
}

/*-------------------------------------------------------*/
/* Fonction qui insère un nouvel élement au debut de la liste */
List *push_front_list(List *li, int x){

  /*crée un nouvel element  avec allocation dynamique*/
  List *element;
  element = malloc(sizeof(*element));/* chaque element est allouer dynamiquement */

  if (element == NULL)
  {
    printf(" Erreur lors de l'allocation dynamique \n");
    EXIT_FAILURE;
  }

  element->value = x;

  if (is_empty_list(li) ==1)
  {
    element->next = NULL;
  }else
  {
    element->next = li;
  }

  return element;
  
}

/*-------------------------------------------------------*/
/* Fonction qui supprime le dernier element en fin de liste */
List *pop_back_list(List *li){

  /* si liste vide */
  if (is_empty_list(li) ==1)
  {
    return new_list();
  }

   /* si contient qu'un seul element */
  if (li->next == NULL){
    
    free(li);/*libére la mémoire */
    li = NULL;/* derrière l'element liberer on lui affecte null */

    return new_list();  /* retourne une liste vide vue qu'ont a supprimer notre seul element */
  
  }
  

  List *temp = li;
  List *before = li; 

  while (temp->next != NULL)
  {
    /* before pointe vers l'avant dernier element (temp->next-1) */
    /* before vaut temp et temp l'element d'apres */
    before = temp;
    temp = temp->next;
    /*
    printf("Valeur avec li en bas [%d]  \n", li->value);
    printf("Valeur avec temp en bas [%d]  \n", temp->value);
    printf("Valeur avec before en bas [%d]  \n", before->value);
    */
    
  }
  
  
  /* on a trouver le dernier element et donc aussi l'avant dernier element */
  before->next = NULL;
  /*l'avant dernier element va valoir null (before)
  et on libère l'element qu'ont supprime a la fin donc temp */
  free(temp);/*libére la mémoire */
  temp = NULL;

  return li;
 
}

/*-------------------------------------------------------*/
/* Fonction qui supprime le premier element en debut de liste */
List *pop_front_list(List *li){
  if (is_empty_list(li) ==1)
  {
    return li;
  }

  List *element;
  element = malloc(sizeof(*element));/* chaque element est allouer dynamiquement */

  if(element==NULL){
    printf(" Erreur lors de l'allocation dynamique \n");
    EXIT_FAILURE;
  } 

  /* li = debut de liste , donc li->next est le "deuxième element" */
  element = li->next;/* on recupere tout sauf le première element */

  free(li);/*libére la mémoire */
  li=NULL;
  return element;/*element vaut la liste li sans le premièrer element */

}

/*-------------------------------------------------------*/
/* Fonction qui supprime le premier element  tant que la liste n'est pas vider */
List *del_list(List *li){
  if (is_empty_list(li) ==1)
  {
    return new_list();
  }

  while (li!=NULL)
  {
    li = pop_front_list(li);
  }

}

