#include <stdio.h>
#include <string.h>

//never actually is called in normal execution
void secret() {
    printf("Access Granted! You have reached the secret function.\n");
}

//vulnerable because strcpy does no bounds checking
void vulnerable(char * input) {
    char buffer[64];
    //on overflow, segfault is linux, Trace/BPT trap on mac os
    strcpy(buffer, input); //if input > 64 bytes, stack overflow
    printf("You entered %s\n", buffer);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <input>\n", argv[0]);
        return 1;
    }
    vulnerable(argv[1]);
    return 0;
}