#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
    int sock,connsock,portno=22000,counter=0;
    char rec[100],snd[100];

    int on=1;
    struct sockaddr_in server;
    bzero(&server,sizeof(server));
    sock=socket(AF_INET,SOCK_DGRAM,0);
    server.sin_family=AF_INET;
    server.sin_addr.s_addr=inet_addr("172.16.95.255");
    server.sin_port=htons(portno);
    socklen_t addsize;
    bind(sock,(struct sockaddr *) &server,sizeof(server));
    addsize=sizeof(server);

     setsockopt(sock ,SOL_SOCKET, SO_BROADCAST, &on, sizeof(on));

int sumarr[100];
    while(1){
        bzero(snd,100);
        bzero(rec,100);
        printf("ME:");
        fgets(snd,100,stdin);
        sendto(sock,snd,100,0,(struct sockaddr *) &server, sizeof(server));
        
    }
    
    return 0;
}
