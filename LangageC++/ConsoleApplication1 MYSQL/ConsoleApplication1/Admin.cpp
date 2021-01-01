#include "Admin.h"

/*Class Admin*/

Admin::Admin()
{
	qstate = 0;
	compteur_id = 0;
	mysql = mysql_real_connect(mysql, "localhost", "root", "010719663a", "testdb3", 3306, NULL, 0);
	if (mysql)
	{
		cout << "Successful connection to database! " << endl;
		cout << "Version 1.4 " << endl;
	}
	else
	{
		cout << "Connection to database has failed! " << endl;
	}
}

Admin::~Admin()
{
	mysql_free_result(res);
	mysql = 0;
}

void Admin::showDataBase()
{
	compteur_id = 0;
	const char* read_query = "SELECT * FROM test2";//tableau de caractere ,( donc chaine de caractere )
		//qstate = mysql_query(conn, read_query);//connection a la table avec le 'SELECT * FROM test'
	if ((qstate = mysql_query(mysql, read_query)) == 0)// connection a la table avec le 'SELECT * FROM test',si 0 = on a acceder a  la table,si 1 == on n'est pas connecter a la table , 
	{
		res = mysql_store_result(mysql);// on lit et stock le resultat en entier dans 'res'
		while (row = mysql_fetch_row(res))// tant qu'ont a quelque chose a lire de la ligne ( tant que ça vaut pas null)
		{
			compteur_id++;
			cout << "ID: " << row[0] << "\tName: " << row[1] << "\tScore: " << row[2] << endl;//accessible comme un tableau car on a utiliser mysql_fetch_row()
			//row[0] = id; row[1] = name, row[2] = score , row[3] = mot de passe

		}
	}
	else
	{
		cout << "Query failed: \n" << mysql_error(mysql) << endl;
	}

}

/*
void Admin::registerClient()
{
	string namee = "";
	string scoree;
	string id = " ";

	cout << "Veuillez entrer votre Identifiant unique :" << endl;
	cin >> id;
	cout << "Veuillez entrer votre prenom :" << endl;
	cin >> namee;
	cout << "Veuillez entrer votre score :" << endl;
	cin >> scoree;

	if (idAvailable(id))
	{
		string  insert_query = "INSERT INTO test2 (id,name,score) VALUES ('" + id + "', '" + namee + "', '" + scoree + "')";//tableau de caractere ,( donc chaine de caractere )
		qstate = mysql_query(mysql, insert_query.c_str());
		if (!qstate)//si qstate ==0
		{
			cout << "Inscription avec success !" << endl;
			compteur_id++;
			return;
		}
		else
		{
			cout << "Query failed: " << mysql_error(mysql) << endl;
		}
	}

	compteur_id--;
	return;
	cout << "\n";
}*/

void Admin::deleteClient()
{

	string  id;
	cout << "Nous allon afficher la base de donnee ! " << endl;
	this->showDataBase();
	cout << "Veuillez supprimer par id :" << endl;
	cin >> id;
	string  delete_query = "DELETE FROM test2 WHERE id='" + id + "' LIMIT 1";//on supprime par id dans la table mysql
	qstate = mysql_query(mysql, delete_query.c_str());

	if (qstate == 0)// on a supprimer avec success
	{
		cout << endl << "Supression avec success ! " << endl;
		compteur_id--;
		cout << "Affichage apres suppression !" << endl;
		this->showDataBase();
	}
	else
	{
		cout << "Query failed: " << mysql_error(mysql) << endl;//erreur table mysql
	}

	cout << "\n";
}

void Admin::showNumberClient()
{
	cout << "Il y a actuellement : " << compteur_id << " client." << endl;
}

/*
void Admin::getInfo()
{
	
		if (!idAvailable(id))//si l'id du client est present dans la Base de donnee
		{
			string hidedId = hideId();// masquer l'id une lettre sur deux
			cout << "1 Vous etes connecter en tant que: " << namee << "\t" << "Score: " << scoree << "\t" << "Id: " << hidedId << endl;
			cout << "\n";
		}
		else
		{
			cout << "Error ID non reconnu !\n";
			cout << "\n";
		}

}*/

/*
int Admin::idAvailable(string testId)
{
	const char* read_query = "SELECT * FROM test2";//on selectionne tout dans la table mysql
	if ((qstate = mysql_query(mysql, read_query)) == 0)// connection a la table avec le 'SELECT * FROM test',si 0 = on a acceder a  la table,si 1 == on n'est pas connecter a la table 
	{
		res = mysql_store_result(mysql);// on lit et stock le resultat en entier dans 'res'
		while ((row = mysql_fetch_row(res)))// tant qu'ont a quelque chose a lire de la ligne ( tant que ça vaut pas null)
		{
			if (testId.compare(row[0]) == 0)
			{
				return 0;// id non disponible
			}
			//cout << "Compteur : " << compteur_id;
		}
	}
	else
	{
		cout << "Query failed: \n" << mysql_error(mysql) << endl;
		return 0;
	}

	return 1;//donc disponible

}*/