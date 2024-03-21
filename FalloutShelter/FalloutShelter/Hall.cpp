#include "Hall.h"

Hall::Hall(HallType _type)
{
	type = _type;
	hallSize = 1;
	hallLV = 1;
	humans = vector<Human*>();
	timerRessource = nullptr;
	//InitTimer();
}

void Hall::InitTimer()
{
	timerRessource = new Timer([&]() {cout << "Timer Begin" << endl; cout << to_string(type) << endl; }, seconds(1), true, true);
}
