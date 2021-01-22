#include "stack.h"

/* ----------------- PILE ---------------- */

/*-------------------------------------------------------*/
/* Fonction qui retourne une pile(stack) null */
Stack* new_stack(){
    return NULL;
}

/*-------------------------------------------------------*/
/* Fonction qui check si la pile est vide*/
int is_empty_stack(Stack *st){
    if (st ==NULL)
    {
        return 1;
    }

    return 0;
}

/*-------------------------------------------------------*/
/* Fonction qui insère une valeur en fin de pile*/
Stack* push_stack(Stack *st,int x){

    Stack *element;

    element = malloc(sizeof(*element));/* l'ordinateur ne connait pas la taille d'un element de pile */

    if (element == NULL)
    {
        printf("La pile est vide");
        return EXIT_FAILURE;
    }

    element->value =x;
    element->next = st; /* le dernière element pointe la pile entière */
    /* l'element ce met au dessus de la pile */

    return  element;/* element contient la pile*/

}

/*-------------------------------------------------------*/
/* Fonction qui efface la pile*/
Stack* clear_stack(Stack *st){

    Stack *element;
    if (is_empty_stack(st)==1)
    {
        printf("La pile est deja vide ! \n");
        return ;
    }

        /* element prend toute la pile sauf l'element au dessus*/
        element = st->next;
        free(st);

        return  clear_stack(element);/* recursivité */
}

/*-------------------------------------------------------*/
/* Fonction qui affichage la pile*/
void print_stack(Stack *st){

    if (is_empty_stack(st)==1)
    {
        printf("La pile est vide ! \n");
        return ;
    }
    
    while (is_empty_stack(st)==0)
    {
        printf("Valeur : [%d]\n",st->value);
        st = st->next;
    }
    
    
}

/*-------------------------------------------------------*/
/* Fonction qui enleve la valeur au dessus de la pile*/
Stack* pop_stack(Stack *st){

    Stack *element;
    
     if (is_empty_stack(st)==1)
    {
        printf("La pile est vide ! \n");
        return;
    }

    /* element prend toute la pile sauf l'element au dessus*/
    element = st->next;
    free(st);

    
    return element;/*return la pile sans l'element du dessus*/

}


/*-------------------------------------------------------*/
/* Fonction qui envoie la valeur du sommet de la pile*/
int top_stack(Stack *st){

    if (is_empty_stack(st)==1)
    {
        printf("Aucun sommet,la pile est vide ! \n");
        return EXIT_FAILURE;
    }

    return st->value;
}

/*-------------------------------------------------------*/
/* Fonction qui envoie la taille de la pile*/
int lenght_stack(Stack *st){
    int lenght=0;

     while (is_empty_stack(st)==0)
    {
        lenght++;
        st = st->next;
    }

    return lenght;
}