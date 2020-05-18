#include <iostream>
#include "Film.h"
#include <windows.h>
using namespace std;


int main()
{
	Film f;
	int n;
	int m;
	do
	{
		cout << "Alegeti modul dorit:" << endl;
		cout << "1. Mod administrator" << endl;
		cout << "2.Mod utilizator" << endl;
		cout << "0. Apasand tasta 0 iesiti din program!!!" << endl;
		cout << "Alegeti ce doriti sa faceti apasand tasta de tip numar,din stanga celor de mai sus: ";
		cin >> n;
		if (n == 1)
			do
			{
				system("CLS");
				cout << "Ati intrat in modul administratorului:" << endl;
				cout << "1.Adaugati un film" << endl;
				cout << "2.Stergeti un film" << endl;
				cout << "3.Modificati un film " << endl;
				cout << "4. Afisati lista de filme" << endl;
				cout << "0. Apasand tasta 0, va reintoarceti la pagina principala!" << endl;
				cout << "Alegeti ce doriti sa faceti apasand tasta de tip numar,din stanga celor de mai sus: ";
				cin >> m;
				//optiune adaugare
				if (m == 1)
					f.insert_film();
				else
					//optiune stergere
					if (m == 2)
						f.stergere_film();
					else
						//optiune modificare
						if (m == 3)
							f.modificare_film();
				/*else
					if (m == 4)
					//	f.afisare_filme();
					else*/
				if (m == 0)
				{
					cout << "Ati iesit din modul administrator";
					break;
				}
				Sleep(3000);
				system("CLS");
			} while (m != 0);
			if (n == 0)
				break;
			Sleep(3000);
			system("CLS");
	} while (n != 0);

}