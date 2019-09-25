#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main(){
	int fb[2];
	pipe (fb);
	char str1[] = "something_text";
	int pid = fork();
	if(pid < 0){
		return 1;
	}
	else if(pid > 0){
		sleep(1);
		char str2[]="";
		read(fb[0], str2, sizeof(str1));
		printf("%s\n", str2);
	}
	else{
		write(fb[1], str1, sizeof(str1));
	}
	return 0;
}
