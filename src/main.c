#include <stdio.h>
#include "server.h"

int main()
{
    int port = 8080;
    printf("Starting server on port %d...\n", port);
    start_server(port);
    return 0;
}
