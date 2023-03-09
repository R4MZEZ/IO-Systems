#include <stdio.h>
//#include <conio.h>

int main(){
    FILE *fs = fopen("/dev/var4", "w");
    char buf[1024];
    printf("Your input:\n");
    scanf("%s", buf);
    fprintf(fs, buf);
    fclose(fs);
    return 0;
}
