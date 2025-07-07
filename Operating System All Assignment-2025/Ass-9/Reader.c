#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
int main() {
    char msg[100];
    int fd = open("mypipe", O_RDONLY);
    read(fd, msg, sizeof(msg));
    printf("Received: %s\n", msg);
    close(fd);
    return 0;
}
