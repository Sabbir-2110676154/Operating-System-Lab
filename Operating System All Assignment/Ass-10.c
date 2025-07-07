#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
int main() {
    mkfifo("mypipe", 0666);
    if (fork() == 0) {
        int fd = open("mypipe", O_RDONLY);
        char msg[100];
        read(fd, msg, sizeof(msg));
        printf("Child got: %s\n", msg);
        close(fd);
    } else {
        int fd = open("mypipe", O_WRONLY);
        write(fd, "Hello Child", 12);
        close(fd);
        wait(NULL);
    }
    return 0;
}
/*Sample Output:
Child got: Hello Child
*/
