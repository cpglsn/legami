#include "User.h"
#include "Profilo.h"
#include "Gruppo.h"
#include "Contatto.h"
#include "Legami.h"


User::User(string n, string pass, Ruoli ruolo,Profilo* p, vector<Contatto*>* c, vector<Gruppo*>* g)
	: nick(n)
    , password(pass)
    , ruolo(ruolo)
    , profilo(p)
    , collegamenti(c)
    , gruppi(g)
    , gestore(0)
{

}


User::~User() {}


User::Ruoli User::getRuolo() const
{
	return ruolo;
}


bool User::operator==(const User& u)
{
	return (nick == u.nick && password == u.password);
}


string User::getNick() const
{
	return nick;
}


bool User::insertContatto(Contatto* c)
{
	if(c)
	{
		// se collegamenti = 0 alloco il vettore collegamenti e aggiungo il contatto
		if(collegamenti == 0)
		{
			collegamenti = new vector<Contatto*>;
			collegamenti->push_back(c);
			return true;
		}

		// se il vettore esiste, controllo che il contatto non sia gia presente
		else
		{
			for(unsigned int i=0; i<collegamenti->size(); ++i)
			{
				// se esiste esco con false
				if(*(*collegamenti)[i] == *c)
					return false;
			}

			// altrimenti
			collegamenti->push_back(c);
			return true;
		}
    }

	return false;
}


bool User::eraseContatto(Contatto* c)
{
	if(collegamenti && c)
	{
		for(unsigned int i=0; i<collegamenti->size(); ++i)
		{
			if(*(*collegamenti)[i] == *c)
			{
				delete (*collegamenti)[i];
				collegamenti->erase(collegamenti->begin() + i);
				return true;
			}
		}
	}

	// se esco dall'if, o il for non ritorna niente, il contatto non è stato cancellato
	return false;
}


void User::setGestore(Legami* l)
{
	gestore=l;
}
