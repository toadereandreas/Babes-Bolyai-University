#include "UI.h"
#include <stdio.h>
#include <stdlib.h>

UI* createUI(Controller* c)
{
	UI* ui = (UI*)malloc(sizeof(UI));
	ui->ctrl = c;

	return ui;
}

void destroyUI(UI * ui)
{
	// first destroy the controller
	destroyController(ui->ctrl);
	// free the UI memory
	free(ui);
}

/*
	Prints the available menu for the problem
	Input: -
	Output: the menu is printed at the console
*/
void printMenu()
{
	printf("\n**********************************************************\n");
	printf("1 - add a planet.\n");
	printf("2 - list all planets.\n");
	printf("3 - list planets with a given type.\n");
	printf("0 - to exit.\n");
	printf("\**********************************************************\n");
}

/*
	Verifies if the given command is valid (is either 1, 2 or 0)
	Input: command - integer
	Output: 1 - if the command is valid
	0 - otherwise
*/
int validCommand(int command)
{
	if (command >= 0 && command <= 3)
		return 1;
	return 0;
}

/*
	Reads an integer number from the keyboard. Asks for number while read errors encoutered.
	Input: the message to be displayed when asking the user for input.
	Returns the number.
*/
int readIntegerNumber(const char* message)
{
	char s[16];
	int res = 0;
	int flag = 0;
	int r = 0;

	while (flag == 0)
	{
		printf(message);
		scanf("%s", s);

		r = sscanf(s, "%d", &res);	// reads data from s and stores them as integer, if possible; returns 1 if successful
		flag = (r == 1);
		if (flag == 0)
			printf("Error reading number!\n");
	}
	return res;
}

int addPlanetUI(UI* ui)
{
	// read the planet's data
	char name[50], type[50];
	double distanceFromEarth = 0;
	
	printf("Please input the name: ");
	scanf("%49s", name);
	printf("Please input the type: ");
	scanf("%49s", type);
	printf("Please input the distance from Earth (in light years): ");
	scanf("%lf", &distanceFromEarth);

	return addPlanet(ui->ctrl, name, type, distanceFromEarth);
}

void listAllPlanets(UI* ui)
{
	// TODO
}

void listPlanetsByType(UI* ui)
{
	char symbols[8];
	printf("Please input the symbol combination (must contain maximum 7 symbols); input 'null' for no symbol combination: ");
	scanf("%7s", symbols);

	PlanetRepo* res = filterByType(ui->ctrl, symbols);
	// List the result - TODO
	
	// now we must destroy the repository that was created for this operation
	destroyRepo(res);
}

void startUI(UI* ui)
{
	while (1)
	{
		printMenu();
		int command = readIntegerNumber("Input command: ");
		while (validCommand(command) == 0)
		{
			printf("Please input a valid command!\n");
			command = readIntegerNumber("Input command: ");
		}
		if (command == 0)
			break;
		switch (command)
		{
		case 1:
		{
			int res = addPlanetUI(ui);
			if (res == 1)
				printf("Planet successfully added.\n");
			else
				printf("Error! Planet could not be added, as there is another planet with the same name!\n");
			break;
		}
		case 2:
		{
			listAllPlanets(ui);
			break;
		}
		case 3:
		{
			listPlanetsByType(ui);
			break;
		}
		}
	}
}