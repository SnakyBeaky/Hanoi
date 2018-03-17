#include "Global.h"

int Discs = 4;
char* FileName = NULL;
bool Print = TRUE;
FileMode Mode = FILEMODE_APPEND;

int Moves = 0;
int Depth = 0;

void Hanoi(int amount, int origin, int destination, int auxiliar)
{
	Depth++;

	if (amount == 1)
	{
		MoveTopDisc(origin, destination);
	}
	else
	{
		Hanoi(amount - 1, origin, auxiliar, destination);
		MoveTopDisc(origin, destination);
		Hanoi(amount - 1, auxiliar, destination, origin);
	}

	Depth--;
}

void LoadParameters(int count, char** args)
{
	for (int i = 1; i < count; i++)
	{
		if (args[i][0] == '-' && i + 1 < count)
		{
			switch (args[i][1])
			{
			case 'd':
				Discs = atoi(args[i + 1]);

				if (Discs <= 0)
				{
					Discs = 4;
					printf("WARNING : Invalid discs parameter. Using default 4 discs.\n");
				}
				break;

			case 'f':
				FileName = args[i + 1];

				if (strlen(FileName) <= 0)
				{
					FileName = NULL;
					printf("WARNING : Invalid file name. Printing to console.\n");
				}
				break;

			case 'o':
				if (strcmp(args[i + 1], "ap") == 0)
				{
					Mode = FILEMODE_APPEND;
				}
				else if (strcmp(args[i + 1], "w") == 0)
				{
					Mode = FILEMODE_CREATE;
				}
				else
				{
					printf("WARNING : Invalid operation parameter. Using default 'ap' append mode.\n\n");
				}
				break;
			}

			i++;
		}
	}

	if (FileName != NULL)
	{
		char path[1024];
		getcwd(path, sizeof(path));

		strcat(path, "\\");
		strcat(path, FileName);
		strcat(path, ".txt");

		if (strcmp(Mode, FILEMODE_APPEND) == 0)
		{
			File = fopen(path, "a");
		}
		else
		{
			File = fopen(path, "r");

			if (File != NULL)
			{
				fclose(File);

				bool overwrite;
				printf("\nThe file already exists (%s).\nDo you want to overwrite the file ? (0 -> No, Else -> Yes) ", path);
				scanf("%d", &overwrite);
				getchar();

				if (overwrite == FALSE)
				{
					exit(0);
				}
			}

			File = fopen(path, "w");
		}

	}
}

void PrintStartParameters(int count, char** args)
{
	char message[1024];

	PrintMessage("==================== START PARAMETERS ===================\n");

	PrintMessage("Command Line Entered : ");

	for (int i = 0; i < count; i++)
	{
		PrintMessage(args[i]);
		PrintMessage(" ");
	}

	sprintf(message, "\nNumber of Towers : %d\n", TOWER_AMOUNT);
	PrintMessage(message);

	sprintf(message, "Number of Discs : %d\n", Discs);
	PrintMessage(message);

	if (File == NULL)
	{
		PrintMessage("Output Type : Console\n");
	}
	else
	{
		PrintMessage("Output Type : File\n");

		sprintf(message, "Output Filename : %s\n", FileName);
		PrintMessage(message);
	}

	sprintf(message, "File Operation : %s\n", Mode);
	PrintMessage(message);

	time_t rawtime;
	struct tm * timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);

	sprintf(message, "\nStart Time : %d/%d/%d %d:%d:%d\n", timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
	PrintMessage(message);

	PrintMessage("=========================================================\n\n");
}

void PrintEndParameters(int count, char** args)
{
	char message[1024];

	PrintMessage("=========================================================\n");
	
	sprintf(message, "Number of Towers : %d\n", TOWER_AMOUNT);
	PrintMessage(message);

	sprintf(message, "Number of Discs : %d\n", Discs);
	PrintMessage(message);

	if (File == NULL)
	{
		PrintMessage("Output Type : Console\n");
	}
	else
	{
		PrintMessage("Output Type : File\n");

		sprintf(message, "Output Filename : %s\n", FileName);
		PrintMessage(message);
	}

	sprintf(message, "File Operation : %s\n", Mode);
	PrintMessage(message);

	sprintf(message, "\nTotal Number of Moves : %d\n", Moves);
	PrintMessage(message);

	time_t rawtime;
	struct tm * timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);

	sprintf(message, "End Time : %d/%d/%d %d:%d:%d\n", timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
	PrintMessage(message);

	PrintMessage("=========================================================\n");
}

int main(int argc, char** argv)
{
	if (argc > 1)
	{
		LoadParameters(argc, argv);
	}

	PrintStartParameters(argc, argv);
	
	InitializeTowers(0, 1, 2);
	InitializeMovements();

	PrintMessage("Hanoi Tower - Starting State\n");
	DisplayTowers();

	Hanoi(Discs, 0, 1, 2);

	PrintEndParameters(argc, argv);

	// Closing file handle if any
	if (File != NULL)
	{
		fclose(File);
		File = NULL;
	}
	
	while (1)
	{
		int input;

		printf("\nInsert the movement to visualize (0 to exit) : ");
		scanf("%d", &input);
		getchar();

		if (input < 0)
		{
			printf("\nInvalid movement.");
		}
		else if (input == 0)
		{
			return 0;
		}
		else
		{
			if (input > Moves)
			{
				printf("\nMovement out of range.");
			}
			else
			{
				DisplayMovement(input);
			}
		}
	}

	return 0;
}
