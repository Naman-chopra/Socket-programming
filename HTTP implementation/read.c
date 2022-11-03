#include<stdio.h>
#include<netdb.h>
#include<string.h>
#include<netinet/in.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<stdlib.h>
int portno;
void configreader(){
    FILE *fpoint;
    char filebuf[999999];
    fpoint=fopen("config.txt","r");
    fgets(filebuf,999999,fpoint);
    printf(filebuf);
//     char s1[100]="18000";
//    for(int i=0; i<999999; i++)
//    {
//      if(strcmp(s1, filebuf[i]) == 0)
//      {
//     //    found=1;
//        printf("Found in row-%d\n", i+1);
//      }
//    }
};
int main(){
    configreader();
    return 0;
}