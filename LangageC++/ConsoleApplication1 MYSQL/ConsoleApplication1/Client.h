#include <iostream>
#include <mysql.h>

using namespace std;

/*Class client*/

class Client
{
public:
	Client();
	~Client();
	void registerClient();// client s'enregistre , fonction la plus grande
	int idAvailable(string);// si l'id du client est disponible dans la base de donnee
	void askDeleteAccount();// demande pour supprimer son compte;
	void getInfo();// afficher les info du client
	string hideId();// masquer l'id une lettre sur deux
	void menuClient();//affichage du menu en boucle tant qu'ont a pas quitter
	void loginClient();
	void decoClient();
	void changePassword();


private:
	MYSQL* mysql = mysql_init(0);//bdd
	MYSQL_ROW row;
	MYSQL_RES* res;
	int qstate;
	string namee;
	string scoree;
	string id;
	string mdp;
	char choix;
	int inscription;
	bool continuer;
	bool connected;
};
