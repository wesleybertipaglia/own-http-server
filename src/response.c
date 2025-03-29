#include "response.h"
#include <string.h>
#include <unistd.h>

void send_http_response(int client_socket)
{
    char *response =
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: text/html\r\n"
        "Connection: close\r\n\r\n"
        "<html><body><h1>Hello, World!</h1></body></html>";

    write(client_socket, response, strlen(response));
}
