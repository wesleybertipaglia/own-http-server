#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <signal.h>
#include "server.h"
#include "socket.h"
#include "handler.h"

extern volatile sig_atomic_t running;

void start_server(server_config_t *config)
{
    int server_fd = create_server_socket(config->host, config->port);
    printf("HTTP server started on %s:%d\n", config->host, config->port);

    while (running)
    {
        int *client_socket = malloc(sizeof(int));
        *client_socket = accept_client(server_fd);

        if (*client_socket == -1)
        {
            free(client_socket);
            continue;
        }

        if (!running) {
            free(client_socket);
            break;
        }

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, (void *)handle_client, (void *)client_socket);
        pthread_detach(thread_id);
    }

    close(server_fd);
}

void handle_client(void *arg)
{
    int client_socket = *(int *)arg;
    free(arg);

    process_request(client_socket);
    close(client_socket);
}
