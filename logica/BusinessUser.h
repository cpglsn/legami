#ifndef BUSINESSUSER_H
#define BUSINESSUSER_H

#include "User.h"

class Legami;
class Profilo;

class BusinessUser : public User
{
	private:
		static const unsigned int risultatiMax;

	public:
		BusinessUser( Legami*, string, string, Profilo*, vector<Contatto*>*, vector<Gruppo*>* );
		virtual ~BusinessUser();

		virtual vector<User*>* find(Profilo*) const;
};

#endif

