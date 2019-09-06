// 0MQ Hello World Server
#include <zmq.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#include "zhelpers.h"

int main(void) {
    // Create Server
    void* context = zmq_ctx_new();
    void* responder = zmq_socket(context, ZMQ_REP);
    int rc = zmq_bind(responder, "tcp://*:5555");

    char* response = "Your Welcome...";

    while(1) {
        char buff[256];

        // Receive Request
        char* message = s_recv(responder);
        if(message == NULL) {
            printf("Something up with receiving\n");
            return -1;
        }
        printf("Received: %s\n", message);

        // "Do some work"
        sleep(1);

        // Send Response
        int sent = s_send(responder, response);
        if(sent == -1) {
            printf("Something up with shipping\n");
            return -1;
        }

        printf("Sent: %s\n", response);
        free(message);
    }

    return 0;
}
