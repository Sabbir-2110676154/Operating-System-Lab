#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    int id = shmget(1234, sizeof(int), 0666 | IPC_CREAT);
    int *count = (int*) shmat(id, NULL, 0);
    *count = 0;

    if (fork() == 0) {
        for (int i = 0; i < 100; i++) {
            printf("Before count: %d\n", count);
            (*count)++;
            printf("After count: %d\n", count);
        }
    } else {
        for (int i = 0; i < 100000; i++){
            printf("Before count: %d\n", count);
            (*count)++;
            printf("After count: %d\n", count);
        }
        wait(NULL);
        printf("Final count: %d\n", *count);
        shmctl(id, IPC_RMID, NULL);
    }
    return 0;
}
/*Sample Output:
Final count: 134521
*/
