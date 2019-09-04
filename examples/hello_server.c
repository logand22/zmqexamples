// 0MQ Hello World Server
#include <zmq.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

//#include "zhelpers.h"

int main(void) {
    // Create Server
    void* context = zmq_ctx_new();
    void* responder = zmq_socket(context, ZMQ_REP);
    int rc = zmq_bind(responder, "tcp://*:5555");

    char* response = "Your Welcome...";

    while(1) {
        char buff[256];

        // Receive Request
        int received = zmq_recv(responder, buff, 255, 0);
        if(received == -1) {
            printf("Something up with receiving\n");
            return -1;
        }
        buff[received] = '\0';

        printf("Received: %s\n", buff);

        // "Do some work"
        sleep(1);

        // Send Response
        int sent = zmq_send(responder, response, strlen(response), 0);
        if(sent == -1) {
            printf("Something up with shipping\n");
            return -1;
        }

        printf("Sent: %s\n", response);
    }

    return 0;
}
