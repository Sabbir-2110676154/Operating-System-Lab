#include <stdio.h>
#include <unistd.h>
#include <netinet/in.h>
int main() {
    int s = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in srv = {AF_INET, htons(8080), inet_addr("127.0.0.1")};
    connect(s, (void*)&srv, sizeof(srv));
    char buf[100];
    read(s, buf, sizeof(buf));
    printf("Client got: %s", buf);
    return 0;
}
