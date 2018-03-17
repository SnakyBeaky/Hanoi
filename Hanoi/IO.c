#include "Global.h"

FILE* File = NULL;

void PrintMessage(char* message)
{
	// Checking if the output type is File or Console
	if (File == NULL)
	{
		// Output type is console, printing message to console
		printf(message);
	}
	else
	{
		// Output type is file, appending message to specified file
		fputs(message, File);
	}
}

void DisplayTowers()
{
	// Defining char array to store messages for printing on console or file
	char str[1024];

	// Iterating on the max disc size
	for (int level = Discs - 1; level >= 0; level--)
	{
		// Printing height level
		sprintf(str, "H%d  ", level);

		// Adding an empty space if the height level occuppies 1 char only (from 0 to 9)
		if (level < 10)
		{
			strcat(str, " ");
		}
		
		PrintMessage(str);
		
		// Iterating on the amount of towers
		for (int t = 0; t < TOWER_AMOUNT; t++)
		{
			// Getting current level disc size in the current tower
			int discSize = Towers[t].Levels[level];

			// Calculating the amount of points (empty spaces) to print
			int points = Discs - discSize;

			// Iterating on the disc size to print the LEFT side of the tower
			for (int left = 0; left < Discs; left++)
			{
				// Checking if the current position is an empty space
				if (left < points)
				{
					// Printing an empty space (point)
					PrintMessage(".");
				}
				else
				{
					// Printing a letter according to the disc size (A = 0, B = 1, etc...)
					sprintf(str, "%c", discSize + 64);
					PrintMessage(str);
				}
			}

			// Printing the tower center
			PrintMessage("|");

			// Iterating on the disc size to print the RIGHT side of the tower (reversed loop order to mirror the tower)
			for (int right = Discs - 1; right >= 0; right--)
			{
				// Checking if the current position is an empty space
				if (right < points)
				{
					// Printing an empty space (point)
					PrintMessage(".");
				}
				else
				{
					// Printing a letter according to the disc size (A = 0, B = 1, etc...)
					sprintf(str, "%c", discSize + 64);
					PrintMessage(str);
				}
			}

			// Printing a spacer to separate towers
			PrintMessage("  ");
		}

		PrintMessage("\n");
	}


	/* Printing bottom line (connects all towers and ends the current movement) */

	// Printing empty spaces to match the start of the towers
	PrintMessage("     ");

	// Calculating the amount of lines required to fill up all towers
	int towerLength = (Discs * 2) + 1;
	int fullLength = (towerLength * TOWER_AMOUNT) + TOWER_AMOUNT + 1;
	
	// Iterating on the amount of lines required
	for (int i = 0; i < fullLength; i++)
	{
		PrintMessage("-");
	}

	PrintMessage("\n\n");
}