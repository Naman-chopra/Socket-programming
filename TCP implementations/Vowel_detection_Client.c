#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<netinet/in.h>

int main(){
    int sockfd,portno=22000;

    char rec[100],snd[100];
    struct sockaddr_in server;
    bzero(&server,sizeof(server));
    sockfd=socket(AF_INET,SOCK_STREAM,0);

    server.sin_family=AF_INET;
    server.sin_port=htons(portno);
    server.sin_addr.s_addr=INADDR_ANY;
    
    connect(sockfd, (struct sockaddr *) &server,sizeof(server));
    // printf("Enter the string:")
    while(1){
    bzero(snd,100);
    bzero(rec,100);

    printf("\nOriginal: ");
    fgets(snd,100,stdin);
    send(sockfd,snd,100,0);
    recv(sockfd,rec,100,0);
    printf("Server respone: %s",rec);
    }
    // close(newsockfd);
    close(sockfd);
    return 0;
}