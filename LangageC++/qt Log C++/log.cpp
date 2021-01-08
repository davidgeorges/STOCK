#include "log.h"
#include "crypt.h"

/*  Fonction login , ouvre le dossier avec le nom d'utilisateur si le fichier ne s'ouvre pas il n'existe pas d'utilisateur avec ce nom
 * si il existe on lit première ligne qu'on sotck dans une chaine on compare le mot de passe et le chaine recu si c'est la même l'utilisateur est connecter
 * sinon pas connecter et fermetire */
void log(string &chaine1,string &chaine2){

    // Declaration variable
    string conf;// pour confirmation mdp
    string buffer;
    QMessageBox failure;
    QMessageBox success;

    // si on a choisis connexion
        /* code */

            // ouveture fichier en mode lecture pour savoir si dossier vide ou pas
            ifstream monFluxR(chaine1);

            // si flux ouvert donc utilisateur bon
            if (monFluxR)
            {
                //cout << "Taille du fichier : " << taille << " octets." << endl;
                    getline(monFluxR, buffer);
                    decrypt(buffer);
                    if (chaine2.compare(buffer) == 0)
                    {
                        cout << "Connexion avec succes " << chaine1 << endl;
                        success.setText("Connexion avec succes ");
                        success.exec();
                        monFluxR.close();
                    }
                    else
                    {
                        cout << "Pseudo ou mot de passe inconnu " << endl;
                        failure.setText("Pseudo ou mot de passe inconnu");
                        failure.exec();
                        monFluxR.close();
                    }

            }
            else
            {
                cout << "Nom d'utilisateur ou mot de passe inconnu " << endl;
                failure.setText("Nom d'utilisateur ou mot de passe inconnu");
                failure.exec();
                monFluxR.close();
            }





}

/*  Fonction inscription lit dossier avec le nom d'utilisateur ,  si on ouvre le dossier c'est que l'utilisateur existe deja donc on exit
 * si il ouvre pas le dossier l'utilisateur existe pas on demande le mot de passe et la confirmation si c'est bon on s'inscrit sinon exit */

void cre(string &chaine1,string &chaine2,string &conf)
{

    // Declaration variable
    char chaine[15];
    string buffer;
    int taille;
    QMessageBox failure;
    QMessageBox success;

        // ouverture lecture
        ifstream monFluxR(chaine1); // ça ne crée pas de fichier, tente de l'ouvrire avec chaine1
        if (monFluxR) // si aucune erreur , donc deja crée comme ifstream ne crée pas de fichier =  utilisateur deja pris
            {
                //afichage dans console
                cout << "Nom d'utilisateur deja pris ! ";
                //afichage une Qmessagebox
                failure.setText("Nom d'utilisateur deja pris ! ");
                failure.exec();
                monFluxR.close();
            }
            else
            {
                // on ouvre on mode écriture et crée le fichier
                ofstream monFluxW(chaine1,ios::out);
                if ((chaine2.size() <=12 ) && chaine2.compare(conf) == 0) // si mot de passe pas inferieur/egale a 12 carac on continue et si les mot de passe sont les mêmes
                {
                        // crypt mot de passe et ecriture dans fichier
                        crypt(conf);;
                        monFluxW << conf;
                        //afichage dans console
                        cout << "Inscription avec succes bienvenue ! "<< chaine1 << endl;
                        //afichage une Qmessagebox
                        success.setText("Inscription avec succes :");
                        success.exec();
                        monFluxR.close();
                        monFluxW.close();
                 }
                else
                {
                    //afichage dans console si...
                    cout << "Desoler mot de passe trop grand ! ou les mot de passe ne sont pas les memes !  " << endl;

                    //afichage une Qmessagebox
                    failure.setText("Mot de passe différent ou trop grands !");
                    failure.exec();
                    //fermeture fichier
                    monFluxW.close();
                    // On recupere la taille de la chaine1 de type string et on let me en char[] car remove prend des char[]
                    taille = chaine1.length();
                    for(int i =0; i<taille; i++)
                    {
                        chaine[i] = chaine1[i];
                    }
                    remove(chaine);
                    //EXIT_SUCCESS;
                }


            }
}

void FenGenerer::cree()
{
    // on recupere le texte dans un Qstring
    nom2 = this->nom1->text(); // Qstring
    mot2 = this->mot1->text();
    mot22 = this->mot11->text();

    // QString converti en string
    nom3 = nom2.toStdString();
    mot3 = mot2.toStdString();
    mot33 = mot22.toStdString();
    cre(nom3,mot3,mot33);
}


