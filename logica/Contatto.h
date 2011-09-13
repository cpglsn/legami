/*
	questa classe rappresenta la lista di contatti (link a User e
	tag per definire in che rapporti si è con lo user)
*/

#ifndef CONTATTO_H
#define CONTATTO_H

#include <string>
#include "User.h"

using std::string;

class User;

class Contatto
{
	private:
		User* user;
		string tag;

	public:
		Contatto(User*, string);
		virtual ~Contatto();

		bool operator==(const Contatto&);

		// ritorna il puntatore allo user del contatto
		User* getUser() const;

		// ritorna il tag con cui lo user è stato salvato
		string getTag() const;
};

#endif

