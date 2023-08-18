/*
inet_aton() converts the Internet host address cp from the IPv4 numbers-and-dots notation into binary form (in network byte order) and stores it in the structure that inp points to. inet_aton() returns nonzero if the address is valid, zero if not. The address supplied in cp can have one of the following forms:

int inet_aton(const char *cp, struct in_addr *inp);
*/

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **args){
    char sample_ip[] = "8.8.8.8333";
    struct in_addr ipv4;

    memset(&ipv4, 0, sizeof(struct in_addr));
    
    if(0 == inet_aton(sample_ip, &ipv4)){
        printf(" Error \n");
    }else{
        printf("%d\n", ipv4.s_addr);


    }
    return 0;
}