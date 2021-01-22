#include "listdouble.h"


int main(int argc, char const *argv[])
{
    
    ListD *li= new_list();
    print_list(li);
    li = push_back(li,15);
    li = push_back(li,13);
    li = push_back(li,12);
    li = push_front(li,14);
    print_list(li);
    li=del_list(li);

    return 0;
}