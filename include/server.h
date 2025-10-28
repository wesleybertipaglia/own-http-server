#ifndef SERVER_H
#define SERVER_H

#include "config.h"

void start_server(server_config_t *config);
void handle_client(void *arg);

#endif
