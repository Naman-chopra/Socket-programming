#include<stdio.h>
#include<netdb.h>
#include<string.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<stdlib.h>

int main(){
    int portno=80,sockfd;
    char recbuf[4096],sndbuf[4096];

    struct sockaddr_in server;
    bzero(&server,sizeof(server));

    sockfd=socket(AF_INET,SOCK_STREAM,0);
     server.sin_addr.s_addr=htonl(INADDR_ANY);
     server.sin_family=AF_INET;
     server.sin_port=htons(portno);

     
     connect(sockfd, (struct sockaddr *) &server, sizeof(server));
     sprintf(sndbuf,"GET / HTTP/1.1\r\n\r\n");
     send(sockfd,sndbuf,4096);
     bzero(recbuf,4096,0);
     recv(sockfd,recbuf,4096,0);
     printf("%s",recbuf);

    return 0;
}