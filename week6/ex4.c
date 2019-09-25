#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
void s_kill(){
	printf("\nSIGKILL\n");
}
void s_stop(){
	printf("\nSIGSTOP\n");
}
void s_usr1(){
	printf("\nSIGUSR1\n");
}
int main(){
	signal(SIGKILL, s_kill);
	signal(SIGSTOP, s_stop);
	signal(SIGUSR1, s_usr1);
	pid_t pid = getpid();
	sleep(1);
	kill(pid, SIGUSR1);
	while(1);
	return 0;
}