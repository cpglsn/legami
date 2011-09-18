/*
	questa classe rappresenta la lista di contatti (link a User e
	tag per definire in che rapporti si è con lo user)
*/

#ifndef CONTATTO_H
#define CONTATTO_H

#include "User.h"
#include <string>

using std::string;

class User;

class Contatto
{
	public:
		Contatto(User*, string);

		bool operator==(const Contatto&);

		// ritorna il puntatore allo user del contatto
		User* getUser() const;

		// ritorna il tag con cui lo user è stato salvato
		string getTag() const;

	private:
		User* user;
		string tag;
};

#endif

