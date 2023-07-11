#pragma once
#include "professors.hpp"
#include "mainbase.hpp"

/**
* @brief Funkcja globalna odpowiedzialna za wyœwietlanie du¿ej iloœci tekstu do u¿ytkownika.
* Jest to g³ównie menu.
* 
*/
void menu();

/**
* @brief Funkcja globalna pytaj¹ca u¿ytkownika o dane nowego wyk³adowcy.
* Funkcja pyta u¿ytkownika o dane potrzebne do utworzenia nowego profesora. Nastêpnie wskaŸnik na klasê judge dodaje ostatni¹ zmienn¹ potrzebn¹ do utworzeni czyli punkty Hirsha.
* @return professor
*/
professor askfor();

/**
* @brief G³ówna funkcja programu równie¿ globalna.
* Funkcja s³u¿y do komunikacji z u¿ytkownikiem. Pocz¹tkowo tworzy wskaŸnik na klasê mainbase. PoŸniej w pêtli wyœwiela menu, ¿eby u¿ytkownik móg³ stwierdziæ co chce dalej robiæ.
* @return bool
*/
bool mainProgram();