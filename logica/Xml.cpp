#include "Xml.h"
#include <sstream>



// ritorna l'info tra i tag
string tag(string s, string t1, string t2)
{
	if(s.find(t1)!=string::npos && s.find(t2)!=string::npos )
	{
		int inizio = s.find(t1) + t1.size();
		int fine = s.find(t2) - inizio;
		return s.substr(inizio, fine);
	}

	// se non c'è match ritorna la stringa vuota
	return "";
}



string int_to_string(const int& i)
{
	std::ostringstream ss;
	ss << i;
	return ss.str();
}



int string_to_int(const string& s)
{
	int number;
	std::istringstream ss(s);
	ss >> number;
	return number;
}

