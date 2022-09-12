#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>

int main(){
    int sockfd,counter=0,portno=22000;
    int newsockfd;
    char snd[100],rec[100];
    struct sockaddr_in servaddr;
    bzero(&servaddr, sizeof(servaddr));
    sockfd=socket(AF_INET,SOCK_DGRAM,0);
    servaddr.sin_family=AF_INET;
    servaddr.sin_port=htons(portno);
    servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
    
    bind(sockfd,(struct sockaddr *) &servaddr, sizeof(servaddr));
    socklen_t addsize;
    addsize=sizeof(servaddr);
    listen(sockfd,5);
    
     newsockfd=accept(sockfd,(struct sockaddr *) NULL,NULL);
printf("Wait to recieve string\n");
    while(1){
        bzero(rec,100);
        bzero(snd,100);
        recvfrom(sockfd,rec,100,0, (struct  sockaddr *) &servaddr, &addsize);
        // recv(newsockfd,rec,100,0);
        printf("\nOriginal: %s",rec);
        int k = strlen(rec);
        printf("Reversed:");
        for(int i=k-1;i>-1;i--){
            snd[k-i-1]=rec[i];
            printf("%c",snd[k-i-1]);
        }
        sendto(sockfd,snd,100,0,(struct  sockaddr *) &servaddr, sizeof(servaddr));
        // send(newsockfd,snd,100,0);
        // printf(snd);

    }

    return 0;
}