#include <iostream>
#include <cstdlib>
#include <cstring>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

#define MAX_MESSAGE_SIZE 100
#define MESSAGE_QUEUE_KEY 1234

// Define the structure for the message
struct Message {
    long mtype;                  // Message type
    char mtext[MAX_MESSAGE_SIZE];  // Message content
};

int main() {
    // Create the message queue
    int msqid = msgget(MESSAGE_QUEUE_KEY, 0666 | IPC_CREAT);
    if (msqid == -1) {
        std::cerr << "Failed to create message queue." << std::endl;
        return 1;
    }

    while (true) {
        Message message;
        // Receive the message from the queue
        if (msgrcv(msqid, &message, MAX_MESSAGE_SIZE, 1, 0) == -1) {
            std::cerr << "Failed to receive message." << std::endl;
            exit(1);
        }

        // Display the received message
        std::cout << "Reader: " << message.mtext << std::endl;

        // Check for the termination message
        if (strcmp(message.mtext, "bye") == 0) {
            break;
        }
    }

    // Remove the message queue
    if (msgctl(msqid, IPC_RMID, nullptr) == -1) {
        std::cerr << "Failed to remove message queue." << std::endl;
        return 1;
    }

    return 0;
}
