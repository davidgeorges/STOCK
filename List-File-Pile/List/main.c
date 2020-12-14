#include "list.h"


int main(int argc, char const *argv[])
{
    
    List *list = new_list();

    /*
    if (is_empty_list(list))
    {
        printf("Liste vide ! \n");
    }
    printf("Affichage taille [%d] \n",list_length(list));
    */
    
    list = push_back_list(list,50);
    list = push_back_list(list,20);
    /*
    list = push_back_list(list,25);
    list = push_front_list(list,2);
    list = push_front_list(list,3);
    print_list(list);
    */
   //list  = pop_back_list(list);


   /*
   int x=5;
   int *temp;
   int *liste = &x;

   temp = liste;
   printf("%d \n",*temp);
   printf("%d \n",*liste);
   *temp = 2;
   printf("%d \n",*temp);
   printf("%d \n",*liste);
   *liste = 2*5;
    //temp = list;
   printf("%d \n",*temp);
   printf("%d \n",*liste);
   */
   
    return 0;
}
