#include "UI.h"

int main()
{
    Repository repo ;
    Controller controller ;
    Console console ;

    repo = create_repository(100) ;
    controller = create_controller(&repo) ;
    console = create_console(&controller) ;

    start(&console);
}