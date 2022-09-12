#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>

int main(){
    int sockfd,portno=22000,counter;
    char sendline[100],recvline[100];

    struct sockaddr_in myaddr;
    sockfd=socket(AF_INET,SOCK_STREAM,0);
    bzero(&myaddr,sizeof(myaddr));
    myaddr.sin_family=AF_INET;
    myaddr.sin_port=htons(portno);
    myaddr.sin_addr.s_addr=htonl(INADDR_ANY);

    connect(sockfd,(struct sockaddr *) &myaddr,sizeof(myaddr));
    counter=0;
    while(1){
        counter++;
    bzero(sendline,100);
    bzero(recvline,100);
    printf("Send num %i: ",counter);
    fgets(sendline,100,stdin);
    send(sockfd,sendline,100,0);

    if(counter==2){
        recv(sockfd,recvline,100,0);
        printf("%s\n",recvline);
        counter=0;
    }
        }
    close(sockfd);
 return 0;
}