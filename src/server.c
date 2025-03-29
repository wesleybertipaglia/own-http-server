#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "server.h"
#include "socket.h"
#include "handler.h"

void start_server(int port)
{
    int server_fd = create_server_socket(port);
    printf("HTTP server started on port %d\n", port);

    while (1)
    {
        int client_socket = accept_client(server_fd);
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, (void *)handle_client, (void *)&client_socket);
        pthread_detach(thread_id);
    }
}

void handle_client(int client_socket)
{
    process_request(client_socket);
    close(client_socket);
}
