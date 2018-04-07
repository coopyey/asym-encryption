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
    if (fp==NULL) { printf("\nFile %s not found!\n",name); return; }
    
    char *temp;    
    temp = (char*) malloc (strlen(buffer));
    temp = strtok(buffer, ".");

    result =  sprintf(name, "textfiles/c_%s.txt", temp);
    if (result==0) { printf("\nFile output naming failed.\n"); return; }

    FILE *out;
    out = fopen(name,"w");

    srand(seed);

    while (cur != EOF) {
        result = 0;
        cur = fgetc(fp);
        work = cur;

        //To keep the random character an ASCII character
        while ((num >= 0) && (num <= 31)) {
            num = abs(rand() % 256);
        }

        work = cur ^ num;
        result = putc(work, out);
        if (result==EOF) { printf("\nPrinting to file failed.\n"); return; }
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
    if (fp==NULL) { printf("\nFile %s not found!\n",name); return; }
    
    char *temp;    
    temp = (char*) malloc (strlen(buffer));
    temp = strtok(buffer, ".");

    result =  sprintf(name, "textfiles/p_%s.txt", temp);
    if (result==0) { printf("\nFile output naming failed.\n"); return; }

    FILE *out;
    out = fopen(name,"w");

    srand(seed);

    while (cur != EOF) {
        result = 0;
        cur = fgetc(fp);
        work = cur;

        //To keep the random character an ASCII character
        while ((num >= 0) && (num <= 31)) {
            num = abs(rand() % 256);
        }

        result = putc(work, out);
        if (result==EOF) { printf("\nPrinting to file failed.\n"); return; }
    }; 
    fclose(fp);
    fclose(out);  
}