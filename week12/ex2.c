#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[]){
	char buffer[128];
	int append = 0;
	char * mode = "w";
	for (int i = 0; i < argc; i++){
		if (strcmp(argv[i], "-a") == 0){
			append = 1;
		}
	}

	if (append){
		mode = "a";
	}

	fread(buffer, 1, 128, stdin);

	for (int i = 1; i < argc; i++){
		if  (strcmp(argv[i], "-a") != 0){
			FILE* my_file = fopen(argv[i], mode);
			fprintf(my_file, "%s", buffer);
			fclose(my_file);
		}
	} 
	printf("%s", buffer);
	return 0;
}
