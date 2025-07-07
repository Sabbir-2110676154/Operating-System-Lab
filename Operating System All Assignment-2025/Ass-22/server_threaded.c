#include <pthread.h>
#include <unistd.h>
#include <netinet/in.h>
#include <stdio.h>

void* handle(void* cs) {
    int c = *(int*)cs;
    write(c, "Hi from thread\n", 15);
    close(c);
    return NULL;
}

int main() {
    int s = socket(AF_INET, SOCK_STREAM, 0), c;
    struct sockaddr_in srv = {AF_INET, htons(8080), INADDR_ANY};
    bind(s, (void*)&srv, sizeof(srv));
    listen(s, 5);
    while (1) {
        c = accept(s, 0, 0);
        pthread_t t;
        pthread_create(&t, NULL, handle, &c);
        pthread_detach(t);
    }
}
