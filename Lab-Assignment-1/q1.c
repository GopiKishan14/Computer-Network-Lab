#include <stdio.h>
#include <unistd.h>

int main() {
	if (fork() == 0) {
        // Created child 1 of Parent.
		int id = getpid();
		if (fork() == 0) {
            // Created grandchild1 of Parent (child1 of child1)
			sleep(2);
			// printf("Created grandchild1 of Parent (child1 of child1)\n");
			printf("Grand Child1 : %d ", getpid());
			printf("its parent id : %d\n", getppid());
		} else {
            // child1 continues
			if (fork() == 0) {
                // Created grandchild2 of Parent (child2 of child1)
				sleep(2);
				printf("Grand Child2 : %d ", getpid());
				printf("its parent id : %d\n", getppid());
			} else {
                // child 1 process continues and pid get printed
				printf("Child1 : %d ", getpid());
				printf("its parent id : %d\n", getppid());
			}
		}
		wait(NULL);
		wait(NULL);
	} else {
            // Parent process continues

		if (fork() == 0) {
            // Created child 2 of Parent
			if (fork() == 0) {
                // Created grandchild3 of Parent (child1 of child2)
				sleep(2);
				printf("Grand Child3 : %d ", getpid());
				printf("its parent id : %d\n", getppid());
			} else {

                // child2 continues

				if (fork() == 0) {

                    // Created grandchild4 of Parent (child2 of child2)
					sleep(2);
					printf("Grand Child4 : %d ", getpid());
					printf("its parent id : %d\n", getppid());
				} else {
                    // child2 process continues and pid get printed
					printf("Child2 : %d ", getpid());
					printf("its parent id : %d\n", getppid());
				}
			}
			wait(NULL);
			wait(NULL);
		} else {
            // Parent process continues here
			sleep(5);
			printf("Parent : %d\n", getpid());		
		}
	}
}