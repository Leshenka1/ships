#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;
class Ship
{
private:
	string nameOfShip;
public:
	Ship(string nameOfShip);
	Ship();
	bool emptyName();
	string getNameOfShip() const;
	friend ostream& operator << (ostream& os, const Ship& p);
	bool operator ==(const Ship& p);
};


