#include "biblio.h";

int main() {
	fstream plik; int liczbaWierszy = 0, pojem, ile;
	otworzPlik("plik.txt", plik);
	ileWierszy(plik, liczbaWierszy);
	ile = liczbaWierszy - 1;
	plik >> pojem;
	int **P = stworzTablice2D(ile+1, pojem+1), **wagiWartosci = stworzTablice2D(2, ile), **Q = stworzTablice2D(ile + 1, pojem + 1);
	string *nazwy = stworzTablice(ile);
	daneZPliku(nazwy, wagiWartosci, ile, plik);
	zamknijPlik(plik);
	wypelnijQPZerami(ile, pojem, P, Q);
	algorytmOrazWyswietlanie(ile, pojem, wagiWartosci, P, Q);
	najlepszaMozliwosc(ile, pojem, P, Q, wagiWartosci, nazwy);
	usunTablice(ile + 1, P); usunTablice(2, wagiWartosci); usunTablice(ile + 1, Q); delete[] nazwy;
	system("pause");
	return 0;
}
	