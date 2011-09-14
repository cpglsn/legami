#include "Profilo.h"


Profilo::Profilo(string n, string c, string t, string ma, string lp, string la, int a, int m, int g)
	: nome(n), cognome(c), telefono(t), mail(ma), lavoro_precedente(lp), lavoro_attuale(la), anno_nascita(a), mese_nascita(m), giorno_nascita(g) {}


/*
string Profilo::getNome() const
{
	return nome;
}


string Profilo::getCognome() const
{
	return cognome;
}


int Profilo::getAnnoNascita() const
{
	return anno_nascita;
}


int Profilo::getMeseNascita() const
{
	return mese_nascita;
}


int Profilo::getGiornoNascita() const
{
	return giorno_nascita;
}


string Profilo::getLavPrec() const
{
	return lavoro_precedente;
}


string Profilo::getLavAtt() const
{
	return lavoro_attuale;
}


string Profilo::getTelefono() const
{
	return telefono;
}


string Profilo::getMail() const
{
	return mail;
}
*/

void Profilo::setNome(string s)
{
	nome = s;
}


void Profilo::setCognome(string s)
{
	cognome = s;
}


void Profilo::setAnnoNascita(int a)
{
	anno_nascita = a;
}


void Profilo::setMeseNascita(int m)
{
	mese_nascita = m;
}


void Profilo::setGiornoNascita(int g)
{
	giorno_nascita = g;
}

void Profilo::setLavPrec(string s)
{
	lavoro_precedente = s;
}


void Profilo::setLavAtt(string s)
{
	lavoro_attuale = s;
}


void Profilo::setTelefono(string s)
{
	telefono = s;
}


void Profilo::setMail(string s)
{
	mail = s;
}

