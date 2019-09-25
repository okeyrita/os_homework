#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

int main(){
	int fb[2];
	pipe(fb);
	pid_t ch2;
	printf("Main process creates 1 child process\n");
	pid_t ch1 = fork();

	if (ch1 < 0){
		printf("Incorrect behaviour (child 1)\n");
		return 1;
	}
	else if(ch1 == 0){//child1
		close(fb[1]);
		read(fb[0], &ch2, sizeof(ch2));
		printf("Child 1 gets pid of the child2 from buffer\n");
		printf("Child 1 sleeps 2 seconds\n");
		sleep(2);
		printf("Child 1 sends a stop signal to child 2\n");
		kill(ch2, SIGSTOP);

	}
	else{//main process
		printf("Main process creates 2nd child process\n");
		ch2 = fork();
		if (ch2 < 0){
			printf("Incorrect behaviour (child 2)\n");
			return 1;
		}
		else if (ch2 == 0){
			printf("Child 2 starts\n");
			while(1);
		}
		else{
			close (fb[0]);
			printf("Main process writes pid of child 2 to buffer\n");
			write(fb[1], &ch2, sizeof(ch2));
			waitpid(ch2, NULL, WUNTRACED);

		}

	}
	return 0;
}