#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    char *child_names[] = {"child_1", "child_2", "child_3"};

    for (int i = 0; i < 3; i++) {
        pid = fork();
        if (pid == 0) {
            // Child process
            printf("%s: PID = %d, PPID = %d\n", child_names[i], getpid(), getppid());
            exit(0);
        }
    }

    // Parent process waits for all children
    for (int i = 0; i < 3; i++) wait(NULL);

    printf("parent_process: PID = %d\n", getpid());

    return 0;
}

/*Sample Output

child_1: PID = 1234, PPID = 1230
child_2: PID = 1235, PPID = 1230
child_3: PID = 1236, PPID = 1230
parent_process: PID = 1230
*/