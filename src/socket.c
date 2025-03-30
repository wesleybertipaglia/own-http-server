#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include "socket.h"

int create_server_socket(int port)
{
    int server_fd;
    struct sockaddr_in server_addr;

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("Error creating socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        perror("Error when binding");
        exit(1);
    }

    if (listen(server_fd, 5) == -1)
    {
        perror("Error listening to connections");
        exit(1);
    }

    return server_fd;
}

int accept_client(int server_fd)
{
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    int client_socket;
    while ((client_socket = accept(server_fd, (struct sockaddr *)&client_addr, &client_addr_len)) == -1)
    {
        perror("Error accepting connection");
    }

    return client_socket;
}
