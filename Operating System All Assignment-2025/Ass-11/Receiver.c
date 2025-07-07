#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
struct msg { long type; char text[100]; };
int main() {
    key_t k = ftok("file", 65);
    int qid = msgget(k, 0666 | IPC_CREAT);
    struct msg m;
    msgrcv(qid, &m, sizeof(m.text), 1, 0);
    printf("Received: %s\n", m.text);
    msgctl(qid, IPC_RMID, NULL); // remove queue
    return 0;
}
