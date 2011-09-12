#include "Gruppo.h"


Gruppo::Gruppo( string n, string d, vector<User*>* m)
	: nome(n), descrizione(d), membri(m) {}


string Gruppo::getNome() const
{
	return nome;
}


string Gruppo::getDescrizione() const
{
	return descrizione;
}


vector<User*>* Gruppo::getMembri() const
{
	return membri;
}


bool Gruppo::appartiene( User* user) const
{
	if( membri)
	{
		for( unsigned int i=0; i<membri->size(); ++i)
		{
			if( *((*membri)[i]) == *user )
				return true;
		}
	}

	// se non appartiene o la lista è vuota
	return false;
}


void Gruppo::aggiungi( User* user)
{
	if( membri)
	{
		// lo user appartiene già alla lista
		if( appartiene( user))
			return;

		membri->push_back(user);
		return;
	}

	// se la lista è vuota
	membri = new vector<User*>;
	membri->push_back(user);
	return;
}


void Gruppo::cancella( User* user)
{
	if( membri)
	{
		for( unsigned int i=0; i<membri->size(); ++i)
		{
			if( *((*membri)[i]) == *user )
				// chiamo il distruttore di User, non esegue la distruzione profonda
				membri->erase( membri->begin() + i);
		}

		// se il gruppo è vuoto allora lo cancello
		if( membri->empty() )
			delete this;
	}
}


bool Gruppo::operator ==(const Gruppo& g)
{
    return nome == g.nome;
}

