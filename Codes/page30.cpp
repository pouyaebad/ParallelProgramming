// Pre-requirement : None
//
// On Linux        : g++ ./file_name.cpp
//

#include <iostream>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msgBuffer  // structure for message to pass to queue
{   
    long  msgType;
    char  msgText[200];
};


int main()
{
    if (0 == fork())
    {
        key_t key{ ftok("/home", 22) };             // generating a unique key
        int msgid{ msgget(key, 0666 | IPC_CREAT) }; // creating a message queue

        msgBuffer m1{ 2, "Hi From Process 1" };     // the message to sent
        msgsnd(msgid, &m1, sizeof(m1), 0);          // sending the message

        std::cout << "Message Sent: " << m1.msgText << std::endl;
    }
    else
    {
        key_t key{ ftok("/home", 22) };            // generating a unique key
        int msgid{ msgget(key, 0666 | IPC_CREAT) }; // creating a message queue

        msgBuffer m2;
        msgrcv(msgid, &m2, sizeof(m2), 2, 0);       // receving the message

        std::cout << "Message Received: " << m2.msgText << std::endl;

        msgctl(msgid, IPC_RMID, NULL);              // destroy the message queue
    }
}
// Result: "Hi From Process 1" will be printed twice: from sender & receiver
