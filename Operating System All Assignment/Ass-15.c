#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int id = shmget(1234, sizeof(int), 0666 | IPC_CREAT);
    int *x = (int*) shmat(id, NULL, 0);
    *x = 0;

    if (fork() == 0) {
        for (int i = 0; i < 100; i++){
            printf("Before count: %d\n", count);
            (*x)++;
            printf("After count: %d\n", count);
        }
    } else {
        for (int i = 0; i < 100; i++) {
            printf("Before count: %d\n", count);
            (*x)++;
            printf("After count: %d\n", count);
        wait(NULL);
        printf("Final: %d\n", *x);
        shmctl(id, IPC_RMID, NULL);
    }
    return 0;
}
/*Sample Output:
Final: 154321
*/
