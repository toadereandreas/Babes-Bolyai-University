#ifndef LAB3_4_REPOSITORY_H
#define LAB3_4_REPOSITORY_H

#include "Domain.h"
#include <stdlib.h>

typedef Country TElem;
typedef struct{
    int length;
    int capacity;
    TElem *array;
}Repository;

// This function creates an array of elements of the type country.
Repository create_repository( int capacity );

// This function deallocate the memory used by the repo.
void destroy_repository( Repository repo );

// This function prints the elements in the repository.
char *str_repository(Repository repo, char *str );

char *display_repository(Repository repo, char *str, char *string);

//This function adds an element of the type country to an array.
int add( Repository *repo, TElem new_Element);

//This function removes an element of the type country from an array.
int remove_element( Repository *repo, TElem element);

//This function updates an element of the type country
int update_element( Repository *repo, TElem element);

//This function performs the migration from countr_from to country_to.
int update_migration( Repository *repo, char *country_from, char *country_to, int migrators) ;

// This function returns a string containing all countries from repository that meet the given conditions.
char *filter_repository(Repository repo, char *str, char *continent, int minimum_population);

char *sort_repository(Repository repo, char *str, char *continent);
#endif //LAB3_4_REPOSITORY_H