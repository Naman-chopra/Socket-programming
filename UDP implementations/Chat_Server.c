#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

int main(){

    int sockfd,portno=22000;
    char recline[100],senline[100];


    struct sockaddr_in server;

    socklen_t addsize;
    addsize=sizeof(server);

    bzero(&server, sizeof(server));

    sockfd=socket(AF_INET,SOCK_DGRAM,0);
     server.sin_addr.s_addr=htonl(INADDR_ANY);
     server.sin_family=AF_INET;
     server.sin_port=htons(portno);

    bind(sockfd,(struct sockaddr *) &server, sizeof(server));
    printf("Wait for client to send message\n");
    while(1){
        bzero(recline,100);
        bzero(senline,100);
        // printf("---------wait for respone---------");
        recvfrom(sockfd,recline,100,0, (struct sockaddr *)&server, &addsize);
        printf("Client: %s",recline);

        printf("\nME:");
        fgets(senline,100,stdin);
        sendto(sockfd, senline,100,0, (struct sockaddr * )&server, sizeof(server));
    }


     return 0;
}