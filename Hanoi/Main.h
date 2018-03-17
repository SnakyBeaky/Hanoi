#ifndef MAIN_HEADER
#define MAIN_HEADER

#include "Global.h"

/* FileMode Type */

typedef char* FileMode;

#define FILEMODE_APPEND "ap"
#define FILEMODE_CREATE "w"

/* Start Options */
extern int Discs;
extern char* FileName;
extern bool Print;
extern FileMode Mode;

extern int Moves;
extern int Depth;

/* Parameter related methods (loading and printing) */

void LoadParameters(int count, char** args);
void PrintStartParameters(int count, char** args);
void PrintEndParameters(int count, char** args);

/* Main recursive Hanoi algorithm.
	int amount : Amount of discs to move
	int origin : Origin tower
	int destiny : Destination tower
	int auxiliar : Auxiliar tower
*/
void Hanoi(int amount, int origin, int destiny, int auxiliar);

/* Starting point for the application.
	int argc : Amount of arguments in argv
	int argv : Command line splitted by spaces
*/
int main(int argc, char** argv);

#endif