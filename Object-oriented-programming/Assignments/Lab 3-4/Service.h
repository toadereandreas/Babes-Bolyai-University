#ifndef LAB3_4_SERVICE_H
#define LAB3_4_SERVICE_H

#include "Repository.h"
#include "string.h"

typedef struct{
    Repository *repo;
}Controller;

// This is the constructor.
Controller create_controller( Repository *repo );

// This function adds a country.
int add_country( Controller *controller, char *name, char *continent, int population );

// This function prints the repository.
char *str_controller(Controller controller, char *str );

// This function removes a country.
int remove_country( Controller *controller, char *name );

// This function updates a country identified by its name.
int update_country( Controller *controller, char *name, int new_population);

// This function performs a migration from one country to another.
int migrate( Controller *controller, char *country_from, char *country_to, int migrators);

// This function calls the destructor of the repository.
void destroy_repository_controller( Controller controller );

// This function filters the repository by continent and minimum population.
char *filter_controller( Controller controller,char *str,char *continent, int minimum_population) ;

// This function displays all the countries that have the same given string in their name.
char* display_controller( Controller controller, char *str, char *string);

// This function returns a string having the countries from a continent sorted asc by name.
char* sort_controller( Controller controller, char *str, char *continent );
#endif //LAB3_4_SERVICE_H
