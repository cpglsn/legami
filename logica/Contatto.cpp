#include "Contatto.h"


Contatto::Contatto(User* u, string t)
	: user(u)
    , tag(t)
{
}

Contatto::~Contatto()
{

}

bool Contatto::operator==(const Contatto& c)
{
	return user->getNick() == c.user->getNick();
}


User* Contatto::getUser() const
{
	return user;
}


string Contatto::getTag() const
{
	return tag;
}


