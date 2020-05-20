#pragma once
#include "Validare.h"
#include <string>
#include <vector>
#include <windows.h>
#include <stdlib.h>
#include <cstdlib>

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
	vector<Film> ListaFilme;
	Film();
	void insert_film();
	void stergere_film();
	void afisare_filme();
	void modificare_film();
	void Cautare(int obtiune);
	//void openTrailer(string trailer);
	void addListaFilme(Film it);
	void addListaFilme1(int obtiune);
	void stergere(int obtiune);
	void Afisare(int obtiune);

};


