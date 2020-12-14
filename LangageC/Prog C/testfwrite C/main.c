#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int age;
    int agee;
    char nom[30];
    char prenom[30];
    }Personne;

int main()
{
    FILE *pt;
    int i=0;
    int j=0;
    int nombrePer=1;
    Personne *tab;
    Personne *tab2;
    char tab3[64];

    Personne per;



    if(nombrePer>0){

        tab = malloc( nombrePer*sizeof(per));
        tab2 = malloc( nombrePer*sizeof(per));
        //tab2 = malloc( nombrePer*sizeof(per));
        printf("%zu\n",sizeof(per));
        if (tab==NULL){

            exit(0);
        }

    pt = fopen("exemple1.txt","w");
    if (pt == NULL)
    {
        printf("Erreur lors de l'ouverture du dossier ! ");
        exit(0);
    }

        for (i = 0 ; i < nombrePer ; i++)
        {
            printf("Quel age a l'amis numero %d ? \n", i + 1);
            scanf("%d", &tab[i].age);
            //printf("l'ami numero %d a %d ans  ? \n",i+1,tab[i].age);
            fprintf(pt, "%d\n", tab[i].age);
            printf("Quel est le prenom de  l'amis numero %d ? \n", i + 1);
            scanf("%d", &tab[i].agee);
            fprintf(pt, "%d\n", tab[i].agee);
            fclose(pt);
            /*
            //printf("Prenom de l'ami numero %d est %s   ? \n",i+1,tab[i].prenom);
            printf("Quel est le nom de  l'amis numero %d ? \n", i + 1);
            scanf("%s", &tab[i].nom);
            fprintf(pt, "%s\n", tab[i].nom);
            //printf("Nom de l'ami numero %d est %s   ? \n",i+1,tab[i].nom);
            */
        }

    }
    else{
        printf("Erreur ovuert\n"); 
    }

    printf("coucou \n");
    pt = fopen("exemple1.txt","r");



    for (j = 0 ; j < nombrePer ; j++)
        {
            while (fgets(tab3,64,pt) != NULL) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
            {
                tab2[j].age = tab3;
                printf("la 2 %s\n",tab2[j].age); // On affiche la chaîne qu'on vient de lire
            }

             while (fgets(tab3,64,pt) != NULL) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
            {
                tab2[j].age = tab3;
                printf("la 2 %s\n",tab2[j].age); // On affiche la chaîne qu'on vient de lire
            }   
        }
    
 

            
    
    fclose(pt);


}
