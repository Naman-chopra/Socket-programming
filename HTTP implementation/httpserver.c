#include<stdio.h>
#include<netdb.h>
#include<string.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<stdlib.h>

void setHttpHeader(char httpHeader[])
{
    // File object to return
    FILE *htmlData = fopen("index.html", "r");

    char line[100];
    char responseData[8000];
    while (fgets(line, 100, htmlData) != 0) {
        strcat(responseData, line);
    }
    // char httpHeader[8000] = "HTTP/1.1 200 OK\r\n\n";
    strcat(httpHeader, responseData);
}

int main(){
    char httpHeader[8000] = "HTTP/1.1 200 OK\r\n\n";
    int portno=80,sockfd;
    char recbuf[4096],sndbuf[4096];

    struct sockaddr_in server;
    bzero(&server,sizeof(server));

    sockfd=socket(AF_INET,SOCK_STREAM,0);
     server.sin_addr.s_addr=htonl(INADDR_ANY);
     server.sin_family=AF_INET;
     server.sin_port=htons(portno);
    bind(sockfd, (struct sockaddr *) &server, sizeof(server));
    listen(sockfd,5);
    setHttpHeader(httpHeader);  // Custom function to set header
    int newsockfd;
    newsockfd=accept(sockfd, (struct sockaddr *) NULL, NULL);
    while(1){

     send(newsockfd,httpHeader,sizeof(httpHeader),0);
    //  recv(newsockfd,recbuf,4096,0);
    }

    return 0;
}