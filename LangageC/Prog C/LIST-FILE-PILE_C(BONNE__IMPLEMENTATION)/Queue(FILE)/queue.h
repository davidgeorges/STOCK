#ifndef __QUEUE__H__
#define __QUEUE__H__

#include <stdio.h>
#include <stdlib.h>

/* ----------------- FILES ---------------- */

/*Définition type Boolean : première valeur prend 0 et la deuxième prend...*/

/*Structure de controle ( FILES ) */
typedef struct Element Element ;
struct Element 
{
    /* un element de file va contenir  une valeur  
    et un pointeur next vers un autre element */
    int value;
    Element  *next;

};


typedef struct Queue Queue;
struct Queue 
{
    /* un element de file va contenir  une valeur  
    et un pointeur next vers un autre element */
    Element  *premier;

};



/*Structure de controle  premier element*/


static int nb_elements =0;



/* Prototypes */
Queue* new_list(void);
int queue_length();
int queue_first(Queue *qu);
void push_queue(Queue *qu, int x);
void print_queue(Queue *);
void pop_queue(Queue *);
void del_queue(Queue *);

#endif