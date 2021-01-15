#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define PORT 4444

/*Fonction pour vider le buffer*/
void viderBuffer();
/*Fonction pour lire une chaine de caractere, et enlever le retour a la ligne(entrer) et le remplacer par le caractere de fin de chaine*/
int lire(char *chaine, int longueur);

int main(){

	int clientSocket;
	int ret;
	struct sockaddr_in serverAddr;
	char buffer[1024];
	char pseudo[20];

	clientSocket = socket(AF_INET, SOCK_STREAM, 0);
	if(clientSocket < 0){
		printf("[-]Error in connection.\n");
		exit(1);
	}
	printf("[+]Client Socket is created.\n");

	/*on init les adresse,port du serveru pour se connecter*/
	memset(&serverAddr, '\0', sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(PORT);
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	/*on se connecte a au serveur*/
	ret = connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
	if(ret < 0){
		printf("[-]Error in connection.\n");
		exit(1);
	}

	printf("Veuillez ecrire votre pseudo : \n");
	lire(pseudo,20);

	printf("Bienvenue %s \n!",pseudo);
	/*on envoie au serveur notre message(pseudo)*/
	send(clientSocket, pseudo, strlen(pseudo), 0);

	printf("[+]Connected to Server.\n");

	while(1){
		printf("You: ");
		lire(buffer,1024);
		send(clientSocket, buffer, strlen(buffer), 0);

		if(strcmp(buffer, "!exit") == 0){
			close(clientSocket);
			printf("[-]Disconnected from server.\n");
			exit(1);
		}

		if(strcmp(buffer, "!opengate") == 0){
			printf("You send the command to open gate\n");
		}

		if(recv(clientSocket, buffer, 1024, 0) < 0){
			printf("[-]Error in receiving data.\n");
		}/*else{
			printf("Server: \t%s\n", buffer);
		}*/
	}

	return 0;
}



/*-------------------------------------------------------------------------------------- Fonction viderBuffer et Lire--------------------------------------------------------------------------------------*/
void viderBuffer()
{
    int c = 0;
    /*tant qu'ont a pas trouver le retour a la ligne et qu'ont est pas a la fin de 'fichier' ->(fin du buffer)*/
    while (c != '\n' && c != EOF)
    {
        c = getchar();//on récupere le caractere en ecrasent le precedent*/
    }
}
 
int lire(char *chaine, int longueur)
{
    char *positionEntree = NULL;/*pointeur de type char*/
 
    /*si il n'est pas egale a NULL on n'a pas d'erreur donc on continue*/
    if (fgets(chaine, longueur, stdin) != NULL)
    {
        /*on recherche la caractere '\n' dans la chaine passe en parametre*/
        positionEntree = strchr(chaine, '\n');
        /*si on la trouver*/
        if (positionEntree != NULL)
        {
            *positionEntree = '\0';/* on le remplace par le caractere de fin de chaine*/
        }
        else/*si on la pas trouver on vide le buffer*/
        {
            viderBuffer();
        }
        /* on sort de la fonction*/
        return 1;
    }
    else/*si on a un probleme avec fgets on vide le buffer*/
    {
        viderBuffer();
        return 0;
    }
}