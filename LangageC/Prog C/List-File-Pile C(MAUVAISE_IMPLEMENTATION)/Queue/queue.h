#ifndef __QUEUE__H__
#define __QUEUE__H__

#include <stdio.h>
#include <stdlib.h>

/* ----------------- FILES ---------------- */

/*Définition type Boolean : première valeur prend 0 et la deuxième prend...*/

/*Structure de controle ( FILES ) */
typedef struct Queue Queue;
struct Queue
{
    /* un element de file va contenir  une valeur  
    et un pointeur next vers un autre element */
    int value;
    Queue *next;

};


typedef struct First First;
struct First
{
    /* un element de file va contenir  une valeur  
    et un pointeur next vers un autre element */
    int value;
    Queue *next;

};



/*Structure de controle  premier element*/


static int nb_elements =0;



/* Prototypes */
int is_empty_queue(Queue *);
Queue* new_list(void);
int queue_length();
int queue_first(Queue *qu);
Queue* push_queue(Queue *qu, int x);
void print_queue(Queue *);
Queue* pop_queue(Queue *);
Queue* del_queue(Queue *);

#endif