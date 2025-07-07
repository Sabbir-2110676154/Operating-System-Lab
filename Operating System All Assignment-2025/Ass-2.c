#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid > 0) {
        // Parent process
        printf("Parent: PID = %d, Child PID = %d\n", getpid(), pid);
        sleep(2);  // Let child live longer
        printf("Parent exiting...\n");
    } else if (pid == 0) {
        // Child process
        sleep(5);  // Wait longer than parent
        printf("Child: PID = %d, New PPID = %d (should be init)\n", getpid(), getppid());
    } else {
        printf("Fork failed.\n");
    }

    return 0;
}

//Sample output:
/*Parent: PID = 1024, Child PID = 1025
Parent exiting...
Child: PID = 1025, New PPID = 1 (should be init)
*/