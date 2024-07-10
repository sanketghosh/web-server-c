#include <stdio.h>
#include "server.h"
#include <server.h>

void launch(struct Server *server)
{
    printf("----WAITING FOR THE CONNECTION-----");
    int address_length = sizeof(server.address);
}

int main(int argc, char const *argv[])
{
    struct Server server = server_constructor(
        AF_INET,
        SOCK_STREAM,
        0,
        INADDR_ANY,
        80,
        10,
        launch);
}
