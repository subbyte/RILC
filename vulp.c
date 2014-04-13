#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1024

int vul(char *content, int len)
{
    char buffer[16];

    /* same buffer overflow problem as Heartbleed in openssl
    here we exploit it to change the control flow */
    memcpy(buffer, content, len);

    return 0;
}
 
int main(int argc, char **argv)
{
    char *data;
    int length;
    FILE *finput;

    printf("Compile: gcc vulp.c -o vulp -fno-stack-protector ");
    printf("(-g should be involved to use SystemTap)\n");
    printf("Run: ./vulp filename (<=16B: normal, >16B: abnormal)\n");

    data = (char *) malloc (N);

    finput = fopen(argv[1], "r");
    length = fread(data, 1, N, finput);
    printf("%d bytes read.\n", length);
    fclose(finput);

    vul(data, length);

    printf("Returned Properly\n");
    return 0;
}
