#include <string.h>
#include <corecrt_malloc.h>
#include "Domain.h"
#include <stdlib.h>

Country create_country( char *name, char *continent, int population){
    Country country ;
    country.name = name ;
    country.continent = continent ;
    country.population = population ;
    return country ;
}

char *country_string( Country country ){
    /* This function returns a string that contains a country.
     * Input : country, the country
     * Output: str, the string with the country */
    char *str ;
    char *string_population ;
    str = (char*)malloc(sizeof(char) * 50);
    string_population = (char*)malloc(sizeof(char) * 15);
    memset(str, 0, sizeof(str)) ;
    strcpy(str, country.name );
    strcat(str, " ");
    strcat(str, country.continent );
    strcat(str, " ");
    itoa(country.population,string_population,10);
    strcat(str,string_population);
    strcat(str, "\n\0");
    free(string_population);
    return str;
}

int equals( Country country1, Country country2 )
{  /* This function checks whether 2 countries are the same.
    * Input : country1 and country2, the two countries that are compared.
    * Output: 1, if they are the same.
    *         0, otherwise. */
    if( strcmp(country1.name,country2.name) == 0  )
        return 1;
    return 0;
}