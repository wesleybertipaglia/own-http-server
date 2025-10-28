#ifndef REQUEST_H
#define REQUEST_H

#include <stdlib.h>

typedef struct {
    char *method;
    char *path;
    char *version;
    char **headers;
    size_t header_count;
    char *body;
    size_t body_length;
} http_request_t;

http_request_t *parse_request(const char *buffer, size_t length);
void free_request(http_request_t *request);

#endif