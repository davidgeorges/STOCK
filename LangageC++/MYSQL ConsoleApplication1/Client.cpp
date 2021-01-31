#include "Client.h"

/*Class client*/

Client::Client()
{
	inscription = 0;
	continuer = true;
	connected = false;
	namee = " ";
	scoree = " ";
	id = " ";
	mdp= " ";
	mysql = mysql_real_connect(mysql, "localhost", "root", "010719663a", "testdb3", 3306, NULL, 0);
	if (mysql)
	{
		cout << "Client successful connection to database! " << endl;
		cout << "\n";
	}
	else
	{
		cout << "Client connection to database has failed! " << endl;
	}
}

Client::~Client()
{
	mysql_free_result(res);
	mysql = 0;
}

void Client::registerClient()
{
	string mdpC=" ";

	/*Si on est pas deja connecter*/
	if (connected == false)
	{
		if (inscription!=3)//on ne peut pas s'inscire 3 dois d'affiler
		{
			cout << "Veuillez entrer votre Identifiant unique :" << endl;
			cin >> id;
			cout << "\n";

			if (idAvailable(id))// si l'id est disponible
			{
				/*Si l'id n'est pas sup�rieur a la taille maximal*/
				if (id.length()<=12)
				{
					cout << "Vous aller proceder a l'inscription l'id est disponible." << endl;
					cout << "Veuillez entrer votre prenom :" << endl;
					cin >> namee;
					cout << "\n";
					/*Si le nom n'est pas sup�rieur a la taille maximal*/
					if (namee.length()<=14)
					{
						cout << "Veuillez entrer votre score :" << endl;
						cin >> scoree;
						cout << "\n";
						/*Si le score n'est pas sup�rieur a la taille maximal*/
						if ((scoree.length() <= 3))
						{
							cout << "Veuillez entrer votre mot de passe :" << endl;
							cin >> mdp;
							cout << "\n";
							cout << "Veuillez confirmer votre mot de passe :" << endl;
							cin >> mdpC;
							cout << "\n";
							/*Si l'est mot de passe corresponde*/
							if ((mdp.compare(mdpC) == 0))
							{
								/*Si le mot de passe n'est pas sup�rieur a la taille maximal*/
								if ((mdp.length() <= 20))
								{
									string  insert_query = "INSERT INTO test2 (id,name,score,mdp) VALUES ('" + id + "', '" + namee + "', '" + scoree + "', '" + mdp + "')";//on ins�re les valeur dans la table mysql
									qstate = mysql_query(mysql, insert_query.c_str());
									if (!qstate)//si qstate ==0
									{
										cout << "Inscription avec success !" << endl;
										inscription ++;
										return;
									}
									else
									{
										cout << "Query failed: " << mysql_error(mysql) << endl;// si erreur table mysql
									}
								}
								else
								{
									system("cls");
									cout << "\n";
									cout << "Mot de passe trop long (max 20 caractere) ! \n" << endl;
								}
							}
							else
							{
								system("cls");
								cout << "Mot de passe different ! \n" << endl;
							}
						}
						else
						{
							system("cls");
							cout << "Probleme de taille avec le score (max 999). \n" << endl;
						}
					}
					else
					{
						system("cls");
						cout << "Probleme de taille avec le nom ( max 14 caracteres). \n" << endl;
					}
				}
				else
				{
					system("cls");
					cout << "Desoler l'id est trop long (max 12 caractere). \n" << endl;
				}
			}
			else
			{
				system("cls");
				cout << "Desoler votre id n'est pas disponible . \n" << endl;
			}
		}else
		{
			system("cls");
			cout << "Vous vous etes deja inscrit. \n" << endl;// nous somme inscrit
		}
	}
	else
	{
		system("cls");
		cout << "Deconnectez vous pour vous inscrire. \n" << endl;
	}
	return;
	cout << "\n";
}

int Client::idAvailable(string testId)
{
	const char* read_query = "SELECT * FROM test2";//on selectionne tout dans la table mysql
	if ((qstate = mysql_query(mysql, read_query)) == 0)// connection a la table avec le 'SELECT * FROM test',si 0 = on a acceder a  la table,si 1 == on n'est pas connecter a la table 
	{
		res = mysql_store_result(mysql);// on lit et stock le resultat en entier dans 'res'
		while ((row = mysql_fetch_row(res)))// tant qu'ont a quelque chose a lire de la ligne ( tant que �a vaut pas null)
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

}

void Client::askDeleteAccount()
{
	cout << "En  cours de programmation..." << endl;
	cout << "\n";
}

void Client::getInfo()
{
	/*Si on est connecter*/
	if (connected)
	{
		if (!idAvailable(id))//si l'id du client est present dans la Base de donnee
		{
			string hidedId = hideId();// masquer l'id une lettre sur deux
			string read_query = "SELECT * FROM test2 WHERE id='" +id+ "' ";
			if ((qstate = mysql_query(mysql, read_query.c_str())) == 0)
			{
				res = mysql_store_result(mysql);
				row = mysql_fetch_row(res);
				/*Recuperation du nom et du score*/
				namee = row[1];
				scoree = row[2];
				/*Affichage */
				cout << "Vous etes connecter en tant que: " << namee << "\t" << "Score: " << scoree << "\t" << "Id: " << hidedId << endl;
				cout << "\n";
			}
			else
			{
				cout << "Query failed: \n" << mysql_error(mysql) << endl;
			}
		}
		else 
		{
			cout << "Error ID non reconnu !\n";
			cout << "\n";
		}
	}
	else
	{
		cout << "Pour avoir vos infos veuillez vous connecter !\n";
		cout << "\n";
	}
}

string Client::hideId()// masquer l'id une lettre sur deux
{
	string newId = id;
	int i = 0;
	int taille = id.size();
	/*Tant qu'ont pas fait toute la chaine de caractere , on cache une lettre sur deux l'id*/
	while (i != taille)
	{
		if (i%2==0)
		{
			newId[i] ='*';
		}
		i++;
	}

	return newId;
}

void Client::menuClient()
{
	while (continuer)
	{
		cout << "Appuyez sur 1 pour vous connecter : " << endl;
		cout << "Appuyez sur 2 pour vous enregistrer : " << endl;
		cout << "Appuyez sur 3 pour avoir vos infos : " << endl;
		cout << "Appuyez sur 4 pour demande la supression de votre compte : " << endl;
		cout << "Appuyez sur 5 pour quitter le programme : " << endl;
		cout << "Appuyez sur 6 pour vous deconnecter : " << endl;
		cout << "Appuyez sur 7 pour changer votre mot de passe : " << endl;
		cin >> choix;

		system("cls");
		/*Switch faire une fonction selon choix*/
		switch (choix)
		{
		case '1':
			loginClient();
			break;
		case '2':
			registerClient();
			break;
		case '3':
			getInfo();
			break;
		case '4':
			askDeleteAccount();
			break;
		case '5':
			cout << "Vous quittez le programme..." << endl;
			continuer = false;
			break;
		case '6':
			decoClient();
			break;
		case '7':
			changePassword();
			break;
		default:
			cout << "Veuillez appuyez sur une operation valide ! " << endl;
			break;
		}
	}
}

void Client::loginClient()
{
	if(connected == false)//si on est pas connecter
	{
		cout << "Veuillez entrer votre Identifiant unique :" << endl;
		cin >> id;
		/*On demande le mot de passe*/
		cout << "Veuillez entrer votre mot de passe :" << endl;
		cin >> mdp;
		if (idAvailable(id) ==0)// l'id existe
		{
			/*On selectionne le mdp dans la case correspondant a l'id*/
			string read_query = "SELECT mdp FROM test2 WHERE id='"+id+"' ";
			qstate = mysql_query(mysql, read_query.c_str());
			if ( qstate == 0 )// connexion a la table avec success
			{
				/*---------*/
				res = mysql_store_result(mysql);
				row = mysql_fetch_row(res);
				/*m�me mot de passe dans la base de donner correspondant a l'id donner*/
				if (mdp.compare(row[0]) == 0)
				{
					cout << "Connexion avec success ! " << endl;
					connected = true;//on est connecter
				}
				else
				{
					cout << "Mauvaise identifiant ou mot de passe !" << endl;
				}

			}
			else
			{
				cout << "Query failed: " << mysql_error(mysql) << endl;// si erreur table mysql
			}
		}
		else
		{
			cout << "Mauvaise identifiant ou mot de passe !" << endl;
		}
	}
	else
	{
		cout << "Vous etes deja connecter." << endl;
	}

	cout << "\n";
}

void Client::decoClient()
{
	/*Si on est pas connecter , on peut se deconnecter*/
	if (connected)
	{
		connected = false;
		namee = " ";
		scoree = " ";
		id = " ";
		mdp = " ";
		cout << "Vous vous etes deconnecter.\n" << endl;
	}
	else
	{
		/*Si on essaye de se deconnecter quand on est pas connecter*/
		cout << "Vous n'etes pas connecter.\n" << endl;
	}

	
}

void Client::changePassword()
{
	string mdp1= " ";/*mot de passe actuelle*/
	string mdp2 = " ";/*nouveau mot de passe*/
	string mdp3 = " ";/*confirmation nouveau mot de passe*/
	/*Si on est connecter*/
	if (connected)
	{
		cout << "Veuillez entrer votre mot de passe actuelle : \n" << endl;
		cin >> mdp1;
		cout << "Veuillez entrer votre nouveau mot de passe  : \n" << endl;
		cin >> mdp2;
		cout << "Veuillez confirmer votre nouveau mot de passe  : \n" << endl;
		cin >> mdp3;
		/*Mot de passe actuelle est confirmer*/
		if (mdp1.compare(mdp) ==0)
		{
			/*Si les mots de passe correspondent*/
			if (mdp2.compare(mdp3)==0)
			{
				/*Il faut verifier que le mot de passe ne depasse pas 20 caractere*/
				if (mdp2.length() <= 20)
				{
					if (mdp2.compare(mdp) == 1)/*Si il le mot ne passe changer n'est pas egale au mot de passe actuelle*/
					{
						/*ici tout est bon sauf l'update du mot de passe dans la base de donner */
						/*On va update le mot de passe dans la base de donnee */
						string  update_query = "update testdb3.test2 set mdp = '" + mdp2 + "' where id = '" + id + "' ";
						qstate = mysql_query(mysql, update_query.c_str());//on modifie dans la base de donnee
						if (!qstate)/*Si aucune erreur*/
						{
							cout << "Vous venez de modifier votre mot de passe, vous allez etre deconnecter.\n" << endl;
							decoClient();
							/*Mot de passe changer dans base de donnee*/
						}
						else
						{
							cout << "Query failed: " << mysql_error(mysql) << endl;// si erreur table mysql
						}
					}
					else
					{
						cout << "Ce mot de passe a deja ete define une fois sur ce compte \n" << endl;
					}
				}
				else
				{
					cout << "Mot de passe trop long (max 20 caracteres)\n" << endl;
				}
			}
			else
			{
				cout << "Les mots de passe ne correspondent pas.\n" << endl;
			}
		
		}
		else
		{
			cout << "Les mots de passe ne correspondent pas.\n" << endl;
		}
	}
	else
	{
		system("cls");
		cout << "Veuillez vous connecter avant !\n" << endl;
	}
}