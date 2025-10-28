#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "server.h"
#include "config.h"

volatile sig_atomic_t running = 1;
server_config_t *global_config;

void signal_handler(int sig) {
    running = 0;
    printf("\nShutting down server...\n");
}

int main(int argc, char *argv[])
{
    server_config_t *config = load_config(argc, argv);
    if (!config) {
        fprintf(stderr, "Failed to load config\n");
        return 1;
    }

    global_config = config;

    signal(SIGINT, signal_handler);

    printf("Starting server on %s:%d...\n", config->host, config->port);
    start_server(config);

    free_config(config);
    return 0;
}
