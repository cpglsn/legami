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
		BusinessUser( string, string, Profilo* =0, vector<Contatto*>* =0, vector<Gruppo*>* =0);
		virtual ~BusinessUser();

		virtual vector<User*>* find(Profilo*) const;
};

#endif

