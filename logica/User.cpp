#include "User.h"

User::User( Legami* l, string n, string pass, Profilo* p, vector<Contatto*>* c, vector<Gruppo*>* g )
	: gestore(l), nick(n), password(pass), profilo(p), collegamenti(c), gruppi(g), ruolo("base") {}


User::~User() {}


string User::getRuolo() const
{
	return ruolo;
}


bool User::operator==(const User& u)
{
	return nick == u.nick;
}


void User::setGestore(Legami* g)
{
	gestore = g;
}


bool User::insertContatto(Contatto* c)
{
	if(c)
	{
		if(collegamenti == 0) // se collegamenti = 0 alloco il vettore collegamenti e aggiungo il contatto
		{
			collegamenti = new vector<Contatto*>;
			collegamenti->push_back(c);
			return true;
		}

		else // se il vettore esiste, controllo che il contatto non sia gia presente
		{
			for(unsigned int i=0; i<collegamenti->size(); ++i)
			{
				if( *(*collegamenti)[i] == *c ) // se esiste esco con false
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
	if( collegamenti && c )
	{
		for(unsigned int i=0; i<collegamenti->size(); ++i)
		{
			if( *(*collegamenti)[i] == *c )
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

