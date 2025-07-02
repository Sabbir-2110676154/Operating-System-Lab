#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();
    if (pid == 0) {
        printf("Child done. PID: %d\n", getpid());
        exit(0); // Child exits
    } else {
        sleep(10); // Parent delays, doesn't wait()
        printf("Parent running. PID: %d\n", getpid());
        while (1); // Keep parent alive
    }
    return 0;
}

//Sample output:
/*Child done. PID: 1234
Parent running. PID: 1233
*/