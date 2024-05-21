// (c) Copyright 2024 IrtyGo
// Codename ProcCode
// Version 0.2.1
// Descrption: Additonal String Commands
// Licenced under the GPL version 3.0, See LICENSE
// Updated by IrtyGo on 10/05/2024-21/05/2024

#include <stdio.h>
#include <string.h>

char* AppendToNewString(char* str1, char* str2) {

char * res;
res = malloc(sizeof(char)*2048);
sprintf(res, "%s%s", str1, str2);
return res;
}

char* AppendToNewStringS(char* str1, char* str2) {

char * res;
res = malloc(sizeof(char)*2048);
sprintf(res, "%s %s", str1, str2);
return res;
}
