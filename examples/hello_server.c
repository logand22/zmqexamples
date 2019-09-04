#include <zmq.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "zhelpers.h"

int main(void) {
    printf("%d\n", EAGAIN);

    void* context = zmq_ctx_new();
    void* responder = zmq_socket(context, ZMQ_REP);
    int rc = zmq_bind(responder, "tcp://*:5555");

    while(1) {
        char* str_recv = s_recv(responder);
        if(str_recv == NULL) {
            printf("The error message is: %s\n", strerror(errno));
            return -1;
        }
        printf("%s\n", str_recv);
        free(str_recv);
    }

    return 0;
}
