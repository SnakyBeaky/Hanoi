#ifndef IO_HEADER
#define IO_HEADER

#include "Global.h"

// Pointer to the destination file, NULL if output is console
extern FILE* File;

/* Print a message to the specified output (console or file).
	char* message : Message to print
*/
void PrintMessage(char* message);

// Print the status of all towers
void DisplayTowers();

#endif