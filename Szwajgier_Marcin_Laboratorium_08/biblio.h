#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void otworzPlik(string nazwa, fstream &plik);
void zamknijPlik(fstream &plik);
string *stworzTablice(int n);
int **stworzTablice2D(int w, int k);
void usunTablice(int w, int **t);
void ileWierszy(fstream &plik, int &liczbaWierszy);
void daneZPliku(string *nazwy, int **wagiWartosci, int ile, fstream &plik);
void wypelnijQPZerami(int ile, int pojem, int **P, int **Q);
void algorytmOrazWyswietlanie(int ile, int pojem, int **wagiWartosci, int **P, int **Q);
void najlepszaMozliwosc(int ile, int pojem, int **P, int **Q, int **wagiWartosci, string *nazwy);

