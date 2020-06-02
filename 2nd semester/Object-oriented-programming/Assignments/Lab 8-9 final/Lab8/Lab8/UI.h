#pragma once
#ifndef LAB5_6_UI_H
#define LAB5_6_UI_H
#include "Bussines.h"
class Console {
private:
	Controller ctrl;
public:
	Console(const Controller& controller) : ctrl{ controller } {}
	void run();
	void run_admin();
	void run_user();
};
#endif //LAB5_6_UI_H