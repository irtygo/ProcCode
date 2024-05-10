// (c) Copyright 2024 IrtyGo
// Codename ProcCode
// Version 0.2.0.3
// Descrption: Main C file
// Licenced under the GPL version 3.0, See LICENSE
// Updated by IrtyGo on 05/10/2024
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fileop.h"
#include "addstr.h"

struct cmd {

char* help;
char* fnf;
char* help2;
char* version;

};

struct regmode {

char* log;
char* print;

};


int main (int argc, char* argv[]) {


struct cmd cmd;
struct regmode regmode;

cmd.help = "HELP\n\
%s\n\
--version Show version info\n\
--help Show help info\n\
-print filename Run the selected program/command and print out the exit code afterwards.\n\
-log filename Run the selected program/command and save the exit code to a file.\n\
To run a program/command with more than one argument, put the the argument in quotes with the first argument.\n\
eg.\n\
proccode -print ls \"/home/work -a\"\n\
proccode -log cat 'important.txt coolgamesource.c'\n";
cmd.version = "Proccode Version 0.2.0.3\nCopyright 2024 IrtyGo.\nLicensed with GPL 3.0\nTHERE IS ABSOLUTELY NO WARRANTY.\n";
cmd.fnf = "Error: File not found.\n";
regmode.log = "-log";
regmode.print = "-print";
char *callline = argv[0];
char *modea = argv[1];
char *file = argv[2];
char *progarg = argv[3];
int mode;
//strcat(cmd.help1, cmd.help2);

// check if any other strings are null, if so throw an exeption.
if (cmd.help == 0 || cmd.version == 0 || cmd.fnf == 0 || regmode.log == 0 || regmode.print == 0) {
printf("An exeption has occurred.\n");
exit(1);
}


// check if mode is null.
if (modea == 0) {
printf("No mode specified. Try --help.\n");
// We need to give an exitcode too.
exit(22);
}



// Compare mode to known values if not null
int help = strcmp(modea, "--help");
int version = strcmp(modea, "--version");
int print = strcmp(modea, regmode.print);
int log = strcmp(modea, regmode.log);

if (print == 0) {
mode = 1;
} 
if (log == 0) {
mode = 2;
}

// check if filename is null
if (file == 0 && !version == 0 && !help == 0) {
printf("No filename specified\n Try --help.\n");
// We need to give an exit code too.
exit(22);
}

if (help == 0) {
// Display help info.
printf(cmd.help, cmd.version);
// We need to give an exit code too
exit(0);
}

if (version == 0) {
printf("%s", cmd.version);
// We need to give an exit code too.
return 0;
}

int exists = 1;

switch (mode) {

case 1:
if (!progarg == 0) {

char* filearg = AppendToNewStringS(file, progarg);
int status = system(filearg);
printf("Exit code is %d.\n", status);
// Give the same exit code as the anlaysed program.
exit(status);

} else {

//char* filearg = AppendToNewString(file, progarg);
int status = system(file);
printf("Exit code is %d.\n", status);
// Give the same exit code as the anlaysed program.
exit(status);

}

case 2:

if (!progarg == 0) {
char* filearg = AppendToNewStringS(file, progarg);
int status = system(filearg);
//char* filelog = file;
char* filelog = AppendToNewString(file, ".log");
int logexist = CheckIfFileExists(filelog);
if (logexist == 1) {
FILE* pntr = AppendDataToFile(filelog);
fprintf(pntr, "Exit code is %d.\n", status);
fclose(pntr);
} else {
FILE* pntr = CreateOrOverwriteFile(filelog);
fprintf(pntr, "Exit code is %d.\n", status);
fclose(pntr);
}
// Give the same exit code as the anlaysed program.
exit(status);
} else {

int status = system(file);
//char* filelog = file;
char* filelog = AppendToNewString(file, ".log");
int logexist = CheckIfFileExists(filelog);
if (logexist == 1) {
FILE* pntr = AppendDataToFile(filelog);
fprintf(pntr, "Exit code is %d.\n", status);
fclose(pntr);
} else {
FILE* pntr = CreateOrOverwriteFile(filelog);
fprintf(pntr, "Exit code is %d.\n", status);
fclose(pntr);
}
// Give the same exit code as the anlaysed program.

exit(status);
}
break;



default:
printf("Non null unregonized mode value.\n");
break;

}

// We need to give an exit code too.
return 0;
}


