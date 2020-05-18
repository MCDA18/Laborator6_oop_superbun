#include "Film.h"
#include <iostream>
#include <fstream>
using namespace std;
//constructoru default
Film::Film()
{
	titel = "";
	genre = "";
	erscheinungsjahr = 0;
	anzahl_likes = 0;
	trailer = "";
}
//adaugarea unui film,la inceputul programului,creand astfel o lista implicita
//inserarea unui film nou,in modul administratoului
void Film::insert_film()
{
	Validare v;
	string titel, genre, trailer;
	int erscheinungsjahr, anzahl_likes;
	Film f;
	int ok = 0;
	cout << "Ce nume doriti sa aiba filmul?";
	cin >> titel;
	if (v.validare_film(titel) == 1)
	{
		cout << "Ce gen este filmul?";
		cin >> genre;
		cout << "In ce an a aparut filmul?";
		try {
			cin >> erscheinungsjahr;

		}
		catch (exception)
		{
			cout << "Date introduse gresit!";
		}
		cout << "Care este numarul de like-uri?";
		cin >> anzahl_likes;
		cout << "Care este linkul trailerului?";
		cin >> trailer;
		//atributele obiectului primesc datele oferite de administrator
		/*f.titel = titel;
		f.genre = genre;
		f.erscheinungsjahr = erscheinungsjahr;
		f.anzahl_likes = anzahl_likes;
		f.trailer = trailer;*/
		ofstream out("filme.txt", ios::app);
		out << titel << ' ' << genre << ' ' << erscheinungsjahr << ' ' << anzahl_likes << ' ' << trailer << endl;
		cout << "Filmul a fost adaugat cu succes";
		out.close();
	}
	else
		cout << "Numele exista deja";
}
//stergerea unui film
void Film::stergere_film()
{
	Validare v;
	vector<Film> aux;
	string titel, genre, trailer;
	int erscheinungsjahr, anzahl_likes;
	Film f;
	string nume;
	cout << "Ce filme doriti sa stergeti?";
	cin >> nume;
	int ok = 0;
	ifstream in("filme.txt", ios::in);
	//daca exista numele,il poate sterge
	if (v.validare_film(nume) == 0)
	{
		while (in >> titel >> genre >> erscheinungsjahr >> anzahl_likes >> trailer)
			if (titel != nume)
			{
				f.titel = titel;
				f.genre = genre;
				f.erscheinungsjahr = erscheinungsjahr;
				f.anzahl_likes = anzahl_likes;
				f.trailer = trailer;
				aux.push_back(f);//creaza un nou vector,fara filmul pe care dorim sa l stergem
			}
		vector_filme = aux;//se pune aux in vectoru v
		ofstream out("filme.txt", ios::out);
		for (const auto& film : vector_filme)
			out << film.titel << " " << film.genre << " " << film.erscheinungsjahr << " " << film.anzahl_likes << " " << film.trailer << endl;
		cout << "Filmul a fost sters cu succes";
		in.close();
		out.close();
	}
	else
		cout << "Filmul pe care doriti sa-l stergeti nu exista!";
}

void Film::modificare_film()
{
	vector<Film> aux;
	Film f;
	Validare v;
	string titel, genre, trailer, nume, tr, gen, t;
	int erscheinungsjahr, anzahl_likes, nr_like, an;
	string titlu;
	int m, n;
	cout << "Ce film doriti sa modificati?" << endl;
	cin >> nume;
	if (v.validare_film(nume) == 0)
	{
		cout << "Alegeti ce doriti sa modificati la acest film:" << endl;
		cout << "1.Titel" << endl;
		cout << "2.Genre" << endl;
		cout << "3.Erscheinungsjahr" << endl;
		cout << "4.Anzahl Likes" << endl;
		cout << "5.Link trailer" << endl;
		cin >> m;
		ifstream in1("filme.txt", ios::in);
		while (in1 >> titel >> genre >> erscheinungsjahr >> anzahl_likes >> trailer)
			if (titel != nume)
			{
				f.titel = titel;
				f.genre = genre;
				f.erscheinungsjahr = erscheinungsjahr;
				f.anzahl_likes = anzahl_likes;
				f.trailer = trailer;
				aux.push_back(f);//creaza un nou vector,fara filmul pe care dorim sa l stergem
			}
			else
			{
				t = titel;
				gen = genre;
				an = erscheinungsjahr;
				nr_like = anzahl_likes;
				tr = trailer;
			}
		in1.close();
		ofstream out("filme.txt", ios::out);
		for (const auto& film : aux)
			out << film.titel << " " << film.genre << " " << film.erscheinungsjahr << " " << film.anzahl_likes << " " << film.trailer << endl;
		out.close();
		ofstream out1("filme.txt", ios::app);
		if (m == 1)
		{
			cout << "Titlu nou:";
			cin >> titlu;
			out1 << titlu << " " << gen << " " << an << " " << nr_like << " " << tr;
			cout << "Titlul a fost schimbat!" << endl;

		}
		if (m == 2)
		{
			cout << "Gen nou:";
			cin >> genre;
			out1 << t << " " << genre << " " << an << " " << nr_like << " " << tr;
			cout << "Genul a fost schimbat!";
		}
		if (m == 3)
		{
			cout << "An nou:";
			cin >> erscheinungsjahr;
			out1 << t << " " << gen << " " << erscheinungsjahr << " " << nr_like << " " << tr;
			cout << "Anul a fost schimbat!";
		}
		if (m == 4)
		{
			cout << "Numar de like-uri nou:";
			cin >> anzahl_likes;
			out1 << t << " " << gen << " " << an << " " << anzahl_likes << " " << tr;
			cout << "Numarul de like-uri a fost schimbat";
		}
		if (m == 5)
		{
			cout << "Trailer nou:";
			cin >> trailer;
			out1 << t << " " << gen << " " << an << " " << nr_like << " " << trailer;
			cout << "Trailer-ul a fost schimbat";
		}
		out1.close();

	}
	else
		cout << "Filmul pe care doriti sa-l modificati,nu exista!";
}


/*
//modificarea filmului
void Film::modificare_film()
{
	string titel, genre, trailer;
	int erscheinungsjahr, anzahl_likes;
	string nume,titlu,gen,tr;
	Film f;
	int an,nr;
	int ok = 0;
	int n;
	vector<Film> aux;
	std::cout << "Ce film doriti sa modificati?"<<endl;
	cin >> nume;
	ifstream in("filme.txt", ios::in);
	//se va cauta filmul care va trebui modificat
	while(in>>titlu>>genre>>erscheinungsjahr>>anzahl_likes>>trailer)
		if (titlu == nume)
		{
			ok = 1;
			//administratorul alege ce sa modifice
			cout << "Alegeti ce doriti sa modificati la acest film:"<<endl;
			cout << "1.Titel" << endl;
			cout << "2.Genre"<<endl;
			cout << "3.Erscheinungsjahr" << endl;
			cout << "4.Anzahl Likes" << endl;
			cout << "5.Link trailer" << endl;
			cin >> n;
			//n=1,schimba titlu
			if (n == 1)
			{
				cout << "Titlul nou:" << endl;
				cin >> titlu;
				for (auto film : v)
				{
					if (film.titel == it.titel)
						f.titel = titlu;
					else
						f.titel = film.titel;
					f.genre = film.genre;
					f.erscheinungsjahr = film.erscheinungsjahr;
					f.anzahl_likes = film.anzahl_likes;
					f.trailer = film.trailer;
					aux.push_back(f);//creaza un vector nou,schimband titlul
				}
				cout << "Titlul a fost modificat!";
			}
			//n==2,schimba genul
			if (n == 2)
			{
				cout << "Gen nou:"<<endl;
				cin >> gen;
				for (auto film : v)
				{
					//parcurgere vectoru si unde titlu de la film.titel==it.titel..schimba genu,daca nu pune genul normal
					if (film.titel == it.titel)
						f.genre = gen;
					else
						f.genre = film.genre;
					f.titel = film.titel;
					f.erscheinungsjahr = film.erscheinungsjahr;
					f.anzahl_likes = film.anzahl_likes;
					f.trailer = film.trailer;
					aux.push_back(f);// creaza un vector nou, schimband genuk
				}
				cout << "Genul a fost modificat!" << endl;
			}
			//schimba anul aparitiei
			if (n == 3)
			{
				cout << "Erscheinungsjahr nou:";
				cin >> an;
				for (auto film : v)
				{

					if (film.titel == it.titel)
						f.erscheinungsjahr = an;
					else
						f.erscheinungsjahr = film.erscheinungsjahr;
					f.genre = film.genre;
					f.titel = film.titel;
					f.anzahl_likes = film.anzahl_likes;
					f.trailer = film.trailer;
					aux.push_back(f);
				}
				cout << "Anul aparitiei a fost modificat!";
			}
			//schimba numarul de like-uri
			if (n == 4)
			{
				cout << "Numar de like-uri nou:";
				cin >> nr;
				for (auto film : v)
				{

					if (film.titel == it.titel)
						f.anzahl_likes = nr;
					else
						f.anzahl_likes = film.anzahl_likes;
					f.genre = film.genre;
					f.titel = film.titel;
					f.erscheinungsjahr = film.erscheinungsjahr;
					f.trailer = film.trailer;
					aux.push_back(f);
				}
				cout << "Numarul de like-uri a fost modificat!";
			}
			//schimba link ul
			if (n == 5)
			{
				cout << "Link-ul trailerului nou:";
				cin >> tr;
				for (auto film : v)
				{

					if (film.titel == it.titel)
						f.trailer = tr;
					else
						f.trailer = film.trailer;
					f.genre = film.genre;
					f.titel = film.titel;
					f.anzahl_likes = film.anzahl_likes;
					f.erscheinungsjahr = film.erscheinungsjahr;
					aux.push_back(f);
				}
				cout << "Link-ul trailerui a fost modificat!";
			}
			v = aux;
		}
		//daca numele ii gresit sau nu exista in vector,se afiseaza mesajul
	if (ok == 0)
		cout << "Filmul pe care doriti sa-l modificati,nu exista!";
}*/