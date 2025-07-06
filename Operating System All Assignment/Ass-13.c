#include <pthread.h>
#include <stdio.h>

int count = 0;

void* inc(void* a) {
    for (int i = 0; i < 100; i++) {
        printf("Before count: %d\n", count);
        count++;
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
    printf("Final count: %d\n", count);
    return 0;
}
/*Sample Output:
Final count: 178432
*/
