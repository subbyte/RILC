#include <stdio.h>
#include <stdlib.h>

void main(){
    char* varsh = getenv("VARSHELL");

    if(varsh){
        printf("$VARSHELL address: %p\n", (unsigned int)varsh);
    } else {
        printf("Error: no variable VARSHELL found.\n");
    }
}
