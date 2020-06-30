/** @file */

#ifndef FUNKCJE_H
#define FUNKCJE_H

#include <stdio.h>
#include <stdlib.h>
// #include <crtdbg.h>

/** Wezel listy liter **/
typedef struct slowo{
    char litera; ///litera
    struct slowo* pPrev; ///wskaznik na poprzedni¹ literê
    struct slowo* pNext; ///wskaznik na nastêpn¹ literê
} slowo_type;

/** Wezel listy s³ów **/
typedef struct slowa{
    slowo_type* wyraz; ///wskaznik na listê liter
    struct slowa* pNext; ///wskaznik na nastêpne s³owo
} slowa_type;

/**
Funkcja dodaje literê do listy liter
@oparam[in, out] head wskaznik na pierwszy wezel listy
@oparam[in, out] tail wskaznik na ostatni wezel listy
@param literka litera ktora chcemy dodaæ do listy
*/
void pushback(slowo_type **head, slowo_type **tail, char literka);
/**
Funkcja porownuje dwie listy liter
@oparam[in, out] head1 wskaznik na pierwszy wezel pierwszej listy
@oparam[in, out] head2 wskaznik na pierwszy wezel drugiej listy
@return funkcja zwraca 1 jeœli drugie slowo jest po pierwszym alfabetycznie
*/
int porownanie(slowo_type *head1, slowo_type *head2);
/**
Funkcja dodaje slowo do listy slow
@oparam[in, out] glowa wskaznik na pierwszy wezel listy
@oparam[in, out] wyrazik wskaznik na liste liter
*/
void dodaj(slowa_type **glowa, slowo_type* wyrazik);
/**
Funkcja wypisuje listê slow do pliku wyjsciowego
@oparam[in, out] glowa wskaznik na pierwszy wezel listy
@param output nazwa pliku wyjsciowego
*/
void drukarka(slowa_type *glowa, char* output);
/**
Funkcja sprawdza czy slowo jest palindromem
@oparam[in, out] glowa wskaznik na pierwszy wezel listy
@oparam[in, out] ogon wskaznik na ostatni wezel listy
@return funkcja zwraca 1 jeœli slowo jest palindromem
*/
int palindrom(slowo_type *glowa, slowo_type *ogon);
/**
Funkcja kopiuje slowo ze zrodla do celu
@param destination docelowe s³owo
@param source slowo zrodlowe
*/
void zamiana(char* destination, const char* source);
/**
Funkcja sprawdza czy dwa slowa sa identyczne
@param string1 pierwsze slowo
@param string2  drugie slowo
@return funkcja zwraca 1 jeœli slowa sa identyczne
*/
int moje_strcmp(char string1[], char string2[] );
/**
Funkcja usuwa liste liter
@oparam[in, out] glowa wskaznik na liste liter
*/
void zwolnij1(slowa_type *glowa);
/**
Funkcja usuwa listê slow
@oparam[in, out] glowa wskaznik na liste slow
*/
void zwolnij2(slowo_type *glowa);

#endif
