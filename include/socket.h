#ifndef SOCKET_H
#define SOCKET_H

int create_server_socket(const char *host, int port);
int accept_client(int server_fd);

#endif
