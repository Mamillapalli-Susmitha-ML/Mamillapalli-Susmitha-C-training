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
        message.mtype = 1;  // Set the message type

        // Get user input
        std::cout << "Writer: ";
        std::cin.getline(message.mtext, MAX_MESSAGE_SIZE);

        // Send the message to the queue
        if (msgsnd(msqid, &message, strlen(message.mtext) + 1, 0) == -1) {
            std::cerr << "Failed to send message." << std::endl;
            exit(1);
        }

        // Check for the termination message
        if (strcmp(message.mtext, "bye") == 0) {
            break;
        }
    }

    return 0;
}

