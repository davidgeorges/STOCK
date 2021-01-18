#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include "socketQueue.h"

#define PORT 4444
/*éviter le coût lié à la création d’un nouveau thread pour chaque tâche*/
#define THREAD_POOL_TAILLE 5

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;


void *handleConnection(void *arg);

void *threadFonction(void *arg);

int main(){

	/*Declaration variable*/
	int sockfd;
	int ret;
	pthread_t thread_pool[THREAD_POOL_TAILLE];
	struct sockaddr_in serverAddr;/*structure qui représente la socket du client en (IPv4)*/
	int newSocket;
	struct sockaddr_in clientAddr;/*structure qui représente le client*/
	socklen_t addr_size;

	char buffer[1024] = " ";
	char pseudo[20];

	/*Creation de thread*/
	for (int i = 0; i < THREAD_POOL_TAILLE; i++)
	{
		pthread_create(&thread_pool[i],NULL,threadFonction,NULL);
	}

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0){
		printf("[-]Error in connection.\n");
		exit(1);
	}
	printf("[+]Server Socket is created.\n");


	/*on initialiser la structure a '\0' */
	memset(&serverAddr, '\0', sizeof(serverAddr));
	/*Initialise family , le port, et l'adresse IP*/
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(PORT);
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	/*sockcd = socket a ecouter*/
	/*bind demande une sockaddr * et non un sockaddr_in , on met donc un  cast (struct sockaddr*) devant notre sockaddr_in)*/
	/* on bind sockfd(client) avec la socket du server */
	ret = bind(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
	if(ret < 0){
		printf("[-]Error in binding.\n");
		exit(1);
	}
	printf("[+]Bind to port %d\n", 4444);

	/* accept max 10 client en attendent de connection*/
	if(listen(sockfd, 10) == 0){
		printf("[+]Listening....\n");
	}else{
		printf("[-]Error in binding.\n");
	}

	/*Boucle infini*/
	while(1){

		/* on accepte la connexion du client */
		newSocket = accept(sockfd, (struct sockaddr*)&clientAddr, &addr_size);
		if(newSocket < 0){
			exit(1);
			printf("[-]Error\n");
		}
		/*conversion de l'adresse en chaine de caractere (inet_ntoa) et du port en entier (ntohs)*/
		printf("Connection accepted from %s:%d\n", inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port));

		int *pclient = malloc(sizeof(int));
		*pclient = newSocket;
		pthread_mutex_lock(&mutex);
		/*on envoie le socket client dans la queue*/
		enqueue(pclient);
		/* on envoie au signal attendant qu'ont a une nouvelle socket a traiter*/
		pthread_cond_signal(&cond);
		pthread_mutex_unlock(&mutex);
		//pthread_create(&t[i],NULL,threadFonction,pclient);

		
	}

	close(newSocket);
	close(sockfd);


	return 0;
}

/*fonction de regroupant les commande disponible pour un utilisateur connecter*/
void *handleConnection(void *arg){

	int newSocket = *(int*) arg;
	free(arg);
	
	char buffer[1024] = " ";
	char pseudo[20];
	recv(newSocket, pseudo, 1024, 0);/* oh recoir le pseudo envoyer par le client*/
	while(1){
		/*on recoit un message du client stocker dans 'buffer' de max 1024 caractere*/
		recv(newSocket, buffer, 1024, 0);
		if(strcmp(buffer, "!exit") == 0){
			/*conversion de l'adresse en chaine de caractere (inet_ntoa) et du port en entier (ntohs)*/
			printf("Client %s has been disconnected.\n",pseudo);
			//printf("disconnected from %s:%d\n", inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port));
			break;
		}

		if (strcmp(buffer,"!opengate") == 0){
			printf("Client %s : has send the command to open the gate \n",pseudo);
			send(newSocket, buffer, strlen(buffer), 0);
			bzero(buffer, sizeof(buffer));
		}else{
			printf("Client %s : %s\n",pseudo,buffer);
			send(newSocket, buffer, strlen(buffer), 0);
			bzero(buffer, sizeof(buffer));
		}
		
	}
		
	return NULL;
}


/*fonction pour thread*/
void *threadFonction(void *arg){

	/*Boucle infini*/
	while (1)
	{
		/*on lock le mutex*/
		pthread_mutex_lock(&mutex);
		/*on attent un signal pour effectuer l'action suivante*/
		pthread_cond_wait(&cond,&mutex);
		/*on enleve un personne de la queue(on a eu un nouveau client si on est ici*/
		int *pclient= dequeue();
		/*on unlock le mutex*/
		pthread_mutex_unlock(&mutex);
		/*si non null c'est qu'il y a quelqu'un donc on appel la fonction */
		if (pclient !=NULL)
		{
			handleConnection(pclient);
		}
		
	}
	

}