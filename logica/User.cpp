#include "User.h"
#include "Contatto.h"
#include "Legami.h"


User::User(string n, string pass)
	: nick(n)
	, password(pass)
	, gestore(0)
{

}


User::~User() {}


bool User::operator==(const User& u)
{
	// serve per controllare il login
	return (nick == u.nick && password == u.password);
}


string User::getNick() const
{
	return nick;
}


bool User::insertContatto(Contatto* c)
{
	if(!collegamenti.empty() && c) return false;

	// controllo che il contatto non sia già presente
	for(unsigned int i=0; i<collegamenti.size(); ++i)
	{
		// se è già presente non lo inserisco
		if(*(collegamenti[i]) == *c)
			return false;
	}

	// se non è già presente lo inserisco
	collegamenti.push_back(c);
	return true;
}


bool User::eraseContatto(Contatto* c)
{
	if(!collegamenti.empty() && c)
	{
		for(unsigned int i=0; i<collegamenti.size(); ++i)
		{
			if(*(collegamenti[i]) == *c)
			{
				delete collegamenti[i];
				collegamenti.erase(collegamenti.begin() + i);
				return true;
			}
		}
	}

	// se il contatto non è presente, oppure l'if iniziale non è soddisfatto
	return false;
}


vector<User*>* User::find(Profilo* p) const
{
	if(!gestore || !p)
		return 0;

	// lo user Base può solo cercare per nome, cognome o email gli altri campi quindi vanno resettati
	p->setLavPrec("");
	p->setLavAtt("");
	p->setAnnoNascita(0);
	p->setMeseNascita(0);
	p->setGiornoNascita(0);

	// manda il profilo di ricerca al gestore che ritorna sempre un vector<User*>*
	return gestore->find(p);
}

