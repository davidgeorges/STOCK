#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
#define PI 3.14159


/*------------------------------------------- Georges David , 06/01/2021 -------------------------------------------*/

/*----------------------------------------------!!!!! A FINIR !!!!!-------------------------------------------------*/

/* Programe qui demande deux nombre complexe sous forme polaire ou cartesienne pour en faire un calcul              */ 

/* Utilisation de structure */

/*---------------------------------------- Definition forme et aide calcul  ----------------------------------------*/

/* Forme cartèsienne z = x + y i , Forme polaire z = p(cos θ + i sin θ) */
/* Quand on a la forme polaire on peut facilement passer a la forme cartésienne x = p cos θ
p = row , θ = angle theta                                                       y = p sin θ 
---------------------------------------------------------------------------------------------------------------------
Pour passer de la forme cartèsienne a la forme polaire p =  √x²+y² 
y = x tg θ                                             θ = arctg(y/x) */

/*------------------------------------------------------------------------------------------------------------------*/

/* Structure */
typedef struct Complexe
{
    /* re = partie reel , im = partie imaginaire */
    double re;
    double im;

}Complexe;

/* struct Complexe nb1, struct Complexe nb2,int val */

/* Prototypes fonction */
void saisie(Complexe a);/* Saisie d'un nombre complexe */
int choixSaisie(int);/* Saisie nombre carte ou polaire */
void choixOperateur(Complexe,Complexe,int);/* Choix operateur et appel fonction selon saisie */
void additionCartesienne(Complexe ,Complexe,int);/* Addition a partir de la forme cartesienne */
void soustractionCartesienne(Complexe,Complexe,int);/* Soustracion a partir de la forme cartesienne */
void multiplierPolaire(Complexe,Complexe,int);/* Multiplier a partir de la forme polaire */
void divisionPolaire(Complexe,Complexe,int);/* Division a partir de la  forme cartesienne */
void conversionToPolaire(double *,double *);/* Conversion de forme cartesienne en forme polaire */
void conversionToCartesienne(double *,double *);/* Conversion de forme polaire en forme cartesienne */
void checkValeurAfficher(double,double,double);/* Affichage le resultat selon les valeurs , en cours de programmation...*/



int main(int argc, char const *argv[]){

    /*Declarations de plusieurs variables et initialiastion d'une seul*/
    double x1;
    double y1;
    double x2,y2;
    struct Complexe nb1,nb2;
    char poub =' ';
    int val = 0;
    char choix = ' ';
    int continuer = 1;

    /*Boucle pour refaire des operations arithemetique avec deux nombre compelexe sauf si on decide de quitter*/
    while (continuer)
    {
        choixSaisie(&val);
        saisie(nb1);/*Appel  a la fonction saisie avec passage des variable par adresse,
        (car cette fonction déclarer avec des pointeurs en paramètre va directement changer la valeur de nos variable dans le programme principal ( par adresse ))*/
        saisie(nb2);
        /*Mise en place d'une poubelle pour effacer le retour a la ligne avant appel de notre fonction pour saisir un caractère */
        scanf("%c", &poub);
        //choixOperateur(x1, y1, x2, y2, val);

        scanf("%c", &poub);
        printf("Pour quitter le programme veuillez appuyez sur 1 : \n");
        scanf("%c", &choix);

        if (choix == '1')
        {
            continuer = 0;
            system("cls");
            printf("Vous venez de quitter le programme.\n");
        }
        else
        {
            system("cls");
            printf("Vous avez decider de continuer.\n");
        }
    }

    return 0;
}

/* Saisie d'un nombre complexe ( seule fonction avec pointeur pour garder les valeurs saisie dans la fonction principal) */
void saisie(Complexe nb1){

    printf("Veuillez saisir la partie reelle : \n");
    scanf("%lf",&nb1.re);
    printf("partie reelle [%.2lf] \n",nb1.re);
    printf("Veuillez saisir la partie imaginaire : \n");
    scanf("%lf",&nb1.im);
    printf("partie reelle [%.2lf] \n",nb1.im);
}

/* Saisie nombre carte ou polaire */
int choixSaisie(int val){
    val = 0;
    char choix = ' ';
    char poub =' ';
    printf("Veuillez entrer en quel forme allez vous entrez votre nombre complexe , P pour polaire ou C pour cartesienne !\n");
    scanf("%c%c",&choix,&poub);
    if (choix == 'C')
    {
        val = 1;/* 1 = forme cartesienne */
    }
    
    return val;
}

/* Choix operateur et appel fonction selon saisie x=reel , y=imaginaire*/
void choixOperateur(Complexe nb1,Complexe nb2,int val){

    char choix =' ';
    printf("Veuillez entrer votre operation arithmetique entre '+' , '-' , '*' , '/' \n");
    scanf("%c",&choix);
    switch (choix)/* Appel de la fonction adequate a la situation selon la saisie de l'utilisateur */
    {
    case '+':
        additionCartesienne(nb1,nb2,val);
        break;
    
    case '-':
        soustractionCartesienne(nb1,nb2,val);
        break;

    case '*':
        multiplierPolaire(nb1,nb2,val);
        break;

    case '/':
        divisionPolaire(nb1,nb2,val);
        break;
    
    default:
        printf("Desoler vous avez entrer aucune operation arithmetique ! \n");
        break;
    }
}

/* Addition forme cartesienne x=reel , y=imaginaire*/
void additionCartesienne(Complexe nb1,Complexe nb2,int val){
    
    if (val==0)/* on a recu le nombre en forme polaire*/
    {
        printf("\nAddition avec forme polaire, conversion de vos saisie en forme cartesienne, la forme initialse sera conserver...\n");
        conversionToCartesienne(&x1,&y1);
        conversionToCartesienne(&x2,&y2);
    }
    
    /*Affichage de test
    printf("test x1 [%.2lf] ",x1);
    printf("test y1 [%.2lf] ",y1);
    printf("test x2 [%.2lf] ",x2);
    printf("test y2 [%.2lf] ",y2);
    */

    double resReel = x1+x2; /*Calcul partie reel */
    double resIm = y1+y2; /*Calcul partie imaginaire*/

    if (resIm <0)
    {
        printf("\n Resultat : [%.1lf %.1lf * i]  \n\n",resReel,resIm);
        printf("\n");
    }else
    {
        printf("\n Resultat  : [%.1lf + %.1lf * i]  \n\n",resReel,resIm);
        printf("\n");
    }
    
}

/* Soustracion forme cartesienne x=reel , y=imaginaire*/
void soustractionCartesienne(Complexe nb1,Complexe nb2,int val){

    if (val==0)/* on a recu le nombre en forme polaire*/
    {
        printf("\nAddition avec forme polaire, conversion de vos saisie en forme cartesienne, la forme initialse sera conserver...\n");
        conversionToCartesienne(&x1,&y1);
        conversionToCartesienne(&x2,&y2);
    }

    double resReel = x1 -x2;/*Calcul partie reel */
    double resIm = y1 - y2;/*Calcul partie imaginaire */

    /* Affichage selon résulat de resIm (partie imaginaire) */
    if (resIm <0)
    {
        printf("\nResultat : [%.1lf %.1lf * i]  \n\n",resReel,resIm);
    }else
    {
        printf("\nResultat : [%.1lf + %.1lf *i]  \n\n",resReel,resIm);
    }

 }

/* Multiplier forme polaire x=reel , y=imaginaire*/
void multiplierPolaire(Complexe nb1,Complexe nb2,int val){

    if (val==1)/* on a recu le nombre en forme cartesienne*/
    {
        printf("\nAddition avec forme cartesienne, conversion de vos saisie en forme polaire, la forme initialse sera conserver...\n");
        conversionToPolaire(&x1,&y1);
        conversionToPolaire(&x2,&y2);
    }
    

    double reel1 = (x1 * x2 -y1 * y2); /* calcul de (a1⋅a2-b1⋅b2) */
    double im1 = (x1 * y2 + y1 * x2);/* calcul de (a1⋅b2−b1⋅a2) */
    
    printf("\n Resultat : [%.1lf + %.1lf * i]  \n\n",reel1,im1);
}

/* Division forme polaire  x=reel , y=imaginaire*/
void divisionPolaire(Complexe nb1,Complexe nb2,int val){

    int i=1;
    if (val==1)/* on a recu le nombre en forme cartesienne*/
    {
        printf("\nAddition avec forme cartesienne, conversion de vos saisie en forme polaire, la forme initialse sera conserver...\n");
        conversionToPolaire(&x1,&y1);
        conversionToPolaire(&x2,&y2);
    }

    /* Utilisation de l'identité   (a1⋅a2+b1⋅b2)+(b1⋅a2−a1⋅b2)⋅i
                                --------------------------------
                                            (a2²−b2²)   
     a1 = x1 , a2 = x2 , b1 = y1 , b2 = y2 */

    double nume1 = (x1 * x2 +y1 * y2); /* calcul de (a1⋅a2+b1⋅b2) (numerateur 1)*/
    double nume2 = (y1 * x2 - x1 * y2);/* calcul de (b1⋅a2−a1⋅b2) (numerateur 2)*/
    double deno= (x2 * x2 + y2 * y2);/* calcul de (a2²−b2²)  (denominateur) */

    checkValueToPrint(nume1,deno,nume2);
}


/* Conversion de forme cartesienne en forme polaire x=reel , y=imaginaire*/
void conversionToPolaire(double *x1,double  *y1){
    

    double x1Row = sqrt(*x1 * *x1 + *y1 * *y1);/*calcul de row ( x ) */
    double x1ThetaRads = atan(*y1 / *x1); /*calcul en radian*/ 
    double x1ThetaDegs = x1ThetaRads*180/PI; /* convertir radian en degres ( y ) */
    //printf("Conversion de [%.1lf] , [%.1lf] en forme POLAIRE.\n",*x1,*y1);
    //printf("Pole X vaut Row = [%.1lf].\n",x1Row);
    //printf("Pole Y vaut Rad/s = [%.1lf].\n",x1ThetaRads);
    //printf("Pole Y vaut Degre = [%.1lf].\n",x1ThetaDegs);

}

/* Conversion de forme polaire en forme cartesienne x=reel , y=imaginaire*/
void conversionToCartesienne(double *x1,double *y1){

    printf("\nConversion de [%.1lf] , [%.1lf] en forme CARTESIENNE.\n",*x1,*y1);

    double y1Bis = *y1;
    y1Bis = y1Bis *PI/180;/* convertir degres en radians */
    *y1 = *x1 * sin(y1Bis) ; /* calcul de y en carte */
    *x1 = *x1 * cos(y1Bis) ; /* calcul de x en carte */

    //printf("Carte X vaut = [%.1lf]. \n",*x1);
    //printf("Carte Y vaut = [%.1lf].\n",*y1);
  

}

void checkValeurAfficher(double value1,double value2,double value3){

     if ((value1 == value2) && (value3 ==0 ))
    {
        printf("\nResultat sous forme carte : [1 + 0 * i]\n\n");
    }else
    {
        if (value3==0 ){
            printf("\nResultat sous forme carte : [%.1lf / %.1lf + 0 * i] \n\n",value1,value2);
        }else
        {
            printf("\nResultat sous forme carte : [%.1lf / %.1lf + ",value1,value2);
            printf("%.1lf / %.1lf * i]  \n\n",value3,value2);
        }
        
    }

    /*
    if ((value1 == value2) && (value3 ==0 ))
    {
        printf("Resultat sous forme carte : [1 + 0 * i]");
    }else
    {
        if (value1 <0 && value2>0)
        {
            printf("Resultat :  [%.1lf * %.1lf * i]  \n",value1,value2);
        }else
        {
            if (value1 ==0 && value2 ==0)
            {
                printf("Resultat : [0 * i] \n");
            }else
            {
                if (value1<0)
                {
                    printf("Resultat : [%.1lf  %.1lf *i]  \n",value1,value2);
                }else
                {
                    if (value2<0)
                    {
                        printf("Resultat : [%.1lf %.1lf *i]  \n",value1,value2);
                    }else
                    {
                        printf("Resultat : [%.1lf + %.1lf *i]  \n",value1,value2);
                    }
                    
                }
            } 
            
        }
        
    }*/
          
}
