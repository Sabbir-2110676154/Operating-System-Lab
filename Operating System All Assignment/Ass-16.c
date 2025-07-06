#include <pthread.h>
#include <stdio.h>

int count = 0;
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;

void* inc(void* a) {
    for (int i = 0; i < 100; i++) {
        printf("Before count: %d\n", count);
        pthread_mutex_lock(&m);
        count++;
        pthread_mutex_unlock(&m);
        printf("After count: %d\n", count);
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;
    pthread_create(&t1, NULL, inc, NULL);
    pthread_create(&t2, NULL, inc, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    printf("Final: %d\n", count);
    return 0;
}
/*Sample output:
Final: 200000
*/
