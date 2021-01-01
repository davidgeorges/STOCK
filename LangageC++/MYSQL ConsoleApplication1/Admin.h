#ifndef Admin__
#define Admin__
#include <iostream>
#include <mysql.h>
using namespace std;

/*Class Admin*/

class Admin		
{
public:
	Admin();
	~Admin();
	void showDataBase();// affichage de toute la base de donnee
	//void registerClient();
	void deleteClient();// supprimer un client par id
	//void getInfo();// afficher les info du client
	//string hideId();// masquer l'id une lettre sur deux
	//int idAvailable(string);// check si le pseudo est disponible
	void showNumberClient();//affichage nombre de client dans la base de donnee

private:
	MYSQL* mysql = mysql_init(0);//bdd
	MYSQL_ROW row;
	MYSQL_RES* res;
	int qstate;
	int compteur_id;
};

#endif // Admin__

