#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>

int main(){
    int sockfd,counter=0,portno=22000;
    char snd[100],rec[100],rev[100];
    struct sockaddr_in servaddr;
    bzero(&servaddr, sizeof(servaddr));
    sockfd=socket(AF_INET,SOCK_DGRAM,0);
    servaddr.sin_family=AF_INET;
    servaddr.sin_port=htons(portno);
    servaddr.sin_addr.s_addr=htonl(INADDR_ANY);

    bind(sockfd,(struct sockaddr *)&servaddr, sizeof(servaddr));
    socklen_t addsize;
    addsize=sizeof(servaddr);
    connect(sockfd,(struct sockaddr *) &servaddr, sizeof(servaddr));
printf("Send the string you want to reverse\n");
    while(1){
        bzero(rec,100);
        bzero(snd,100);
        printf("\nOriginal: ");
        fgets(snd,100,stdin);
        sendto(sockfd,snd,100,0,(struct  sockaddr *) &servaddr, sizeof(servaddr));
        // send(sockfd,snd,100,0);
        recvfrom(sockfd,rec,100,0, (struct  sockaddr *) &servaddr, &addsize);
        // recv(sockfd,rec,100,0);
        printf("Reversed: %s",rec);
    }

    return 0;
}