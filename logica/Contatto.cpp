#include "Contatto.h"


Contatto::Contatto( User* u, string t)
	: user(u), tag(t) {}


bool Contatto::operator==(const Contatto& c)
{
	// utilizza l'operatore == ridefinito nella classe User
	return *user == *c.user;
}


User* Contatto::getUser() const
{
	return user;
}


string Contatto::getTag() const
{
	return tag;
}


