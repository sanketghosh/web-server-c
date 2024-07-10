#include <errno.h>
#include <stdio.h>
#include <sys/socket.h>

int main(int argc, char const *argv[])
{

    // lets create a socket
    int socket_file_descriptor = socket(AF_INET, SOCK_STREAM, 0);

    if (socket_file_descriptor == -1)
    {
        perror("webserver (socket)");
        return 1;
    }

    printf("Socket created successfully !");

    return 0;
}
