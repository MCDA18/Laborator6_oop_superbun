#pragma once
#include "Validare.h"
#include <string>
#include <vector>
using namespace std;
class Film : public Validare
{
public:
	Validare v;
	string titel;
	string genre;
	int erscheinungsjahr;
	int anzahl_likes;
	string trailer;
	vector<Film> vector_filme;
	Film();
	void insert_film();
	void stergere_film();
	void modificare_film();

};


