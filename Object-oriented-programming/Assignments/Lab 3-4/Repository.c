#include "Repository.h"
#include <string.h>

Repository create_repository( int capacity )
{   /* This is the constructor method.
    * This function initializes the repository then returns it.
    * Input : capacity, an integer.
    * Output: repo, a repository. */
    Repository repo;
    repo.length = 0 ;
    repo.capacity = capacity ;
    repo.array = (TElem*)malloc(capacity * sizeof(TElem)) ;
    return repo ;
}

char *str_repository(Repository repo, char *str ){
   /* This function returns a string containing all the countries in the repository.
    * Input : str, empty string
    * Output: result, a string with all the countries in the repository. */
    char *result, *auxiliary ;
    result = (char*)malloc(sizeof(char) * 50 * repo.length );
    auxiliary = (char*)malloc(sizeof(char) * 50);
    memset(result, 0, sizeof(result));
    for( int position = 0 ; position < repo.length ; ++position ){
        if( strlen(str) == 0 || strstr(repo.array[position].name, str) != NULL || strstr(repo.array[position].continent, str) != NULL ){
            auxiliary = country_string(repo.array[position]) ;
            strcat(result,auxiliary);
        }
    }
    free(auxiliary);
    return result;
}

char *filter_repository(Repository repo, char *str, char *continent, int minimum_population){
    /* This function filters the repository by a given continent and a minimum population.
     * Input : repo, a repository
     *         continent, the given continent
     *         minimum_population, an integer
     * Output: result, a string having the countries in the given continent with a minimum population. */
    char *result, *auxiliary ;
    result = (char*)malloc(sizeof(char) * 50 * repo.length );
    auxiliary = (char*)malloc(sizeof(char) * 50);
    memset(result, 0, sizeof(result));
    for( int position = 0 ; position < repo.length ; ++position ){
        if(strlen(str) == 0 || strstr(repo.array[position].name, str) != NULL || strstr(repo.array[position].continent, str) != NULL )
        {
            if( strcmp(repo.array[position].continent,continent) == 0 && repo.array[position].population > minimum_population ) {
                auxiliary = country_string(repo.array[position]);
                strcat(result, auxiliary);
            }
        }
    }
    free(auxiliary);
    return result;
}

char *display_repository(Repository repo, char *str, char *string){
    char *result, *auxiliary ;
    result = (char*)malloc(sizeof(char) * 50 * repo.length );
    auxiliary = (char*)malloc(sizeof(char) * 50);
    memset(result, 0, sizeof(result));
    for( int position = 0 ; position < repo.length ; ++position ){
        if( strlen(str) == 0 || strstr(repo.array[position].name, str) != NULL || strstr(repo.array[position].continent, str) != NULL ){
            if( strstr(repo.array[position].name,string) != NULL ) {
                auxiliary = country_string(repo.array[position]);
                strcat(result, auxiliary);
            }
        }
    }
    free(auxiliary);
    return result;
}

char *sort_repository(Repository repo, char *str, char *continent){
    char *result, *auxiliary, array_sort[100][100] ;
    int sort_array_position = 0 ;
    for( int position = 0; position < 100 ; ++ position )
        strcpy(array_sort[position],"");
    result = (char*)malloc(sizeof(char) * 50 * repo.length );
    auxiliary = (char*)malloc(sizeof(char) * 50);
    memset(result, 0, sizeof(result));

    for( int position = 0 ; position < repo.length ; ++position ){
            if( strcmp(repo.array[position].continent,continent) == 0 ) {
                auxiliary = country_string(repo.array[position]);
                strcpy(array_sort[sort_array_position++],auxiliary);
            }
    }
    for( int i = 0 ; i < sort_array_position - 1 ; ++i )
        for( int j = i + 1 ; j < sort_array_position ; ++j )
            if( strcmp(array_sort[i],array_sort[j]) > 0 )
            {
                strcpy(auxiliary,array_sort[i]);
                strcpy(array_sort[i],array_sort[j]);
                strcpy(array_sort[j],auxiliary);
            }
    for( int i = 0 ; i < sort_array_position ; ++i )
        strcat(result,array_sort[i]);
    free(auxiliary);
    return result;
}

void destroy_repository( Repository repo ){
    /* This is the destructor method.
     * This function frees all the memory that the repository used.
     * Input : repo, a repository.
     * Output: -. */
    for( int position = 0; position < repo.length  ; ++position )
    {// Frees the elements of the array.
        free(repo.array[position].name);
        free(repo.array[position].continent);
    }
    free(repo.array);// Frees the array.
}

int add( Repository *repo, TElem new_Element )
{  /* This is the add feature of the repository.
    *  This function adds an element to the repository.
    *  If there is no more space for the element in the repository,
    *  it will reconstruct the repository and double its capacity.
    *  Input: repo, the repository
    *         new_Element, the new element that should be added to the repository.
    *  Output : 0, if the element already existed in the repository.
    *           1, if the element was successfully added in the repository. */
    if( repo->length + 1 == repo->capacity )
    {// If the repository reached its maximum capacity.
        Country * new_Array = (TElem*)malloc((2 * repo->capacity) * sizeof(TElem));
        for( int position = 0 ; position < repo->length ; ++position )
            new_Array[position] = repo->array[position] ;
        repo->capacity *= 2 ;
        for( int position = 0; position < repo->length ; ++position )
        {// Frees the old array's elements.
            free(repo->array[position].name);
            free(repo->array[position].continent);
        }
        free(repo->array) ;
        repo->array = new_Array ;// The new array becomes the main array in the repository.
    }
    for( int position = 0 ; position < repo->length ; ++position )
        if( equals(repo->array[position],new_Element) )
            return 0;// The new element was already in the repository.
    repo->length += 1 ;
    repo->array[repo->length-1] = new_Element ;
    return 1;// The new element was successfully added.
}

int remove_element( Repository *repo, TElem element )
{  /* This function removes an element.
    * Firstly, it searches the element in the repository, then it frees the memory.
    * After the memory was freed, it overlaps all the elements that are on the right,
    * and then decrements the length.
    * Input : repo, the repository
    *         element, the country that needs to be removed
    * Output : 1, if the country was removed
    *          0, otherwise */
    for( int i = 0; i < repo->length ; ++i ) // Search for element
        if( equals(repo->array[i],element) )
        {
            free(repo->array[i].name);
            free(repo->array[i].continent);
            for( int j = i ; j < repo->length - 1 ; ++j )
                repo->array[j] = repo->array[j+1];
            repo->length -= 1;
            return 1;// The element was removed.
        }
    return 0;// The element was not removed.
}

int update_element( Repository *repo, TElem element){
    /* This function updates the population of a country.
     * Input : element, the country with the new population.
     *         repo, the repository
     * Output: 1, if the country's population was updated
     *         0, otherwise */
    for( int i = 0; i < repo->length ; ++i ){
        if( strcmp(repo->array[i].name,element.name) == 0 ){
            repo->array[i].population = element.population;
            return 1;
        }
    }
    return 0;
}

int update_migration( Repository *repo, char *country_from, char *country_to, int migrators){
    /* This function updates the population after a migration.
     * It decreases the country_from's population by the number of immigrants.
     * It increases the country_to's population by the number of immigrants.
     * Input: repo, the repository
     *        country_from, the name of the country which the population left
     *        country_to, where the population went
     *        migrators, the number of immigrants that left.
     * Output: 1, if the data was updated accordingly
     *         0, otherwise */
    int gone = 0, arrived = 0;
    for( int i = 0; i < repo->length ; ++i ){
        if( strcmp(repo->array[i].name,country_from) == 0 ){
            repo->array[i].population -= migrators ;
            gone = 1;
        }
        if( strcmp(repo->array[i].name,country_to) == 0 ){
            repo->array[i].population += migrators ;
            arrived = 1;
        }
    }
    if( gone == 1 && arrived == 1 )
        return 1;
    return 0;
}