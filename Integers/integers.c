#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// FILL IN THE BODY OF THIS FUNCTION.
// Feel free to create any other functions you like; just include them in this file.
void repr_convert(char source_repr, char target_repr, unsigned int repr) {
    char st[] = {source_repr, target_repr};
    unsigned int sign = repr >> 31;

    if ((st[0] == 'S') && (st[1] == 'S')) {
        if (repr == 0x80000000) {
            printf("%08x\n", 0x00000000);
        }
        else {
            printf("%08x\n", repr);
        }
    }
    else if ((st[0] == 'S') && (st[1] == '2')) {
        if (sign == 0) {
            printf("%08x\n", repr);
        }
        else {
            printf("%08x\n", ~(repr & 0x7FFFFFFF) + 1);
        }
    }
    else if ((st[0] == '2') && (st[1] == '2')) {
        printf("%08x\n", repr);
    }
    else if ((st[0] == '2') && (st[1] == 'S')) {
        if (repr == 0x80000000) {
            printf("undefined\n");
        }
        else if (sign == 0) {
            printf("%08x\n", repr);
        }
        else {
            if ((~(repr & 0x7FFFFFFF) + 1) == 0x80000000) {
                printf("%08x\n", 0x00000000);
            }
            else {
                repr -= 1;
                repr ^= 0x7FFFFFFF;
            printf("%08x\n", repr);
            }
        }
    }
    else {
        printf("error\n");
    }
}

// DO NOT CHANGE ANY CODE BELOW THIS LINE
int main(int argc, char *argv[]) {
    (void)argc; // Suppress compiler warning
    (void)argv;
    
    //repr_convert(argv[1][0], argv[2][0], (int)strtol(argv[3], NULL, 16));
    
    return 0;
}
