#include <stdlib.h>
#include <string.h>
#include "config.h"

server_config_t *load_config(int argc, char *argv[]) {
    server_config_t *config = malloc(sizeof(server_config_t));
    if (!config) {
        return NULL;
    }

    // Default values
    config->port = 8080;
    config->host = strdup(getenv("HOST") ? getenv("HOST") : "0.0.0.0");
    config->root_dir = strdup(getenv("ROOT_DIR") ? getenv("ROOT_DIR") : ".");

    // Check for port from env
    char *port_env = getenv("PORT");
    if (port_env) {
        int port = atoi(port_env);
        if (port > 0 && port <= 65535) {
            config->port = port;
        }
    }

    // Check for port argument
    if (argc > 1) {
        int port = atoi(argv[1]);
        if (port > 0 && port <= 65535) {
            config->port = port;
        }
    }

    return config;
}

void free_config(server_config_t *config) {
    if (config) {
        free(config->host);
        free(config->root_dir);
        free(config);
    }
}