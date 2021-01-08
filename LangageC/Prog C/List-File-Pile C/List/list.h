#ifndef __LIST__H__
#define __LIST__H__

#include <stdio.h>
#include <stdlib.h>

/* ----------------- LISTES CHAINEES ---------------- */


/*Structure de controle  (liste ) */
typedef struct List List;
struct List
{
    /* un element de liste va contenir  une valeur  
    et un pointeur next vers un autre element */
    int value;
    List *next;

};

/* Prototypes */
List *new_list(void);
int is_empty_list(List  *li);
int list_length(List *li);
void print_list(List *li);
List *push_back_list(List *li, int x);
List *push_front_list(List *li, int x);
List *pop_back_list(List *li);
List *pop_front_list(List *li);
List *del_list(List *li);

#endif