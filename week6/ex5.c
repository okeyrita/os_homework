#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

int main(){
	pid_t pid = fork();
	if (pid < 0){
		printf("Incorrect");
		return 1;
	}
	else if (pid == 0){
		while(1){
			printf("I'm alive\n");
			sleep(1);
		}
	}
	else{
		sleep(10);
		kill(pid, SIGTERM);
	}
	return 0;
}
