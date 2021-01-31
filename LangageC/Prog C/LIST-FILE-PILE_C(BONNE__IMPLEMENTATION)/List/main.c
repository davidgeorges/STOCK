#include "list.h"


int main(int argc, char const *argv[])
{
    
    List *list = new_list();
    
    insertFront(list,50);
    insertFront(list,20);
    insertBack(list,25);
    int value =list_length(list);
    printf("Longueur de la liste %d avant\n",value);
    print_list(list);
    del_list(list);
    int value2 =list_length(list);
    printf("Longueur de la liste %d apres\n",value2);
    print_list(list);
    
    printf("Avant \n");
    //FONCTIONNE PAS
    deleteBack(list);
    print_list(list);
    /*deleteBack(list);
    deleteBack(list);
    deleteBack(list);
    deleteBack(list);
    deleteBack(list);
    deleteBack(list);

    print_list(list);*/
   
    return 0;
}
