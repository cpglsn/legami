#include "User.h"


User::User(string n, string pass, Profilo* p, vector<Contatto*>* c, vector<Gruppo*>* g)
	: nick(n), password(pass), profilo(p), collegamenti(c), gruppi(g), ruolo("base"), gestore(0) {}


User::~User() {}


string User::getRuolo() const
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
	gesotre=l;
}


vector<User*>* User::find(Profilo* p) const
{
	p->setAnnoNascita(0);
	p->setMeseNascita(0);
	p->setGiornoNascita(0);
	p->setLavPrec("");
	p->setLavAtt("");
	p->setTelefono("");
	p->setMail("");

	vector<User*>* match = gestore->find(p);

	// rimuovo l'user corrente dalla lista
	for(unsigned int i=0; i<match->size(); ++i)
	{
		if(*(*match)[i] == *this)
			match->erase(match->begin() + i);
	}

	if(match->size() > risultatiMax)
		// cancella i risultati in più
		match->erase(match->begin() + risultatiMax, match->end());

	return match;
}

