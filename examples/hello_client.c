// 0MQ Hello World Client
#include <zmq.h>
#include <stdio.h>
#include <string.h>

//#include "zhelpers.h"

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
        char buff[256];
        
        // Send message wait for response
        int sent = zmq_send(requester, message, strlen(message), 0);
        if(sent == -1) {
            printf("F IN CHAT\n");
            return -1;
        }

        printf("Sent: %s\n", message);

        // Receive Message and print
        int returned = zmq_recv(requester, buff, 255, 0);
        if(returned == -1) {
            printf("FAIELD\n");
            return -1;
        }
        buff[returned] = '\0';

        printf("Received: %s\n", buff);
    }
    return 0;
}

