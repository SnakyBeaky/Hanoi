#ifndef HISTORIAL_HEADER
#define HISTORIAL_HEADER

#include "Global.h"

// Initializes the movement list.
void InitializeMovements();

/* Displays a movement on console.
	int movement : Movement to display
*/
void DisplayMovement(int movement);

/* Adds the current movement to the history.
	char* message : Pointer to the movement message
*/
void AddMovement(char* message);

/* Makes an exact copy of a tower.
	Tower* original : Pointer to the original tower to be copied

	Returns a pointer to the copy.
*/
Tower CopyTower(Tower* original);

#endif