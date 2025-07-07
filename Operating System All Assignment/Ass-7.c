#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//int global_var = 10; // Global variable


int g;
int main() {

   // int local_var = 20; // Local variable
    int l;
    g=30;
    l=20;
    pid_t pid = fork();
    if (pid == 0) {
        // Child Process
        //global_var += 5;
       // local_var += 5;
        g=5;
        l=50;
        printf("Child Process:\n");
        printf("  PID: %d\n", getpid());
        printf("  Global Var: %d\n", g);
        printf("  Local Var: %d\n", l);
    } else {
        // Parent Process
        sleep(1); // Ensure child runs first
        printf("Parent Process:\n");
        printf("  PID: %d\n", getpid());
        printf("  Global Var: %d\n", g);
        printf("  Local Var: %d\n", l);
    }
    return 0;
}

/*Sample output:

Child Process:

  PID: 1234

  Global Var: 15

  Local Var: 25



Parent Process:

  PID: 1233

  Global Var: 10

  Local Var: 20

*/
