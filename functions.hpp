#pragma once
#include "professors.hpp"
#include "mainbase.hpp"

/**
* @brief Funkcja globalna odpowiedzialna za wy�wietlanie du�ej ilo�ci tekstu do u�ytkownika.
* Jest to g��wnie menu.
* 
*/
void menu();

/**
* @brief Funkcja globalna pytaj�ca u�ytkownika o dane nowego wyk�adowcy.
* Funkcja pyta u�ytkownika o dane potrzebne do utworzenia nowego profesora. Nast�pnie wska�nik na klas� judge dodaje ostatni� zmienn� potrzebn� do utworzeni czyli punkty Hirsha.
* @return professor
*/
professor askfor();

/**
* @brief G��wna funkcja programu r�wnie� globalna.
* Funkcja s�u�y do komunikacji z u�ytkownikiem. Pocz�tkowo tworzy wska�nik na klas� mainbase. Po�niej w p�tli wy�wiela menu, �eby u�ytkownik m�g� stwierdzi� co chce dalej robi�.
* @return bool
*/
bool mainProgram();