#ifndef CONFIG_H
#define CONFIG_H

typedef struct {
    int port;
    char *host;
    char *root_dir;
} server_config_t;

server_config_t *load_config(int argc, char *argv[]);
void free_config(server_config_t *config);

#endif