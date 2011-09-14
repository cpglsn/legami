/*
	questa classe gestisce i dati personali dello user
*/

#ifndef PROFILO_H
#define PROFILO_H

#include <string>

using std::string;

class Profilo
{
	public:
		Profilo(string, string, string, string, string, string, int, int, int);

/*		string getNome() const;
		string getCognome() const;
		string getLavPrec() const;
		string getLavAtt() const;
		string getTelefono() const;
		string getMail() const;
		int getAnnoNascita() const;
		int getMeseNascita() const;
		int getGiornoNascita() const;
*/
		void setNome(string);
		void setCognome(string);
		void setLavPrec(string);
		void setLavAtt(string);
		void setTelefono(string);
		void setMail(string);
		void setAnnoNascita(int);
		void setMeseNascita(int);
		void setGiornoNascita(int);

	private:
		string nome, cognome, telefono, mail, lavoro_precedente, lavoro_attuale;
		int anno_nascita, mese_nascita, giorno_nascita;
};

#endif

