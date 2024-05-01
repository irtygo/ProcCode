// (c) Copyright 2024 IrtyGo
// Codename ProcCode
// Version 0.2.0.0
// Descrption: Additonal String Commands
// Licenced under the GPL version 3.0, See LICENSE
#include <stdio.h>
#include <string.h>

char* AppendToNewString(char* str1, char* str2) {

char * res;
res = malloc(sizeof(char)*100);
sprintf(res, "%s%s", str1, str2);
return res;
}

char* AppendToNewStringS(char* str1, char* str2) {

char * res;
res = malloc(sizeof(char)*100);
sprintf(res, "%s %s", str1, str2);
return res;
}
