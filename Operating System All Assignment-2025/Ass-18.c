#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
int main() {
    int sid = semget(1234, 1, 0666 | IPC_CREAT);
    semctl(sid, 0, SETVAL, 2); // Counter = 2
    struct sembuf p = {0, -1, 0}, v = {0, 1, 0};

    printf("Acquiring...\n");
    semop(sid, &p, 1); printf("Entered 1\n");
    semop(sid, &p, 1); printf("Entered 2\n");

    semop(sid, &v, 1); printf("Left 1\n");
    semop(sid, &v, 1); printf("Left 2\n");

    semctl(sid, 0, IPC_RMID);
    return 0;
}
/*Sample Output:
Acquiring...
Entered 1
Entered 2
Left 1
Left 2
*/