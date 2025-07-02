#include <fcntl.h>
#include <unistd.h>
int main() {
    int fd = open("mypipe", O_WRONLY);
    write(fd, "Hello", 6);
    close(fd);
    return 0;
}
