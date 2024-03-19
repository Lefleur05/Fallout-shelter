#include "Hall.h"

Hall::Hall(HallType _type)
{
	type = _type;
	hallSize = 1;
	hallLV = 1;
	humans = vector<Human*>();

}
