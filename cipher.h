#ifndef _CIPHER_H_
#define _CIPHER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *buffer, int seed);
void decrypt(char *buffer, int seed);

#endif