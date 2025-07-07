#include <sys/ipc.h>
#include <sys/msg.h>
struct msg { long type; char text[100]; };
int main() {
    key_t k = ftok("file", 65);
    int qid = msgget(k, 0666 | IPC_CREAT);
    struct msg m = {1, "Hello from sender"};
    msgsnd(qid, &m, sizeof(m.text), 0);
    return 0;
}
