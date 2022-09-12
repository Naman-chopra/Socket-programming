#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<netinet/in.h>

int main(){
    int sockfd,newsockfd,portno=22000;

    char rec[100],snd[100];
    struct sockaddr_in server;
    bzero(&server,sizeof(server));
    sockfd=socket(AF_INET,SOCK_STREAM,0);

    server.sin_family=AF_INET;
    server.sin_port=htons(portno);
    server.sin_addr.s_addr=INADDR_ANY;
    bind(sockfd,(struct sockaddr *) &server, sizeof(server));
    listen(sockfd,5);
    newsockfd=accept(sockfd, (struct sockaddr *) NULL,NULL);
    // printf("Enter the string:")
    while(1){
    bzero(snd,100);
    bzero(rec,100);
    printf("\nwait for client to send string...\n");
    recv(newsockfd,rec,100,0);
    printf("Original: %s",rec);
    // fgets(snd,100,stdin);
    int k= strlen(rec);
    int j=0;
    for (int i=0;i<k;i++){
        if(rec[i]=='A' || rec[i]=='E' || rec[i]=='I' || rec[i]=='U' || rec[i]=='O' || rec[i]=='a' || rec[i]=='e' || rec[i]=='o' || rec[i]=='u' || rec[i]=='i' ){
        snd[j]=rec[i];
        j++;
        }
    
    }
    printf("Vowels are: %s",snd);
    send(newsockfd,snd,100,0);
    }
    close(newsockfd);
    close(sockfd);
    return 0;
}