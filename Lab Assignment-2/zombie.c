// Child becomes Zombie as parent is sleeping 
// when child process exits. 
#include <stdlib.h> 
#include<stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
int main() 
{ 
	// Fork returns process id 
	// in parent process 
	pid_t child_pid = fork(); 

	// Parent process 
	if (child_pid > 0) 
    {
        printf("Parent pid : %d\n",getpid());
        printf("Parent is sleeping now\n");
        sleep(3);
    }
		
	// Child process 
	else
    {
        printf("Child pid : %d\n", getpid());
        printf("child process terminates now\n");
        exit(0); 
    }	

    printf("pid of zombie child : %d\n", child_pid);
		
	return 0; 
} 
