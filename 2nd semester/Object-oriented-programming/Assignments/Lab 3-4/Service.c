#include "Service.h"
Controller create_controller( Repository *repo ){
    Controller controller;
    controller.repo = repo ;
    return controller ;
}

int add_country( Controller *controller, char *name, char *continent, int population ){
    /* This is the service method, which creates an country and adds it to the repository. */
    char *country_name, *country_continent ;
    country_name = (char*)malloc((strlen(name) + 1 ) * sizeof(char) );
    country_continent = (char*)malloc((strlen(continent) + 1 ) * sizeof(char) );
    strcpy(country_name,name);
    strcpy(country_continent,continent);
    Country new_Country = create_country(country_name,country_continent,population);
    int effect = add(controller->repo, new_Country);// Effect is 1 if the country was added 0 otherwise.
    return effect ;
}

char *str_controller(Controller controller, char *str ){
    return str_repository(*(controller.repo), str);
}

char *filter_controller( Controller controller,char *str,char *continent, int minimum_population){
    return filter_repository(*(controller.repo),str,continent,minimum_population);
}

char* sort_controller( Controller controller, char *str, char *continent ){
    return sort_repository(*(controller.repo),str,continent);
}

char* display_controller( Controller controller, char *str, char *string){
    return display_repository(*(controller.repo),str,string);
}

int remove_country( Controller *controller, char *name ){
    /* This is the service method, which creates an country and removes it to the repository. */
    Country fake_Country = create_country(name,"",0);// Fake country, we identify a country by its name.
    return remove_element(controller->repo,fake_Country);
}

int update_country( Controller *controller, char *name, int new_population){
    /* This is the service method, which creates an country and updates its data to the repository. */
    char *new_name;
    new_name = (char*)malloc(sizeof(char) * strlen(name) + 1 );
    strcpy(new_name,name) ;
    Country updated_Country = create_country(new_name,"", new_population);
    int result ;
    result = update_element(controller->repo, updated_Country);
    return result ;
}
int migrate( Controller *controller, char *country_from, char *country_to, int migrators){
    // This method performs a migration from a country to another
    return update_migration(controller->repo,country_from,country_to,migrators);
}

void destroy_repository_controller( Controller controller ){
    //destroy_repository(*(controller.repo));
}