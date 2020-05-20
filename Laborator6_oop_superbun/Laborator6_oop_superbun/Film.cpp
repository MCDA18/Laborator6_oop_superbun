#include "Film.h"
#include <iostream>
#include <fstream>
#include <cstdlib> 
#include <exception>
#include <assert.h>
#define assert(exp) ((void) 0)
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
	Validare v1;
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
		while (!(cin >> erscheinungsjahr))
		{
			cout << "Eroare:Reintroduceti data! ";
			cin.clear();
			cin.ignore(123, '\n');

		}
		cout << "Care este numarul de like-uri?";
		while (!(cin >> anzahl_likes))
		{
			cout << "Eroare:Reintroduceti numarul de like-uri! ";
			cin.clear();
			cin.ignore(123, '\n');

		}
		cout << "Care este linkul trailerului?";
		cin >> trailer;
		ofstream out("filme.txt", ios::app);
		out << titel << ' ' << genre << ' ' << erscheinungsjahr << ' ' << anzahl_likes << ' ' << trailer << endl;
		cout << "Filmul a fost adaugat cu succes";
		out.close();
	}
	else
		cout << "Numele exista deja";
}
void Film::afisare_filme()
{
	string titel, genre, trailer;
	int erscheinungsjahr, anzahl_likes;
	ifstream in("filme.txt", ios::in);
	while (in >> titel >> genre >> erscheinungsjahr >> anzahl_likes >> trailer)
		cout << titel << " " << genre << " " << erscheinungsjahr << " " << anzahl_likes << " " << trailer<<endl;
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
			while (!(cin >> erscheinungsjahr))
			{
				cout << "Eroare:Reintroduceti data! ";
				cin.clear();
				cin.ignore(123, '\n');

			}
			out1 << t << " " << gen << " " << erscheinungsjahr << " " << nr_like << " " << tr;
			cout << "Anul a fost schimbat!";
		}
		if (m == 4)
		{
			cout << "Numar de like-uri nou:";
			while (!(cin >> anzahl_likes))
			{
				cout << "Eroare:Reintroduceti data! ";
				cin.clear();
				cin.ignore(123, '\n');

			}
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

void Film::Cautare(int obtiune)
{
	vector<Film> aux;
	string titel, genre, trailer;
	int erscheinungsjahr, anzahl_likes;
	Film f;
	string gen;
	cout << "Genul este: ";
	cin >> gen;
	int ok = 0;
	int k = 1;
	ifstream in1("filme.txt", ios::in);
	while (in1 >> titel >> genre >> erscheinungsjahr >> anzahl_likes >> trailer)
	{
		f.titel = titel;
		f.genre = genre;
		f.erscheinungsjahr = erscheinungsjahr;
		f.anzahl_likes = anzahl_likes;
		f.trailer = trailer;
		aux.push_back(f);//creaza un nou vector
	}
	for (auto it : aux) /// Cautam in lista de filme
	{
		if (gen == it.genre && k == 1) /// afisam primul gen 
		{
			cout << it.titel << " " << it.genre << " " << it.erscheinungsjahr << " " << it.anzahl_likes << " " << it.trailer << endl;
			string From = string(it.trailer);
			wstring To(From.begin(), From.end()); ///am transformat din string in wstring
			LPCWSTR Last = To.c_str(); /// din wstring in LPCWSTR
			LPCWSTR C = TEXT("open");
			ShellExecute(NULL, C, Last, NULL, NULL, SW_SHOWNORMAL); ///aceseaza browserul
			ok = 1;
			int m;
			do
			{
				///Meniul pentru problema 3 care contine problema 2 incorporata 
				cout << "1.Continuati / Adaugati" << endl;
				cout << "2.Nu Adaugati / Continuati" << endl;
				cout << "0.Iesiti " << endl;
				cout << "Alegeti ce doriti sa faceti apasand tasta de tip numar,din stanga celor de mai sus: ";
				cin >> m;
				//optiune continuare si adaugare
				if (m == 1)
				{
					addListaFilme(it);
					break;
				}
				else
					//optiune continuare
					if (m == 2)
						break;
					else
						if (m == 0)
						{
							cout << "Ati iesit din modul cautare";
							k = 0;
							break;
						}
				//Sleep(3000);
				//system("CLS");
			} while (m != 0);
		}
	}
	addListaFilme1(obtiune);
	if (ok == 0) ///daca nu a gasit genul afisam toate filmele
	{
		cout << "Nu s-a gasit film, va atasam lista de filme pentru o noua cautare";
		string topicName = "filme";
		topicName = "notepad \"" + topicName + "\"";  /// deschiderea fisierului txt;

		system(topicName.c_str());
	}
}

// adaugam in lista de filme

void Film::addListaFilme(Film it) {
	int ok = 1;
	// veerificam daca filmul nu este deja in watchlist
	for (auto i : ListaFilme) {
		if (i.titel == it.titel) {
			cout << "\nFilm se afla in Lista!\n";
			ok = 0;
		}
	}
	if (ok == 1) {
		ListaFilme.push_back(it);
		cout << "\nFilm Adaugat cu succes.\n";
	}

}

void Film::addListaFilme1(int optiune)
{
	/// adaugarea in cele 2 optiuni html / csv
	if (optiune == 1)
	{
		ofstream myfile;
		myfile.open("example.csv");	//deschidere csv
		myfile << "Lista de filme.\n";
		for (auto i : ListaFilme)
		{
			// scriere in fisier csv
			myfile << i.titel << "," << i.genre << "," << i.erscheinungsjahr << "," << i.anzahl_likes << "," << i.trailer << "\n";
			
		}
		myfile.close();
	}
	else
		if (optiune == 2)
		{
			//scrierea in html
			ofstream myfile;
			myfile.open("webex.html"); //deschidere html
			myfile << "<!doctype html>\n";
			myfile << "<html>\n";
			myfile << "<head><title> Watchliste </title></head>\n";
			myfile << "<body>\n";
			myfile << "<table border=1>\n"; ///bordura
			myfile << "<tr>\n";
			myfile << "<td> Titel </td>\n";    ///coloanele
			myfile << "<td> Genre </td>\n"; 
			myfile << "<td> Jahr </td>\n";
			myfile << "<td> Likes </td>\n";
			myfile << "<td> Trailer link </td>\n";
			myfile << "</tr>\n";
			for (auto it : ListaFilme)
			{
				myfile << "<tr>\n";
				myfile << "<td>" <<it.titel<< "</td>\n";
				myfile << "<td>" << it.genre << "</td>\n";
				myfile << "<td>" << it.erscheinungsjahr << "</td>\n";
				myfile << "<td>" << it.anzahl_likes << "</td>\n";
				myfile << "<td><a href =" << it.trailer << ">link</a></td>\n";
				myfile << "</tr>\n";
			}
			myfile << "</table>\n";
			myfile << "</body>\n";
			myfile << "</html>\n";

		}
}
void Film::stergere(int obtiune)
{
	vector<Film> ax;
	string titel, genre, trailer;
	int erscheinungsjahr, anzahl_likes;
	Film f;
	ifstream in1("filme.txt", ios::in);
	while (in1 >> titel >> genre >> erscheinungsjahr >> anzahl_likes >> trailer)
	{
		f.titel = titel;
		f.genre = genre;
		f.erscheinungsjahr = erscheinungsjahr;
		f.anzahl_likes = anzahl_likes;
		f.trailer = trailer;
		ax.push_back(f);//creaza un nou vector
	}
	vector<Film> aux;
	vector<Film> aux1;
	int ok = 0;
	string titlu;
	cout << "Dati titlul: ";
	cin >> titlu;
	for (auto it : ListaFilme) ///Parcurgem lista de vizionari 
	{
		if (it.titel == titlu) ///Cautam titlul
		{
			ok = 1;
			cout << "Doriti sa dati un like la aceast film\n";
			cout << "Tasta 1 = Da\n";
			cout << "Tasta 2 = Nu\n";
			cout << "Apasati Tasta = ";
			int n;
			cin >> n;
			if (n == 1) ///Partea de modificare a like-ului in lista de filme si stergerea filmului in lista de vizionari
			{
				for (const auto& film : ax) /// parcurgem pentru lista de filme 
					if (film.titel == titlu)
					{
						f.titel = film.titel;
						f.genre = film.genre;
						f.erscheinungsjahr = film.erscheinungsjahr;
						f.anzahl_likes = film.anzahl_likes + 1; ///Cand gasim filmul modificam pretul
						f.trailer = film.trailer;
						aux.push_back(f);
					}
					else
					{
						f.titel = film.titel;
						f.genre = film.genre;
						f.erscheinungsjahr = film.erscheinungsjahr;
						f.anzahl_likes = film.anzahl_likes;
						f.trailer = film.trailer;
						aux.push_back(f);
					}
				ax = aux;//se pune aux in vectoru ax 
				ofstream out("filme.txt", ios::out);
				for (const auto& film : aux) /// adaugam in fisier schimbarea
					out << film.titel << " " << film.genre << " " << film.erscheinungsjahr << " " << film.anzahl_likes << " " << film.trailer << endl;
				out.close();
				for (const auto& film : ListaFilme)
					if (film.titel != titlu)   ///Stergem filmul din lista de Vizionare
					{
						f.titel = film.titel;
						f.genre = film.genre;
						f.erscheinungsjahr = film.erscheinungsjahr;
						f.anzahl_likes = film.anzahl_likes;
						f.trailer = film.trailer;
						aux1.push_back(f);//creaza un nou vector,fara filmul pe care dorim sa l stergem
					}
				ListaFilme = aux1;//se pune aux in vectoru ListaFilme
				cout << "Filmul a fost sters cu succes";
			}

			else
				if (n == 2)
				{
					for (const auto& film : ListaFilme)
						if (film.titel != titlu)	///Stergem filmul din lista de Vizionare
						{
							f.titel = film.titel;
							f.genre = film.genre;
							f.erscheinungsjahr = film.erscheinungsjahr;
							f.anzahl_likes = film.anzahl_likes;
							f.trailer = film.trailer;
							aux.push_back(f);//creaza un nou vector,fara filmul pe care dorim sa l stergem
						}
					ListaFilme = aux1;//se pune aux in vectoru v
					cout << "Filmul a fost sters cu succes";

				}
				else
					if (n != 1 && n != 2)
						cout << "Tasta incorecta";
		}


	}
	addListaFilme1(obtiune);
	if (ok == 0)
		cout << "Nu exista filmul";
	
}
void Film::Afisare(int optiune)
{/// Afisam lista de vizionare
	if (optiune == 1)
	{
		string topicName = "example.csv";
		system(topicName.c_str());  /// afisare lista csv
	}
	else
		if (optiune == 2)
		{
			string topicName = "webex.html"; /// afisare lista html;
			system(topicName.c_str());
		}
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