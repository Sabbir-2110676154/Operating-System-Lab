#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <unistd.h>

struct msg { long t; char m[100]; };

int main() {
    int id = msgget(1234, 0666 | IPC_CREAT);
    pid_t pid = fork();
    if (pid == 0) {
        struct msg r;
        msgrcv(id, &r, sizeof(r.m), 1, 0);
        printf("Child got: %s\n", r.m);
    } else {
        struct msg s = {1, "Hello Child"};
        msgsnd(id, &s, sizeof(s.m), 0);
        wait(NULL);
        msgctl(id, IPC_RMID, NULL);
    }
    return 0;
}
/*Sample output:
Child got: Hello Child
*/