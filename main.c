#include "cipher.h"

int main() {
    int seed;
    int size;
    int option = 0;
    char *buffer;
    buffer = (char*) malloc (512);

    printf("The program prefixes all input files that you have encrypted with \'c_\' and all programs you have decrypted with \'p_\', so you can run the program as many times as you wish without having to recompile. Please place all input files into the textfiles folder for use.\n\n");

    printf("1. Encrypt\n2. Decrypt\n3. Exit Program\nPlease input choice: ");
    scanf("%d", &option);
    getchar(); //chomps off \n in stream

    while (option != 3) {
        printf("\nPlease input file name: ");
        fgets(buffer, 512, stdin);
        size = strlen(buffer);
        if (buffer[size-1]=='\n') { buffer[size-1] = 0; }

        printf("Please input seed value: ");
        scanf("%d", &seed);
        getchar(); //comps off \n in stream

        switch(option) {
            case 1:
                encrypt(buffer, seed);
                break;
            case 2:
                decrypt(buffer, seed);
                break;
            case 3:
                break;
        }
        printf("\n1. Encrypt\n2. Decrypt\n3. Exit Program\nPlease input choice: ");
        scanf("%d", &option);
        getchar(); //chomps off \n in stream
    } 
    return 0;
}