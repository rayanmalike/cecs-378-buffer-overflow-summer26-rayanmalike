#include <stdio.h>
#include <string.h>

void safe(char *input) {
    char buffer [64];
    //strncpy limits copy to buffer size, preventing overflow
    strncpy(buffer, input, sizeof(buffer) - 1);
    buffer[63] = '\0'; //ensures termination of null
    printf("You entered: %s\n", buffer);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <input>\n", argv[0]);
        return 1;
    }

    //check input length before processing...input over 63 characters is rejected becfore reaching buffer
    if (strlen(argv[1]) >= 64) {
        printf("Error: input too long, max 63 charactrs.\n");
        return 1;
    }

    safe (argv[1]);
    return 0;
}
