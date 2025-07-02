#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid;
    for (int i = 1; i <= 3; i++) {
        pid = fork();
        if (pid == 0) {
            printf("child_%d (PID: %d, PPID: %d)\n", i, getpid(), getppid());
            exit(0);
        }
    }
    sleep(2); // Let children print first
    printf("parent_process (PID: %d)\n", getpid());
    for (int i = 0; i < 3; i++) wait(NULL);
    return 0;
}
/*Sample output:
child_1 (PID: 1234, PPID: 1231)
child_2 (PID: 1235, PPID: 1231)
child_3 (PID: 1236, PPID: 1231)
parent_process (PID: 1231)
*/