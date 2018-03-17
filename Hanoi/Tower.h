#ifndef TOWER_HEADER
#define TOWER_HEADER

/* Role Type */

typedef int Role;

#define ROLE_START 0
#define ROLE_TARGET 1
#define ROLE_AUXILIAR 2

/* Tower Type */
typedef struct Tower {
	int Height;
	Role Role;
	int* Levels;
} Tower;

#endif