#include<stdio.h>
#include<stdlib.h>
#include<sys/msg.h>

int main() {
    int messageQueueId;
    key_t key;

    if ((key = ftok("./messageQueueKey", 1024)) < 0) {
        perror("ftok error");
        exit(1);
    }

    printf("Message Queue Key:%d.\n", key);
    
    if ((messageQueueId = msgget(key, IPC_CREAT|0777)) == -1) {
        perror("msgget error");
        exit(1);
    }

    printf("Message queue id:%d.\n", messageQueueId);
}
