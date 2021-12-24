#include "Ship.h"

Ship::Ship(string nameOfShip)
{
	this->nameOfShip = nameOfShip;
}

Ship::Ship()
{
}

bool Ship::emptyName()
{
	if (nameOfShip.empty()) return true;
	else return false;
}

string Ship::getNameOfShip() const
{
	return nameOfShip;
}

bool Ship::operator==(const Ship& p)
{
	if (nameOfShip == p.nameOfShip) return true;
	else return false;
}

ostream& operator<<(ostream& os, const Ship& p)
{
	os << p.nameOfShip;
	return os;
}
