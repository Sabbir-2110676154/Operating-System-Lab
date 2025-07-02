#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd[2];
    char write_msg[] = "Hello from parent";
    char read_msg[100];

    if (pipe(fd) == -1) {
        perror("Pipe failed");
        exit(1);
    }

    pid_t pid = fork();

    if (pid == 0) {
        // Child process: read from pipe
        close(fd[1]); // Close write end
        read(fd[0], read_msg, sizeof(read_msg));
        printf("Child received: %s\n", read_msg);
        close(fd[0]);
    } else {
        // Parent process: write to pipe
        close(fd[0]); // Close read end
        write(fd[1], write_msg, strlen(write_msg) + 1);
        close(fd[1]);
        wait(NULL); // Wait for child to finish
    }

    return 0;
}
/* Sample output:
Child received: Hello from parent
*/