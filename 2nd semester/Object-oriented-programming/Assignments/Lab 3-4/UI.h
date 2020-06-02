#ifndef LAB3_4_UI_H
#define LAB3_4_UI_H

#include "Service.h"
#include "stdio.h"

typedef struct{
    Controller *controller;
} Console ;

Console create_console(Controller *controller);

void start( Console *console) ;

#endif //LAB3_4_UI_H
