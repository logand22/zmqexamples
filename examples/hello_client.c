#include <zmq.h>
#include <stdio.h>
#include <stdlib.h>

#include "zhelpers.h"

int main(void) {
    void* context = zmq_ctx_new();
    void* requester = zmq_socket(context, ZMQ_REQ);

    zmq_connect(requester, "tcp://localhost:5555");

    int request_nbr;
    for (request_nbr = 0; request_nbr != 10; request_nbr++) {
        char* buffer = "SEND ME";
        s_send(requester, buffer);
        char* response = s_recv(requester);
        printf("%s\n", response);
        free(response);
    }
    return 0;
}

