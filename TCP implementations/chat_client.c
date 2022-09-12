#include<sys/socket.h>
#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
#include<netdb.h>
#include<string.h>
#include<netdb.h>
#include<stdlib.h>
#include<arpa/inet.h>
int main(int argc,char **argv)
{
int sockfd,n=0;
printf("send one message at a time\n");
char sendline[100];
char recvline[100];
char bye[100]="BYE";
char dummy[100];
struct sockaddr_in servaddr;
sockfd=socket(AF_INET,SOCK_STREAM,0);
bzero(&servaddr,sizeof servaddr);
servaddr.sin_family=AF_INET;
servaddr.sin_port=htons(22000);
servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
//inet_pton(AF_INET,"127.0.0.1",&(servaddr.sin_addr));
connect(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
while(1)
{
bzero( sendline, 100);
bzero( recvline, 100);

printf("Me: ");
fgets(sendline,100,stdin); /*stdin = 0 , for standard input */

while(strlen(sendline)<1){
    printf("Invalid message length\n");
    n++;
    printf("Attempts left: %d",(3-n));
    fgets(sendline,100,stdin); /*stdin = 0 , for standard input */
    if(n==3){
    printf("Attempts exhausted. Closing connection\n");
    close(sockfd);
}
}
send(sockfd,sendline,strlen(sendline),0);
printf("(wait for reply)\n");
recv(sockfd,recvline,100,0);
printf("Server: %s",recvline);

}
}