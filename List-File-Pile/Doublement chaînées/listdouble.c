#include "listdouble.h"


/*-------------------------------------------------------*/
/* Fonction qui retourne une list null */
ListD *new_list(){
    return NULL;
}

/*-------------------------------------------------------*/
/* Fonction qui retourne une list null */
Bool is_empty(ListD *li){
    if (li==NULL)
    {
        return true;
    }
    return false;
}

/*-------------------------------------------------------*/
/* Fonction qui la taille de la list*/
int list_length(ListD * li){
    if (is_empty(li))
    {
        printf("Aucune taille ! la list est vide. \n");
        return 0;
    }
    
    return li->length;
}

/*-------------------------------------------------------*/
/* Fonction qui la valeur du première élement */
int list_first(ListD *li){
    if (is_empty(li))
    {
        printf("Impossible de renvoyer le première élément la liste est vide. \n");
        return 0;
    }

    return li->begin->value;

}

/*-------------------------------------------------------*/
/* Fonction qui renvoie la valeur du dernier élement */
int list_last(ListD *li){
    if (is_empty(li))
    {
        printf("Impossible de renvoyer le dernier élément la liste est vide. \n");
        return 0;
    }

    return li->end->value;
}

/*-------------------------------------------------------*/
/* Fonction qui affiche la liste */
void print_list(ListD *li){
    if (is_empty(li))
    {
        printf("Rien a affiche ! la list est vide. \n");
        return ;
    }

    ListElement *temp = li->begin;

    while (temp !=NULL)
    {
        printf("Valeur [%d] \n",temp->value);
        temp=temp->next;
    }

}

/*-------------------------------------------------------*/
/* Fonction qui met un élement a la fin de la liste */
ListD *push_back(ListD *li,int x){

    ListElement *element; /* un element de la liste */
    element = malloc(sizeof(*element));

    if (element ==NULL)
    {
        printf("Erreur allocation pour element... \n");
    }
    
    /*Initialisation de l'élément */
    element->value = x;
    element->next = NULL;
    element->back = NULL;

    if (is_empty(li))
    {
        li = malloc(sizeof(*li));
        if (li ==NULL)
        {
            printf("Erreur allocation pour li... \n");
        }
        /*Si la list est vide la taille commence 0 , le debut = element et la fin aussi
        comme on a qu'un seul element */
        li->length = 0;
        li->begin = element;
        li->end = element;
    }else
    {   
        
        li->end->next = element;//l'élement de la fin de liste de droite pointe sur element
        element->back = li->end;//le pointeur de gauche du nouvel element pointe sur la gauche de la liste
        li->end =element;// maintenant le pointeur de fin de liste pointe sur le nouvel element
    }
    
    li->length++;

    return li;
}


/*-------------------------------------------------------*/
/* Fonction qui met un élement au debut de la liste */
ListD *push_front(ListD *li,int x){

    ListElement *element; /* un element de la liste */
    element = malloc(sizeof(*element));

    if (element ==NULL)
    {
        printf("Erreur allocation pour element... \n");
    }
    
    /*Initialisation de l'élément */
    element->value = x;
    element->next = NULL;
    element->back = NULL;

    if (is_empty(li))
    {
        li = malloc(sizeof(*li));
        if (li ==NULL)
        {
            printf("Erreur allocation pour li... \n");
        }
        /*Si la list est vide la taille commence 0 , le debut = element et la fin aussi
        comme on a qu'un seul element */
        li->length = 0;
        li->begin = element;
        li->end = element;
    }else
    {   
        
        li->begin->back = element;//l'élement de debut de liste sont pointeur de gauche  pointe sur le nouvel element
        element->next= li->begin;//le pointeur droite du nouvel element pointe sur le debut de la liste
        li->begin =element;// maintenant le pointeur  de debut de liste pointe sur le nouvel element
    }
    
    li->length++;

    return li;
}


/*-------------------------------------------------------*/
/* Fonction qui efface  un élement a la fin de la liste */
ListD *pop_back(ListD *li){
    if (is_empty(li))
    {
        printf("Rien  a supprimer a la fin, la liste est vide. \n");
        return 0;
    }

    /* si il y a qu'un seul element */
    if(li->begin == li->end){
        
        /*on libère la mémoire et on initialise li a null */
        free(li);
        li = NULL;
        return new_list();/*on retourne une liste vide */
    }

    ListElement *temp = li->end;/*on accede a li->end pour pouvoir initiliaser le pointeur back de li par la suite*/
   
   
    /*le dernier element pointe vers l'avant dernier */
    li->end = li->end->back;
    li->end->next = NULL;/* comme on supprime l'element celui de droite vaut NULL ( est supprimer ) */
    temp->next = NULL; /*!!!! CETTE LIGNE NEST PAS OBLIGATOIRE SACHANT QUE end->next EST TOUJOURS NULL !!!!*/
    temp->back = NULL;/* comme on supprime le dernier element on a initialiser le pointeur de droite a null et
    et il faut aussi initialise le pointeur de gauche a null on accedant avec temp qui lui vaut li->end */
 
 

    free(temp);
    temp = NULL;
    
    li->length--;
    return li;

}


/*-------------------------------------------------------*/
/* Fonction qui efface un élement au debut de la liste */
ListD *pop_front(ListD *li){
    if (is_empty(li))
    {
        printf("Rien  a supprimer a la fin, la liste est vide. \n");
        return 0;
    }

    /* si il y a qu'un seul element */
    if(li->begin == li->end){
        
        /*on libère la mémoire et on initialise li a null */
        free(li);
        li = NULL;
        return new_list();/*on retourne une liste vide */
    }

    ListElement *temp = li->begin;/*on accede a li->end pour pouvoir initiliaser le pointeur back de li par la suite*/


    /*le dernier element pointe vers l'avant dernier */
    li->begin= li->begin->next;
    li->begin->back = NULL;/* comme on supprime l'element celui de gauche vaut NULL ( est supprimer ) */
    temp->back = NULL; /*!!!! CETTE LIGNE NEST PAS OBLIGATOIRE SACHANT QUE begin->back EST TOUJOURS NULL !!!!*/
    temp->next = NULL;/* comme on supprime le premier element on a initialiser le pointeur de droite a null et
    et il faut aussi initialise le pointeur de gauche a null on accedant avec temp qui lui vaut li->begin */


    free(temp);
    temp = NULL;
    
    li->length--;
    return li;

}


/*-------------------------------------------------------*/
/* Fonction qui Supprime toute la liste */
ListD *del_list(ListD *li){
    while (!is_empty(li))
    {
        li =pop_front(li);
    }
      
    printf("La liste est maintenant vide ! \n");
    return new_list();
}