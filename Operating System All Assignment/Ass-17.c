#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int sid = semget(1234, 1, 0666 | IPC_CREAT);
    int mid = shmget(1234, sizeof(int), 0666 | IPC_CREAT);
    int *x = shmat(mid, NULL, 0);
    *x = 0;
    semctl(sid, 0, SETVAL, 1);

    struct sembuf p = {0, -1, 0}, v = {0, 1, 0};
    if (fork() == 0) {
        for (int i = 0; i < 100000; i++) {
            semop(sid, &p, 1); (*x)++; semop(sid, &v, 1);
        }
    } else {
        for (int i = 0; i < 100000; i++) {
            semop(sid, &p, 1); (*x)++; semop(sid, &v, 1);
        }
        wait(NULL);
        printf("Final: %d\n", *x);
        shmctl(mid, IPC_RMID, NULL);
        semctl(sid, 0, IPC_RMID);
    }
    return 0;
}
/*Sample Output:
Final: 200000
*/