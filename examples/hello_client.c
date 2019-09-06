// 0MQ Hello World Client
#include <zmq.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "zhelpers.h"

int main(void) {
    // Create Connection
    void* context = zmq_ctx_new();
    void* requester = zmq_socket(context, ZMQ_REQ);
    zmq_connect(requester, "tcp://localhost:5555");

    // Message to send
    char* message = "Hello, World!";

    // Send 10 messages
    int request_nbr;
    for (request_nbr = 0; request_nbr != 10; request_nbr++) {
        // Send message wait for response
        int sent = s_send(requester, message);
        if(sent == -1) {
            printf("F IN CHAT\n");
            return -1;
        }

        printf("Sent: %s\n", message);

        // Receive Message and print
        char* received = s_recv(requester);
        if(received == NULL) {
            printf("FAIELD\n");
            return -1;
        }

        printf("Received: %s\n", received);
        free(received);
    }
    return 0;
}

