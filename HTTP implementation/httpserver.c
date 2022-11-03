#include<stdio.h>
#include<netdb.h>
#include<string.h>
#include<netinet/in.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<stdlib.h>
int portno;
char filebuf[999];
void configreader(char **argv){
    FILE *fpoint;
    fpoint=fopen(argv[1],"r");
    fgets(filebuf,999,fpoint);
    // printf(filebuf);
    // portno=atoi(filebuf[0]);
};
void prepareresponse(char http_header[]){
strcat(http_header,filebuf);
};
int main(int argc, char **argv){
    char httpHeader[8000] = "HTTP/1.1 200 OK\r\n\n";
    int portno=atoi(argv[2]),sockfd;
    prepareresponse(httpHeader);
    char recbuf[4096],sndbuf[4096];

    struct sockaddr_in server;
    bzero(&server,sizeof(server));

    sockfd=socket(AF_INET,SOCK_STREAM,0);
     server.sin_addr.s_addr=htonl(INADDR_ANY);
     server.sin_family=AF_INET;
     server.sin_port=htons(portno);
    
    
    bind(sockfd, (struct sockaddr *) &server, sizeof(server));
    listen(sockfd,5);
    
    
    int newsockfd;
    newsockfd=accept(sockfd, (struct sockaddr *) NULL, NULL);
    // configreader();
    while(1){
    // char sendbuf[]="HTTP/1.1 200 OK\r\n";
    send(newsockfd,httpHeader,sizeof(httpHeader),0);

    close(newsockfd);
    }

    return 0;
}