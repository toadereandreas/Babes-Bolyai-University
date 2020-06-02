#ifndef LAB3_4_DOMAIN_H
#define LAB3_4_DOMAIN_H

typedef struct{
    char *name ;
    char *continent ;
    int population ;
}Country;

// This function is the constructor of the data type Country.
Country create_country( char *name, char*continent, int population);

// This function returns a string that represents the country.
char *country_string( Country country );

//This function checks whether 2 countries are the same.
int equals( Country country1, Country country2 );
#endif //LAB3_4_DOMAIN_H