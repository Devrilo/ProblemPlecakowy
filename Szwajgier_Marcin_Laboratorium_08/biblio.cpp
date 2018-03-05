#include "biblio.h"

/*
*Funkcja otwieraj¹ca plik + sprawdza czy uda³o siê go otworzyæ
*@param_in: nazwa pliku, fstream
*/
void otworzPlik(string nazwa, fstream &plik) {
	plik.open(nazwa);
	if (plik.good() == 0) {
		cout << "Nie udalo sie otworzyc pliku!" << endl;
		getchar();
		exit(0);
	}
}

/*
*Funkcja zamykajaca plik
*@param_in: fstream
*/
void zamknijPlik(fstream &plik) {
	plik.close();
}

/*
*Funkcja alokujaca pamiec na tablice dynamiczna i sprawdzajaca czy udalo sie ja zaalokowac
*@param_in: liczba elem
*@return: tablica
*/
string *stworzTablice(int n) {
	string *tab = nullptr;
	try
	{
		tab = new string[n];
	}
	catch (bad_alloc)
	{
		cout << "Nie udalo sie utworzyc tablicy!" << endl;
		getchar();
		exit(0);
	}
	return tab;
}

/*
*Funkcja tworzaca tablice dwuwym dynamiczna
*@param_in: kolumny, wiersze
*@return: tablica dwuwym
*/
int **stworzTablice2D(int w, int k) {
	int **t = NULL;
	try
	{
		t = new int*[w];
	}
	catch (bad_alloc)
	{
		cout << "Brak miejsca na utworzenie tablicy. Koncze program";
		getchar();
		cin.ignore();
		exit(0);
	}
	for (int i = 0; i<w; i++)
		try
	{
		t[i] = new int[k];
	}
	catch (bad_alloc)
	{
		cout << "Brak miejsca na utworzenie tablicy. Koncze program";
		getchar();
		cin.ignore();
		exit(0);
	}
	return t;
}/**Funkcja zwalniajaca pamiec alokowana na tab dynam dwuwym*@param_in: kolumny, tablica*/void usunTablice(int w, int **t)
{
	for (int i = 0; i<w; i++)
		delete[] t[i];
	delete[] t;
}

/*
*Fkcja sprawdzajaca ile wierszy ma plik
*@param_in: fstream, liczba wierszy (poczatkowo zero)
*/
void ileWierszy(fstream &plik, int &liczbaWierszy) {
	string zmienna;
	while (getline(plik, zmienna))++liczbaWierszy;
	plik.clear();
	plik.seekg(0, ios::beg);
}

/*
*Fkcja pobierajaca dane z pliku, wpisujaca je do odpowiednich tablic i wyswietlajaca je
*@param_in: tablica nazw, tablica wag i wartosci, liczba przedmiotow, fstream
*/
void daneZPliku(string *nazwy, int **wagiWartosci, int ile, fstream &plik) {
	for (int i = 0; i < ile; i++)
		plik >> nazwy[i] >> wagiWartosci[0][i] >> wagiWartosci[1][i];
	for (int i = 0; i < ile; i++) {
		cout << nazwy[i] << ' ';
		for (int j = 0; j < 2; j++) {
			cout << wagiWartosci[j][i] << ' ';
		}
		cout << endl;
	}
}

/*
*Fkcja wypelniajaca tablice wartosci najlepszych upakowan i tablice skojarzona z ta poprzednia
*@param_in: liczba przedmiotow, pojemnosc plecaka, tablice z opisu (obie, w kolejnosci)
*/
void wypelnijQPZerami(int ile, int pojem, int **P, int **Q) {
	for (int i = 0; i <= ile; i++) {
		for (int j = 0; j <= pojem; j++) {
			P[i][j] = 0; Q[i][j] = 0;
		}
	}
}

/*
*Fkcja rozwiazujaca problem plecakowy, wysietlajaca tablice tablice wartosci najlepszych upakowan i tablice skojarzona z ta poprzednia
*@param_in: liczba przedmiotow, pojemnosc plecaka, tablica wag i wartosci, tablice z opisu (obie, w kolejnosci)
*/
void algorytmOrazWyswietlanie(int ile, int pojem, int **wagiWartosci, int **P, int **Q) {
	for (int i = 1; i <= ile; ++i) {
		for (int j = 1; j <= pojem; ++j) {
			if ((j >= wagiWartosci[0][i - 1]) && (P[i - 1][j] < (P[i][j - wagiWartosci[0][i - 1]] + wagiWartosci[1][i - 1]))) {
				P[i][j] = P[i][j - wagiWartosci[0][i - 1]] + wagiWartosci[1][i - 1];
				Q[i][j] = i;
			}
			else {
				P[i][j] = P[i - 1][j];
				Q[i][j] = Q[i - 1][j];
			}
		}
	}
	cout << endl;
	for (int i = 0; i <= ile; i++) {
		for (int j = 0; j <= pojem; j++) {
			cout.width(4);
			cout << P[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i <= ile; i++) {
		for (int j = 0; j <= pojem; j++) {
			cout.width(4);
			cout << Q[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

/*
*Fkcja wysietlajaca maksymalna wartosc i sprawdzajaca oraz wyswietlajaca ktore przedmioty wybrac
*@param_in: liczba przedmiotow, pojemnosc plecaka, tablica P, tablica Q, tablica wag i wartosci, tablica nazw
*/
void najlepszaMozliwosc(int ile, int pojem, int **P, int **Q, int **wagiWartosci, string *nazwy) {
	cout << "Maksymalna wartosc przedmiotow: " << P[ile][pojem] << endl;
	while (pojem > 0) {
		cout << nazwy[1, Q[ile][pojem] - 1] << " warta(e/y): " << wagiWartosci[1][Q[ile][pojem] - 1] << endl;
		pojem = pojem - wagiWartosci[0][Q[ile][pojem] - 1];
	}
}
