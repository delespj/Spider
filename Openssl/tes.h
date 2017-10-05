#ifndef CRYPTO_EXAMPLE_H
#define CRYPTO_EXAMPLE_H

#include <stdio.h>
#include <iostream>
#include <string>


#include "crypt.h"

//#define PRINT_KEYS

void encryptAes(Crypt *crypt);
void printKeys(Crypt *crypt);
std::string getMessage(const char *prompt);

#endif
