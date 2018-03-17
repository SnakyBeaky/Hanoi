#ifndef MOVEMENT_HEADER
#define MOVEMENT_HEADER

#include "Global.h"
#include "Tower.h"

typedef struct Movement
{
	int Number;
	int Depth;
	char* Message;
	Tower Towers[TOWER_AMOUNT];

	struct Movement* Previous;
	struct Movement* Next;
} Movement;

#endif