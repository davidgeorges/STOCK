#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 4444

int main(){

	int sockfd;
	int ret;
	struct sockaddr_in serverAddr;/*structure qui représente la socket du client en (IPv4)*/

	int newSocket;
	struct sockaddr_in clientAddr;/*structure qui représente le client*/

	socklen_t addr_size;

	char buffer[1024] = " ";
	char pseudo[20];

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

	if(listen(sockfd, 10) == 0){/* accept max 10 client en attendent de connection*/
		printf("[+]Listening....\n");
	}else{
		printf("[-]Error in binding.\n");
	}


	while(1){
		/* on accepte la connexion du client */
		newSocket = accept(sockfd, (struct sockaddr*)&clientAddr, &addr_size);
		recv(newSocket, pseudo, 1024, 0);/* oh recoir le pseudo envoyer par le client*/
		if(newSocket < 0){
			exit(1);
			printf("[-]Error\n");
		}
		/*conversion de l'adresse en chaine de caractere (inet_ntoa) et du port en entier (ntohs)*/
		printf("Connection accepted from %s:%d\n", inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port));

			while(1){
				/*on recoit un message du client stocker dans 'buffer' de max 1024 caractere*/
				recv(newSocket, buffer, 1024, 0);
				if(strcmp(buffer, "!exit") == 0){
					/*conversion de l'adresse en chaine de caractere (inet_ntoa) et du port en entier (ntohs)*/
					printf("Client %s has been ",pseudo);
					printf("disconnected from %s:%d\n", inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port));
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

	}

	close(newSocket);
	close(sockfd);


	return 0;
}