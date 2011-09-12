#ifndef PROFILO_H
#define PROFILO_H

#include <string>

using std::string;

class Profilo
{
	private:
		string nome, cognome, telefono, mail, lavoro_precedente, lavoro_attuale;
		int anno_nascita, mese_nascita, giorno_nascita;

	public:
		Profilo( string, string, int, int, int, string, string, string, string);

		string getNome() const;
		string getCognome() const;
		int getAnnoNascita() const;
		int getMeseNascita() const;
		int getGiornoNascita() const;
		string getLavPrec() const;
		string getLavAtt() const;
		string getTelefono() const;
		string getMail() const;

		void setNome(string);
		void setCognome(string);
		void setAnnoNascita(int);
		void setMeseNascita(int);
		void setGiornoNascita(int);
		void setLavPrec(string);
		void setLavAtt(string);
		void setTelefono(string);
		void setMail(string);
};

#endif

