#include <iostream>
using namespace std;

/* -------------------------------------- David Georges ------------------------------------- */

int main()
{
  double nombre(5.3);
  nombre += 4.2;       //nombre vaut maintenant 9.5
  nombre *= 2.;        //nombre vaut maintenant 19
  nombre -= 1.;        //nombre vaut maintenant 18
  nombre /= 3.;        //nombre vaut maintenant 6
  ++nombre;            //nombre vaut maintenant 7
  --nombre;            //nombre vaut maintenant 6

  /* Nous avons d'autre opérateurs arithmétique et des fonction présentes dans la blibliothéque cmath */
   return 0;
}