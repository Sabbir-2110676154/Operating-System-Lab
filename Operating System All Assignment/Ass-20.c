#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int *nums, count;
int avg, min, max;

void* get_avg(void* arg) {
    int sum = 0;
    for (int i = 0; i < count; i++) sum += nums[i];
    avg = sum / count;
    return NULL;
}

void* get_min(void* arg) {
    min = nums[0];
    for (int i = 1; i < count; i++)
        if (nums[i] < min) min = nums[i];
    return NULL;
}

void* get_max(void* arg) {
    max = nums[0];
    for (int i = 1; i < count; i++)
        if (nums[i] > max) max = nums[i];
    return NULL;
}

int main(int argc, char *argv[]) {
    count = argc - 1;
    nums = malloc(count * sizeof(int));
    for (int i = 0; i < count; i++) nums[i] = atoi(argv[i + 1]);

    pthread_t t1, t2, t3;
    pthread_create(&t1, NULL, get_avg, NULL);
    pthread_create(&t2, NULL, get_min, NULL);
    pthread_create(&t3, NULL, get_max, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    printf("Average = %d\nMin = %d\nMax = %d\n", avg, min, max);
    free(nums);
    return 0;
}
/*Sample Output:
$ ./stats 90 81 78 95 79 72 85
Average = 82
Min = 72
Max = 95
*/
