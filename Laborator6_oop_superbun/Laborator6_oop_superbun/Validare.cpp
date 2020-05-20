#include "Validare.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int Validare::validare_film(string nume)
{
	string titel, genre, trailer;
	int erscheinungsjahr, anzahl_likes;
	ifstream in("filme.txt", ios::in);
	while (in >> titel >> genre >> erscheinungsjahr >> anzahl_likes >> trailer)
		if (titel == nume)
			return 0;
	return 1;
}
bool Validare::check_number(int strin) {
	string str = to_string(strin);
	for (int i = 0; i < str.length(); i++)
		if (isdigit(str[i])==false)
			return false;
	return true;
}