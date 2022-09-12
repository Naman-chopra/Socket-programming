#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<netdb.h>
int main(){
    int sockfd,newsockfd,portno=22000;
    char recvline[100];
    char sendline[100];
    struct sockaddr_in servaddr;
    bzero(&servaddr,sizeof(servaddr));
    sockfd=socket(AF_INET,SOCK_STREAM,0);
    servaddr.sin_family=AF_INET;
    servaddr.sin_port=htons(portno);
    servaddr.sin_addr.s_addr=htonl(INADDR_ANY);

    bind(sockfd,(struct sockaddr *) &servaddr, sizeof(servaddr));
    listen(sockfd,5);

    newsockfd=accept(sockfd,(struct sockaddr *) NULL,NULL);
    int counter=0;
    int sumarr[100];
while(1){

    bzero(recvline,100);
    bzero(sendline,100);
    recv(newsockfd,recvline,100,0);
    counter++;
    printf("Recieved num %i: %s\n",counter,recvline);
    sumarr[counter-1]=atoi(recvline);
    bzero(recvline,100);
    printf("The sum array is\n");
    for(int i=0;i<counter;i++){
        printf("%d ",sumarr[i]);
    }
    printf("\n");
    bzero(recvline,100);
    if(counter==2){
    int k=sumarr[0]+sumarr[1];
    sendline[2]=k;
    counter=0;
    sprintf(sendline, "%d", k);
    send(newsockfd,sendline,100,0);
    printf("Sent sum\n");

    }


}

    close(newsockfd);
    close(sockfd);
    return 0;
}