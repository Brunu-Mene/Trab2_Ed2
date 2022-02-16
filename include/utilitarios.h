#ifndef UTILITARIOS_H
#define UTILITARIOS_H

#include "../include/str.h"
//#include "../suffix/str.h"
//#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>

String* le_arquivo(char *adress);
FILE *abreArquivo(char *adress);
void merge_string();

#endif