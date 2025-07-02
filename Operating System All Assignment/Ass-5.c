#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s n child_1 child_2 ... child_n\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    for (int i = 0; i < n; i++) {
        pid_t pid = fork();
        if (pid == 0) {
            printf("%s (PID: %d, PPID: %d)\n", argv[2 + i], getpid(), getppid());
            exit(0);
        }
    }
    sleep(2); // Let children print first
    printf("parent_process (PID: %d)\n", getpid());
    for (int i = 0; i < n; i++) wait(NULL);
    return 0;
}
/*Sample output:
$ ./parent_process 3 child_1 child_2 child_3
child_1 (PID: 1234, PPID: 1231)
child_2 (PID: 1235, PPID: 1231)
child_3 (PID: 1236, PPID: 1231)
parent_process (PID: 1231)
*/