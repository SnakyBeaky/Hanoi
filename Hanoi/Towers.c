#include "Global.h"

Tower Towers[TOWER_AMOUNT];

void InitializeTowers(int start, int target, int auxiliar)
{
	// Assigning roles to all towers
	Towers[start].Role = ROLE_START;
	Towers[target].Role = ROLE_TARGET;
	Towers[auxiliar].Role = ROLE_AUXILIAR;

	// Iterating on the amount of towers
	for (int i = 0; i < TOWER_AMOUNT; i++)
	{
		// Assigning tower height
		Towers[i].Height = Discs;

		// Allocating memory for the int array to hold all tower levels
		Towers[i].Levels = malloc(Discs * sizeof(int));

		// Iterating on the tower height
		for (int j = 0; j < Discs; j++)
		{
			// Checking if the current tower is the starting tower
			if (Towers[i].Role == ROLE_START)
			{
				// Filling the starting tower with discs
				Towers[i].Levels[j] = Discs - j;
			}
			else
			{
				// Setting whole tower as empty
				Towers[i].Levels[j] = 0;
			}
		}
	}
}

int GetTopLevel(int tower)
{
	// Iterating on the tower height (reversed order to search from top to bottom)
	for (int i = Discs - 1; i >= 0; i--)
	{
		// Checking if the current tower level is not empty
		if (Towers[tower].Levels[i] != 0)
		{
			// Returning the current level
			return i;
		}
	}

	// Whole tower is empty, returning -1
	return -1;
}

int GetTopDisc(int tower)
{
	// Getting the top non-empty level of the specified tower
	int topLevel = GetTopLevel(tower);

	// Checking if the tower is not empty
	if (topLevel >= 0)
	{
		// Returning the disc size on the top level
		return Towers[tower].Levels[topLevel];
	}

	// Whole tower is empty, returning -1
	return -1;
}

void MoveTopDisc(int origin, int destiny)
{
	// Getting the size of the disc that will be moved
	int originTopDisc = GetTopDisc(origin);

	// Getting origin and destination heights
	int originTopLevel = GetTopLevel(origin);
	int destinationLevel = GetTopLevel(destiny) + 1;

	// Adding 1 to the move counter
	Moves++;

	// Checking if destination tower is empty
	if (destinationLevel < 0)
	{
		// Moving disc to the bottom level
		destinationLevel = 0;
	}

	// Removing the disc from the origin tower and adding it to the destination tower
	Towers[origin].Levels[originTopLevel] = 0;
	Towers[destiny].Levels[destinationLevel] = originTopDisc;

	// Printing movement message
	char infoString[128];
	sprintf(infoString, "(Move %d) (Depth %d) Moving disc D%d from T%d to T%d\n", Moves, Depth, originTopDisc, origin, destiny);
	PrintMessage(infoString);

	// Printing towers status
	DisplayTowers();

	// Adding current movement to the list
	AddMovement(infoString);
}