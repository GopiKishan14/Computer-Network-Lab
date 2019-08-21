#include<stdio.h> 
#include<stdlib.h>
#include <sys/types.h> 
#include <unistd.h> 

int main() 
{ 
	// Create a child process	 
	int pid = fork(); 

	if (pid > 0) 
    {
        printf("In parent process with pid :  %d\n", getpid()); 
    }
		

	
	else if (pid == 0) 
	{ 
        sleep(1);
		printf("In child process with pid : %d\n", getpid());
        printf("Its parent is dead since ppid is : %d\n", getppid());
        printf("So the child process is orphan process\n");
       
        return 0;
	} 
	printf("This is parent process");
	
	return 0; 
} 
