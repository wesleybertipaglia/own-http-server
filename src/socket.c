#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>
#include "socket.h"

extern volatile sig_atomic_t running;

int create_server_socket(const char *host, int port)
{
    int server_fd;
    struct sockaddr_in server_addr;
    int opt = 1;

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("Error creating socket");
        exit(1);
    }

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1) {
        perror("Error setting socket options");
        exit(1);
    }

    if (fcntl(server_fd, F_SETFL, O_NONBLOCK) == -1) {
        perror("Error setting non-blocking");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    if (inet_pton(AF_INET, host, &server_addr.sin_addr) <= 0) {
        perror("Invalid address");
        exit(1);
    }
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
    while (running) {
        client_socket = accept(server_fd, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_socket != -1) {
            return client_socket;
        }
        if (errno != EAGAIN && errno != EWOULDBLOCK) {
            perror("Error accepting connection");
            return -1;
        }
    }
    return -1;
}
