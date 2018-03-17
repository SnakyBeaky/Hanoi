#include "Global.h"

Movement* Historial;

void InitializeMovements()
{
	// Allocating memory for the first movement in the historial
	Historial = malloc(1 * sizeof(Movement));
}

void DisplayMovement(int movement)
{
	memcpy(&Towers, &Historial[movement - 1].Towers, sizeof(Tower[3]));

	printf("\n");
	printf(Historial[movement - 1].Message);

	DisplayTowers();
}

void AddMovement(char* message)
{
	// Reallocating the memory for the movement history to hold one more movement
	Historial = realloc(Historial, Moves * sizeof(Movement));

	// Getting last movement
	Movement* current = &Historial[Moves - 1];

	// Assigning message and move count
	current->Number = Moves;
	current->Depth = Depth;
	current->Message = malloc(128 * sizeof(char));
	memcpy(current->Message, message, 128 * sizeof(char));

	// Making copies of all towers
	for (int i = 0; i < TOWER_AMOUNT; i++)
	{
		current->Towers[i] = CopyTower(&Towers[i]);
	}

	// Defining pointers to previous and next movements
	current->Previous = &Historial[Moves - 2];
	current->Next = NULL;

	// Defining pointer on the previous movement to this movement
	current->Previous->Next = current;
}

Tower CopyTower(Tower* original)
{
	// Creating a new Tower struct
	Tower copy;

	// Copying Height and Role from original tower
	copy.Height = original->Height;
	copy.Role = original->Role;

	// Allocating memory for the array of levels
	copy.Levels = malloc(Discs * sizeof(int));

	// Copying tower levels from the original tower
	for (int i = 0; i < original->Height; i++)
	{
		copy.Levels[i] = original->Levels[i];
	}

	return copy;
}