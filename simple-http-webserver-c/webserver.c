#include <stdio.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 5000

int main(int argc, char const *argv[])
{

    // creating a socket
    int socket_file_descriptor = socket(AF_INET, SOCK_STREAM, 0);

    if (socket_file_descriptor == -1)
    {
        perror("webserver (socket)");
        return 1;
    }
    printf("SUCCESS! Socket has been created.\n");


    // the address to bind the socket to.
    struct sockaddr_in host_addr;
    int host_addrlen = sizeof(host_addr);

    host_addr.sin_family = AF_INET;
    host_addr.sin_port = htons(PORT);
    host_addr.sin_addr.s_addr = htonl(INADDR_ANY);


    // binding the socket to the address
    if(bind(socket_file_descriptor, (struct sockaddr *)&host_addr, host_addrlen)!= 0){
        perror("webserver (bind)");
        return 1;
    }
    printf("SUCCESS! Socket has been bounded to address\n");


    // listen for incoming connections
    if(listen(socket_file_descriptor, SOMAXCONN) != 0){
        perror("webserver (listen)");
        return 1;
    }
    printf("SUCCESS! Server listening for connections\n");

    return 0;
}