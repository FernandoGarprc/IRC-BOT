#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>

#define PORT "6697"


struct info{
char *host;
char *channel;
char *user;
}Ainfo;



int main(int argc, char *argv[])
{
    struct addrinfo hints;
    struct addrinfo *result,*copy;
    int sock,getadd;


    if(argc<3)
    {
    perror("too few Arguments\n");
    exit(0);
    }
        Ainfo.host=argv[2];

        memset(&hints, 0, sizeof(struct addrinfo));
        hints.ai_family = AF_UNSPEC;
        hints.ai_socktype = SOCK_DGRAM;
        hints.ai_flags = 0;


        getadd=getaddrinfo(Ainfo.host,PORT,(struct addrinfo *)&hints,&result);
        if(getadd!=0){
        perror("\n");
        exit(0);
        }
        copy=result;

        sock = socket(copy->ai_family,copy->ai_socktype,copy->ai_protocol);
        if (connect(sock, copy->ai_addr, copy->ai_addrlen) != 0)
        {
        perror("\n");
        exit(0);
        }



    return 0;
}


void send_inf(int sockct,char msg)
{






}
