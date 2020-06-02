#include "UI.h"

Console create_console(Controller *controller){
    Console console ;
    console.controller = controller ;
    return console ;
}

void ui_help(){
    printf("The application has been implemented the following features:\n");
    printf("Add country => add country_name country_continent country_population.\n");
    printf("Exit => exit.\n");
    printf("Delete country => delete country_name.\n");
    printf("Update country => update country_name new_population.\n");
    printf("Migrate => migrate country_from country_to number_of_immigrants.\n");
    printf("Filter => filter country_continent country_minimum_population.\n");
}

void ui_add(Console *console, char **commands){
    int result, population ;
    population = atoi(commands[3]);
    result = add_country(console->controller, commands[1], commands[2], population) ;
    if( result == 0 )
        printf("The element was not added.\n");
    if( result == 1 )
        printf("The element was added.\n");
}

void ui_print(Console console){
    char *string ;
    string = str_controller(*(console.controller),"");
    printf("%s\n",string);
    free(string);
}

void ui_delete(Console *console, char **commands){
    int result ;
    result = remove_country(console->controller,commands[1]);
    if( result == 1 )
        printf("The element was successfully removed.\n");
    else
        printf("The element was not removed.\n");
}

void ui_update(Console *console, char **commands){
    int result, new_population;
    new_population = atoi(commands[2]);
    result = update_country(console->controller,commands[1],new_population);
    if( result == 1 )
        printf("The given country was updated.\n");
    else
        printf("The country was not updated.\n");
}

void ui_migrate(Console *console, char **commands){
    int migrators = atoi(commands[3]) ;
    int result ;
    result = migrate(console->controller,commands[1],commands[2],migrators);
    if( result == 1 )
        printf("The migration was successful.\n");
    else
        printf("The migration was not successful.\n");
}

void ui_filter( Console console, char **commands){
    char *continent = commands[1] ;
    int minimum_population = atoi(commands[2]);
    char *result = filter_controller(*(console.controller),"",continent,minimum_population);
    printf("%s\n",result);
}

void ui_display(Console console, char **commands){
    char *string = commands[1] ;
    char *result = display_controller(*(console.controller),"",string);
    printf("%s\n",result);
}

void ui_sort(Console console, char **commands){
    char *result = sort_controller(*(console.controller),"",commands[1]);
    printf("%s\n",result);
}

void start(Console *console){
    char **commands ;
    char *str, *word;
    int words, first_countries = 5;

    commands = (char**)malloc(20 * sizeof(char*));
    str = (char*)malloc(1000 * sizeof(char)) ;
    while(1){
        while( first_countries ) {
            if( first_countries == 1 ) add_country(console->controller, "Romania", "Europe", 21);
            if( first_countries == 2 ) add_country(console->controller, "China", "Asia", 1392);
            if( first_countries == 3 ) add_country(console->controller, "India", "Asia", 1288);
            if( first_countries == 4 ) add_country(console->controller, "USA", "NorthAmerica", 421);
            if( first_countries == 5 ) add_country(console->controller, "Pakistan", "Asia", 123);
            first_countries--;
        }
        printf("Insert command >> ");
        fgets(str,1000,stdin);

        for( int position = 0; position < 20 ; ++position )
            commands[position] = (char*)malloc(100 * sizeof(char));

        words = 0 ;// We need to reset word count for each command.
        word = strtok(str," \n\t");
        while( word != NULL ){
            strcpy(commands[words],word);// We copy the current word of the command in the command matrix.
            words += 1 ;
            word = strtok(NULL," \n\t") ;// We go to the next word of the command.
        }

        if( words == 1 && strcmp(commands[0],"help") == 0 )
            ui_help();
        else if( words == 1 && strcmp(commands[0],"exit") == 0 ) {
            for( int position = 0 ; position < 20 ; ++position )
                free(commands[position]);
            free(commands);
            free(str);
            destroy_repository_controller(*(console->controller));
            return;
        }
        else if( words == 3 && strcmp(commands[0],"filter") == 0 )
            ui_filter(*console,commands);
        else if( words == 2 && strcmp(commands[0],"display") == 0 )
            ui_display(*console,commands);
        else if( words == 2 && strcmp(commands[0],"sort") == 0 )
            ui_sort(*console,commands);
        else if( words == 4 && strcmp(commands[0],"add") == 0 )
            ui_add(console, commands);
        else if( words == 1 && strcmp(commands[0],"print") == 0 )
            ui_print(*console);
        else if( words == 2 && strcmp(commands[0],"delete") == 0 )
            ui_delete(console, commands);
        else if( words == 3 && strcmp(commands[0],"update") == 0 )
            ui_update(console, commands);
        else if( words == 4 && strcmp(commands[0],"migrate") == 0 )
            ui_migrate(console, commands);
        else
            printf("Invalid command ! Enter <help> to get the help-menu.\n");

        for( int position = 0 ; position < 20 ; ++position )
            free(commands[position]);
    }
}