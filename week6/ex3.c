#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
void notify(){
	printf("\n%s\n", "notification");
}
int main(){
	signal(SIGINT, notify);
	while(1);
	return 0;
}

