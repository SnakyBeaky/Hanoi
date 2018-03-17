#ifndef LISTS_HEADER
#define LISTS_HEADER

#include "Global.h"

// Global Tower array
extern Tower Towers[TOWER_AMOUNT];

/* Initializes the global tower list.
	int start : Starting tower
	int target : Destination tower
	int auxiliar : Auxiliar tower
*/
void InitializeTowers(int start, int target, int auxiliar);


/* Gets the highest non-empty level of a tower.

	Returns -1 if the whole tower is empty.
*/
int GetTopLevel(int tower);

/* Gets the disc size of the highest non-empty level of a tower.

	Returns -1 if the whole tower is empty.	
*/
int GetTopDisc(int tower);

/* Moves the top disc from a tower to another one.
	int origin : Origin tower (where the disc is located)
	int destiny : Destination tower
*/
void MoveTopDisc(int origin, int destiny);


#endif