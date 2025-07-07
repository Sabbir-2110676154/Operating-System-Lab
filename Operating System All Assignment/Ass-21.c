#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int *fib, n;

void* generate_fib(void* arg) {
    fib[0] = 0;
    if (n > 1) fib[1] = 1;
    for (int i = 2; i < n; i++)
        fib[i] = fib[i - 1] + fib[i - 2];
    return NULL;
}

int main(int argc, char *argv[]) {
    n = atoi(argv[1]);
    fib = malloc(n * sizeof(int));

    pthread_t t;
    pthread_create(&t, NULL, generate_fib, NULL);
    pthread_join(t, NULL);

    for (int i = 0; i < n; i++)
        printf("%d ", fib[i]);
    printf("\n");

    free(fib);
    return 0;
}
/*Sample Output:
$ ./fib 8
0 1 1 2 3 5 8 13
*/
