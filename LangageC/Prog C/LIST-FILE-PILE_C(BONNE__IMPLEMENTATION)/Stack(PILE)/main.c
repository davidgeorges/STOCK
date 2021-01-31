#include "stack.h"


int main(int argc, char const *argv[])
{
    
    Element *pile = new_stack();
    int val;
    int taille;
    push_stack(pile,10);
    push_stack(pile,40);
    push_stack(pile,84);

    print_stack(pile);

    val = top_stack(pile);
    printf("Affichage valeur au top %d \n",val);
    taille = lenght_stack(pile);
    printf("Affichage taille de la pile %d \n",taille);

    /*
    pop_stack(pile);
    print_stack(pile);
    val = top_stack(pile);
    printf("Affichage valeur au top %d \n",val);
    taille = lenght_stack(pile);
    printf("Affichage taille de la pile %d \n",taille);
     pop_stack(pile);
      pop_stack(pile);
       pop_stack(pile);

    val = top_stack(pile);
    printf("Affichage valeur au top %d \n",val);
    taille = lenght_stack(pile);
    printf("Affichage taille de la pile %d \n",taille);*/
       
       


    
   
    return 0;
}