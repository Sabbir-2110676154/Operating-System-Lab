#include <stdio.h>   
#include <stdlib.h>  
#include <unistd.h> 
#include<sys/wait.h>


int main(int argc,char *argv[]) {
int n;
scanf("%d",&n);
    pid_t pid[n+1];
 
for(int i=0;i<n;i++){
    pid[i] = fork();

    if (pid[i] == 0) { // Child 1
     printf("child %d PID %d terminating\n", i,getpid());

        exit(EXIT_SUCCESS);
    } else { 
if(i==n){
            for(int i=1;i<=n;i++){
            wait(NULL);

}  
 printf("Parent PID %d terminating\n", getpid());
                
            }
        }
    }
    return 0;
}
/* Sample Output:
3
child1 PID 6595 terminating
child2 PID 6594 terminating
child3 PID 6596 terminating
*/
