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
    bind(sock,(struct sockaddr *) &server,sizeof(server));
    // listen(sock,5);
    addsize=sizeof(server);
    // connsock=accept(sock,(struct sockaddr *) NULL,NULL);
    printf("wait to recieve numbers\n");

int sumarr[100];
    while(1){
        counter++;
        bzero(snd,100);
        bzero(rec,100);
        recvfrom(sock,rec,100,0,(struct sockaddr *) &server, &addsize);
        printf("recieved num %d: %s\n",counter,rec);
        sumarr[counter-1]=atoi(rec);
        printf("The sum array is\n");
        for(int i=0;i<counter;i++){
        printf("%d ",sumarr[i]);
    }
    printf("\n");
        if(counter==2){
            int k=sumarr[0]+sumarr[1];
            snd[2]=k;
            sprintf(snd, "%d", k);
            printf("Sending sum: %i to client\n",k);
            sendto(sock,snd,100,0,(struct sockaddr *) &server, sizeof(server));
            counter=0;
        }

    }
    
    return 0;
}