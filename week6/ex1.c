#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main(){
	int fb[2];
	pipe (fb);

	char str1[] = "something_text";
	char str2[] = "";
	write(fb[1], str1, sizeof(str1));
	read(fb[0], str2, sizeof(str1));
	printf("%s\n", str2);
	return 0;
}
