#ifndef __ZHELPERS_H_INCLUDED__
#define __ZHELPERS_H_INCLUDED__

#include <zmq.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define randof(num) (int) ((float) (num) * random () / (RAND_MAX + 1.0))

static char* s_recv(void* socket) {
    char buff[256];
    int size = zmq_recv(socket, buff, 255, 0);
    if(size == -1)
        return NULL;
    buff[size] = '\0';
    return strdup(buff);
}

static int s_send(void* socket, char* string) {
    int size = zmq_send(socket, string, strlen(string), 0);
    return size;
}

#endif
