#ifndef __STACK__H__
#define __STACK__H__

#include <stdio.h>
#include <stdlib.h>

/* ----------------- PILE ---------------- */

/*Structure de controle ( PILE ) */
typedef struct Element Element ;
struct Element 
{
    /* un element de file va contenir  une valeur  
    et un pointeur next vers un autre element */
    int value;
    Element *next;

};



Element* new_stack();
void push_stack(Element *st,int x);
void clear_stack(Element *st);
void print_stack(Element *st);
void pop_stack(Element *st);
int top_stack(Element *st);
int lenght_stack(Element *st);


#endif