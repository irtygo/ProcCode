// (c) Copyright 2024 IrtyGo
// Codename ProcCode
// Version 0.2.0.3
// Descrption: File Operations
// Licenced under the GPL version 3.0, See LICENSE
// Updated by IrtyGo on 05/10/2024


int CheckIfFileExists(char* fname)
{
    FILE *file;
    if ((file = fopen(fname, "r")))
    {
        fclose(file);
        return 1;
    }
    return 0;
}


/* If a file does not exist, then create it.
   If the file does exist, then overwrite it completly.  */
FILE* CreateOrOverwriteFile(char* filename) {

// Create the pointer var for the file

FILE *fptr;

// Actually open/create the file

fptr = fopen(filename, "w");

// Give the caller the pointer.

return fptr;

}


/* Open a file in append data mode.  */
FILE* AppendDataToFile(char* filename) {

// Create the pointer var for the file 

FILE *fptr;

// Actually open the file.

fptr = fopen(filename, "a");

// Give the caller the pointer

return fptr;

}

/* Open a file in read only mode.  */
FILE* ReadFromFile(char* filename) {
// Create the pointer var for the file

FILE *fptr;

// Actually open the file.

fptr = fopen(filename, "r");

// Give the caller the pointer
return fptr;
}



