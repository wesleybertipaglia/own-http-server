#include <stdio.h>
#include <unistd.h>
#include "handler.h"
#include "response.h"

void process_request(int client_socket)
{
    char buffer[1024] = {0};
    ssize_t bytes_received = read(client_socket, buffer, sizeof(buffer) - 1);

    if (bytes_received == -1)
    {
        perror("Error reading request");
    }
    else
    {
        buffer[bytes_received] = '\0';
        printf("Received request:\n%s\n", buffer);
    }

    send_http_response(client_socket);
}
