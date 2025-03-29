#include "handler.h"
#include "response.h"

void process_request(int client_socket)
{
    send_http_response(client_socket);
}
