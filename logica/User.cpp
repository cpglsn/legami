#include "User.h"
#include "Contatto.h"
#include "Legami.h"
#include "Xml.h"
#include "Gruppo.h"



User::User(string n, string pass)
	: nick(n)
	, password(pass)
	, gestore(0)
{

}



User::~User() {}



void User::operator delete(void* p)
{
	User* u = static_cast<User*>(p);
	u->gestore->cancella(u);

	// rimuovo i collegamenti dello user
	for(unsigned int i=0; i<u->collegamenti->size(); ++i)
	{
		delete (u->collegamenti)->at(i);
		(u->collegamenti)->at(i) = 0;
	}

	// rimuovo il link ai collegamenti
	delete u->collegamenti;
	u->collegamenti = 0;

	// rimuovo lo user dai gruppi cui appartiene
	for(unsigned int i=0; i<u->gruppi->size(); ++i)
		(u->gruppi)->at(i)->cancella(u);

	// rimuovo il link ai gruppi
	delete u->gruppi;
	u->gruppi = 0;

	// rimuovo il profilo dello user
	delete u->profilo;
	u->profilo = 0;
}



User* User::leggi(string s)
{
	string nick =  tag(s, "<nick>", "</nick>");
	string pass =  tag(s, "<pass>", "</pass>");
	return new User(nick, pass);
}



string User::scrivi() const
{
	return "<nick>" + nick + "</nick>" + "<pass>" + password + "</pass>";
}



bool User::operator==(const User& u)
{
	return (nick == u.nick);
}



string User::getRuolo() const
{
	return "base";
}



string User::getNick() const
{
	return nick;
}



Profilo* User::getProfilo() const
{
	return profilo;
}



bool User::checkLogin(string n, string p) const
{
	return (nick == n && password == p);
}




bool User::insertContatto(Contatto* c)
{
	if(!c) return false;

	if(!collegamenti)
	{
		// creo il vettore
		collegamenti=new vector<Contatto*>;
		collegamenti->push_back(c);
		return true;
	}

	// controllo che il contatto non sia già presente
	for(unsigned int i=0; i<collegamenti->size(); ++i)
	{
		// se è già presente non lo inserisco
		if(*((*collegamenti)[i]) == *c)
			return false;
	}

	// se non è già presente lo inserisco
	collegamenti->push_back(c);
	return true;
}



bool User::eraseContatto(Contatto* c)
{
	if(collegamenti && c)
	{
		for(unsigned int i=0; i<collegamenti->size(); ++i)
		{
			if(*((*collegamenti)[i]) == *c)
			{
				delete (*collegamenti)[i];
				collegamenti->erase(collegamenti->begin() + i);
				return true;
			}
		}
	}

	// se il contatto non è presente, oppure l'if iniziale non è soddisfatto
	return false;
}



bool User::insertGruppo(Gruppo* c)
{
	if(!c) return false;

	if(!gruppi)
	{
		// creo il vettore
		gruppi=new vector<Gruppo*>;
		gruppi->push_back(c);
		return true;
	}

	// controllo che il gruppo non sia già presente
	for(unsigned int i=0; i<gruppi->size(); ++i)
	{
		// se è già presente non lo inserisco
		if( *((*gruppi)[i]) == *c )
			return false;
	}

	// se non è già presente lo inserisco
	gruppi->push_back(c);
	return true;
}



bool User::eraseGruppo(Gruppo* c)
{
	if(gruppi && c)
	{
		for(unsigned int i=0; i<gruppi->size(); ++i)
		{
			if(*((*gruppi)[i]) == *c)
			{
				delete (*gruppi)[i];
				gruppi->erase(gruppi->begin() + i);
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

