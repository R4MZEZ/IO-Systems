#include <stdio.h>
int main(){
	FILE *fout;
	fout = fopen("/mnt/vramdisk1/testLab2SuperTask.txt", "w");
	char s[64];
	printf("Enter your name:\n");
	scanf("%s", s);
	
	fprintf(fout, "Hello, %s!\n", s);     
	fclose(fout);
	return 0;
}
