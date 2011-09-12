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
		Contatto( User*, string);
		virtual ~Contatto();

		bool operator==(const Contatto&);

		User* getUser() const;
		string getTag() const;
};

#endif

