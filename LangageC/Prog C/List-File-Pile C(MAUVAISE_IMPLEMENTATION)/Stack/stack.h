#ifndef __STACK__H__
#define __STACK__H__

#include <stdio.h>
#include <stdlib.h>

/* ----------------- PILE ---------------- */

/*Structure de controle ( PILE ) */
typedef struct Stack Stack;
struct Stack
{
    /* un element de file va contenir  une valeur  
    et un pointeur next vers un autre element */
    int value;
    Stack *next;

};

Stack* new_stack();
int is_empty_stack(Stack *st);
Stack* push_stack(Stack *st,int x);
Stack* clear_stack(Stack *st);
void print_stack(Stack *st);
Stack* pop_stack(Stack *st);
int top_stack(Stack *st);
int lenght_stack(Stack *st);


#endif