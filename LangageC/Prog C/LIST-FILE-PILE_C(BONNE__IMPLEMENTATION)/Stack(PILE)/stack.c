#include "stack.h"

/* ----------------- PILE ---------------- */

/*-------------------------------------------------------*/
/* Fonction qui retourne une pile(stack) null */
Element* new_stack(){
    Element *st= malloc(sizeof(*st));
    st->next=NULL;//aucun element
    return st;
}

/*-------------------------------------------------------*/
/* Fonction qui insère dans la pile(au dessu de tout les autres)*/
void push_stack(Element *st,int x){

    Element *element;

    element = malloc(sizeof(*element));/* l'ordinateur ne connait pas la taille d'un element de pile */

    element->value =x;
    element->next = NULL;
    if (element == NULL)
    {
    printf("Erreur lors de l'allocation dynamique \n");
    }

    /*Si on a que un element*/
    if (st->next== NULL)
    {

        printf("La pile est vide on insere le premiere element\n");
        st->next =  element;
        //printf("ICI 0 ! \n");
        return;
    }

    Element *temp = st;
    //printf("ICI 1 ! \n");

    while (temp->next !=NULL)
    {
        temp=temp->next;
    }
     
    /*ici on est en haut de la pile*/
    temp->next = element;
    //printf("ICI 2 ! \n");

}

/*-------------------------------------------------------*/
/* Fonction qui efface la pile*/
void clear_stack(Element *st){

    Element *element;
    if (st->next==NULL)
    {
        printf("La pile est deja vide ! \n");
        return ;
    }


    while (st->next !=NULL)
    {
        pop_stack(st);
    }
}

/*-------------------------------------------------------*/
/* Fonction qui affiche la pile*/
void print_stack(Element *st){

    if (st->next== NULL)
    {
        printf("Impossible d'afficher une liste vide ! \n");
        return ;
    }

    Element *temp = st;
    //printf("ICI 4 ! \n");
    while (temp->next!=NULL)
    {
        temp=temp->next;
        printf("Valeur : [%d]\n",temp->value);
    }
    //printf("ICI 5 ! \n");
    
}

/*-------------------------------------------------------*/
/* Fonction qui enleve la valeur au dessus de la pile*/
void pop_stack(Element *st){

    Element *element;
    
    if (st->next==NULL)
    {
        printf("La pile est vide ! \n");
        return;
    }

    /* element prend toute la pile sauf l'element au dessus*/
    Element *temp = st;
    Element *before = st;

    while (temp->next !=NULL)
    {
        before = temp;
        temp=temp->next;
    }

    printf("Valeur effacer %d \n",temp->value);
    
    before->next=NULL;//l'element d'avant la fin pointe sur NULL 
    temp= NULL;
    free(temp);//on libere la mémoire de l'element supprimer
    
    



}


/*-------------------------------------------------------*/
/* Fonction qui envoie la valeur du sommet de la pile*/
int top_stack(Element *st){

    if (st->next==NULL)
    {
        printf("Aucun sommet,la pile est vide ! \n");
        return EXIT_FAILURE;
    }

    Element *temp = st;

    while (temp->next !=NULL)
    {
        temp=temp->next;
    }

    return temp->value;
}

/*-------------------------------------------------------*/
/* Fonction qui envoie la taille de la pile*/
int lenght_stack(Element *st){
    int lenght=0;

    Element *temp = st;

    while (temp->next !=NULL)
    {
        temp=temp->next;
        lenght++;
    }
    return lenght;
}