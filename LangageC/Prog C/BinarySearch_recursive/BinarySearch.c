
int binarySearch(int tab[], int debut, int fin, int x) 
{ 
    /* x : valeur a chercher */

    /* condition d'arret */
   if (fin >= debut) 

   {    /* calcul milieu du tableau */
        int milieu = debut + (fin - debut)/2;
  
        /* si l'element est au milieu on la trouver */
        if (tab[milieu ] == x) {
            return milieu ; 
        }

        /* Si l'element est plus petit que la  valeur au milieu, il sera dans la parti gauche du tableau */
        if (tab[milieu] > x){
            return binarySearch(tab, debut, milieu -1, x); // recursivite avec le même debut et un milieu different ( la fin de la prochaine fonctione est le milieu actuelle -1)
        }

        /* ( +1 ou -1 pour ne pas recomparer l'element actuelle qui n'est donc pas l'element rechercher ) */

        /* Si l'element est plus grand que la  valeur au milieu, il sera dans la parti droite du tableau */
        return binarySearch(tab, milieu +1, fin, x); //recursivité avec la même fin et un debut different  ( le debut de la prochaine fonction est le milieu actuelle +1)
   } 
  
   // We reach here when element is not present in array 
   return -1; 
} 
  
int main(void) 
{ 
   int tab[] = {2, 3, 4, 10, 40}; 
   int n = sizeof(tab)/ sizeof(tab[0]); 
   int x = 10; 
   int result = binarySearch(tab, 0, n-1, x); 
   (result == -1)? printf("L'element n'est pas present dans le tableau") 
                 : printf("L'element est  present a l'indice %d", result); 
   return 0; 
} 