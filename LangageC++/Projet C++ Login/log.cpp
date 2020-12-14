#include "log.h"
#include "crypt.h"

void coin(char chaine1[N],string &chaine2){

    int taille;
    string rep; //reponse
    string co = "CO";
    string log = "IN";
    string conf;// pour confirmation mdp
    string buffer;
    //affichage et saisie plus mettre en maj la saisie
    cout << "* Appuyez sur CO pour vous connecter : \n" << endl;
    cout << "* Appuyez sur IN pour vous connecter : \n" << endl;
    cin >> rep;
    for (int i=0; i<rep.length(); i++){
        rep [i] = toupper(rep[i]);
    }


    // si on a choisis connexion
    if (rep.size() <=2 )
    {
        /* code */
    
        if( rep.compare(co) == 0 ){
            //affichage saisie , nom et mot de passe
            cout << "Vous allez vous connecter ! "<< endl;
            cout << "Veuillez ecrire votre nom d'utilisateur : " << endl;
            cin >> chaine1;
            cout << "Veuillez ecrire votre mot de passe : " << endl;
            cin >> chaine2;

            // ouveture fichier en mode lecture pour savoir si dossier vide ou pas
            ifstream monFluxR(chaine1);

            // si flux ouvert donc le fichier existe deja donc utilisateur connu
            if (monFluxR)
            {
                //cout << "Taille du fichier : " << taille << " octets." << endl;
                    getline(monFluxR, buffer);
                    decrypt(buffer);
                    if (chaine2.compare(buffer) == 0)
                    {
                        cout << "Connexion avec succes " << chaine1 << endl;
                        monFluxR.close();
                    }
                    else
                    {
                        cout << "Pseudo ou mot de passe inconnu " << endl;
                        monFluxR.close();
                    }
                
                
                
            }
            else
            {
                cout << "Nom d'utilisateur ou mot de passe inconnu " << endl;
                monFluxR.close();
            }
            

        }
        else
        {
            if (rep.compare(log) == 0 ){
                //Affichage et saisie
                cout << "Vous allez vous inscrire ! "<< endl;
                cout << "Veuillez ecrire votre nom d'utilisateur : " << endl;
                cin >> chaine1;

                // ouverture lecture
                ifstream monFluxR(chaine1);
                if (monFluxR) // si aucune erreur , donc deja crée comme ifstream ne crée pas de fichier =  utilisateur deja pris
                {
                    cout << "Nom d'utilisateur deja pris ! ";
                    monFluxR.close();
                    EXIT_SUCCESS;
                }
                else
                {
                    // on ouvre on mode écriture et crée le fichier
                    ofstream monFluxW(chaine1,ios::out);
                    // Affichage et saisie nom et mdp
                    cout << "pas cree ";
                    cout << "Veuillez entrer votre mot de passe : " << endl;
                    cin >> chaine2;
                    cout << "Veuillez confirmer votre mot de passe : " << endl;
                    cin >> conf;
                    if ((chaine2.size() <=12 ) && chaine2.compare(conf) == 0) // si mot de passe pas supérieur a 12 carac on continue et si les mot de passe sont les mêmes
                    {
                        // si les mot de passe sont les mêmes

                            crypt(conf);;
                            monFluxW << conf;
                            cout << "Inscription avec succes bienvenue ! "<< chaine1 << endl;
                            monFluxR.close();
                    }
                    else
                    {
                        cout << "Desoler mot de passe trop grand ! ou les mot de passe ne sont pas les memes !  " << endl;
                        monFluxW.close();
                        remove(chaine1);
                        EXIT_SUCCESS;
                    }
    
                    
                }
    
                
            }
            else
            {
                cout << "Desole mauvais choix ! \n" << endl;
            }
            
        }
    }
    else
    {
        cout << "Reponse trop grande " << endl;
    }
           
        
}


