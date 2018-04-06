#include "cipher.h"

void encrypt(char *buffer, int seed) {
    int work = 0;
    int cur = 0;
    int num = 0;
    int result = 0;

    char *name;
    name = (char*) malloc (strlen(buffer)+10);
    sprintf(name, "textfiles/%s", buffer);

    FILE *fp;
    fp = fopen(name,"r");
    if (fp==NULL) { printf("File %s not found!\n",name); exit(1); }
    
    char *temp;    
    temp = (char*) malloc (strlen(buffer));
    temp = strtok(buffer, ".");

    result =  sprintf(name, "textfiles/c_%s.txt", temp);
    if (result==0) { printf("File output naming failed.\n"); exit(1); }

    FILE *out;
    out = fopen(name,"w");

    srand(seed);

    memset(buffer, 0, strlen(buffer));

    while (cur != EOF) {
        result = 0;
        cur = fgetc(fp);
        work = cur;

        //To keep the random character an ASCII character
        while ((num >= 0) && (num <= 31)) {
            num = abs(rand() % 256);
        }

        work = cur ^ num;
        result = fputc(work, out);
        if (result==EOF) { printf("Printing to file failed.\n"); exit(1); }
    }; 

    fclose(fp);
    fclose(out);
}

void decrypt(char *buffer, int seed) {
    int work = 0;
    int cur = 0;
    int num = 0;
    int result = 0;

    char *name;
    name = (char*) malloc (strlen(buffer)+10);
    sprintf(name, "textfiles/%s", buffer);

    FILE *fp;
    fp = fopen(name,"r");
    if (fp==NULL) { printf("File %s not found!\n",name); exit(1); }
    
    char *temp;    
    temp = (char*) malloc (strlen(buffer));
    temp = strtok(buffer, ".");

    result =  sprintf(name, "textfiles/p_%s.txt", temp);
    if (result==0) { printf("File output naming failed.\n"); exit(1); }

    FILE *out;
    out = fopen(name,"w");

    srand(seed);

    memset(buffer, 0, strlen(buffer));

    while (cur != EOF) {
        result = 0;
        cur = fgetc(fp);
        work = cur;

        //To keep the random character an ASCII character
        while ((num >= 0) && (num <= 31)) {
            num = abs(rand() % 256);
        }

        work = cur ^ num;
        result = fputc(work, out);
        if (result==EOF) { printf("Printing to file failed.\n"); exit(1); }
    }; 

    fclose(fp);
    fclose(out);  
}