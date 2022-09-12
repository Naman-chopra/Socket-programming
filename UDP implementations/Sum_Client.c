#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
    int sock,connsock,portno=22000,counter=0;
    char rec[100],snd[100];

    struct sockaddr_in server;
    bzero(&server,sizeof(server));
    sock=socket(AF_INET,SOCK_DGRAM,0);
    server.sin_family=AF_INET;
    server.sin_addr.s_addr=htonl(INADDR_ANY);
    server.sin_port=htons(portno);
    socklen_t addsize;
    addsize=sizeof(server);
        printf("Send numbers\n");

    while(1){
        counter++;
        bzero(snd,100);
        bzero(rec,100);
        printf("number %d: ",counter);
        fgets(snd,100,stdin);
        sendto(sock,snd,100,0,(struct sockaddr *) &server, sizeof(server));
        if(counter==2){
            recvfrom(sock,rec,100,0,(struct sockaddr *) &server,&addsize);
            printf("Sum Recieved: %s\n",rec);
            counter=0;
        }
    }
    
    return 0;
}