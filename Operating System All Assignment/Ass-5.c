#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
   
    int Pid1, Pid2, Pid3;
    printf("Parent Process Started: PID %d\n", getpid());
    Pid1 = fork();
    if (Pid1 == 0) {
        printf("child 1  PID %d PPID %d\n", getpid(), getppid());
       
        exit(0);
    } else {
        Pid2 = fork();
        if (Pid2 == 0) {
            printf("child2 : PID = %d, PPID = %d\n", getpid(), getppid());
        
            exit(0);
        } else {
            Pid3 = fork();
            if (Pid3 == 0) {
                Printf ("child3  PID = %d, PPID = %d\n", getpid(), getppid());
                exit(0);
            } else {
                Wait(NULL);
                Wait(NULL);
                Wait(NULL);
                Printf ("Parent Process (PID %d) Finished.\n", getpid());
            }
        }
        return 0;
    }
/* Sample Output:
Parent Process Started: PID 2107
child 1 PID 2108 PPID 2107
child2 : PID = 2109 PPID = 2107
child3 PID = 2110, PPID = 2107
Parent Process (2107) Finished
*/
