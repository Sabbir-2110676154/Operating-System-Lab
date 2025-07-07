#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int main() {
    int s = socket(AF_INET, SOCK_STREAM, 0), c;
    struct sockaddr_in srv = {AF_INET, htons(8080), INADDR_ANY};
    bind(s, (void*)&srv, sizeof(srv));
    listen(s, 5);
    while (1) {
        c = accept(s, 0, 0);
        write(c, "Hi from server\n", 15);
        close(c);
    }
}
