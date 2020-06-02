#include "UI.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

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
	printf("3 - undo.\n");
	printf("0 - to exit.\n");
	printf("\n**********************************************************\n");
}

/*
	Verifies if the given command is valid (is either 1, 2, 3or 0)
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

/*
	Reads a string with spaces from the standard input.
	Input:	message - string, message to be shown to the user.
			maxStrSize - the maximum size for the string to be read
	Output: the string that was read.
*/
void readStringWithSpaces(const char* message, int maxStrSize, char str[])
{
	printf(message);
	fgets(str, maxStrSize, stdin);
	// the newline is also read so we must eliminate it from the string
	size_t size = strlen(str) - 1;
	if (str[size] == '\n')
		str[size] = '\0';
}

int addPlanetUI(UI* ui)
{
	// read the planet's data
	char name[50], type[50];
	double distanceFromEarth;
	
	fgetc(stdin); // read the newline, to prevent it from going further to fgets
	readStringWithSpaces("Please input the name: ", 50, name);
	readStringWithSpaces("Please input the solar system: ", 50, type);
	printf("Please input the distance to Earth (in thousands of light years): ");
	scanf("%lf", &distanceFromEarth);

	return addPlanetCtrl(ui->ctrl, name, type, distanceFromEarth);
}

void listAllPlanets(UI* ui)
{
	PlanetRepo* repo = getRepo(ui->ctrl);
	int length = getRepoLength(repo);

	// TODO
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
				printf("Error! Planet could not be added, as there is another planet with the same symbol combination!\n");
			break;
		}
		case 2:
		{
			listAllPlanets(ui);
			break;
		}
		case 3:
		{
			int res = undo(ui->ctrl);
			if (res == 1)
				printf("Undo was successful.\n");
			else
				printf("No more undos to be made.\n");
			break;
		}
		}
	}
}