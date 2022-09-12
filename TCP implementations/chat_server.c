#include <sys/types.h>
#include <sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include <netdb.h>
#include<netinet.h>
#include <stdio.h>
#include<string.h>
int main()
{
    int comp=1;
printf("send one message at a time\n");

char str[100],str2[100];
int listen_fd, comm_fd;
struct sockaddr_in servaddr;
listen_fd = socket(AF_INET, SOCK_STREAM, 0);
bzero( &servaddr, sizeof(servaddr));
servaddr.sin_family = AF_INET;
servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
servaddr.sin_port = htons(22000);
bind(listen_fd, (struct sockaddr *) &servaddr, sizeof(servaddr));
listen(listen_fd, 10);
comm_fd = accept(listen_fd, (struct sockaddr*) NULL, NULL);

while(comp!=0)
// while(strcmp(str,bye)!=0)
{
bzero( str, 100);
recv(comm_fd,str,100,0);

printf("Client: %s",str);
if(strlen(str)==0){
    printf("No data recieved.\n Closing connection\n");
    close(comm_fd);
    close(listen_fd);
}
comp=strcmp(str,bye);
// printf("strcmp %d\n",comp);
// printf("%d",comp);
printf("Me: ");
fgets(str2,100,stdin);

// printf("Me: %s",str2);
send(comm_fd,str2,strlen(str2),0);
printf("(wait for reply)\n");
}
close(comm_fd);
close(listen_fd);
return 0;
}