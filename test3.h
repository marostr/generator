#ifndef TEST3_H
	#define TEST3_H
	#include "absTest.h"
	
class Test3 : public absTest {
/**
* \class Test3
* \brief klasa testujaca losowosc liczb metoda znajdywania podciagow bitow i podzialu na klasy
*/


/**
 * \param count[6] - tablica wynikow testu (6 klas podciagu bitowego 1,2,3,4,5,6+ elemtnowego)
 */
int count[6];
//najlepszy stosunek [23-26] : [11-14] : [5-7] : [2,5-4] : [1-2] : [1-2]

/**
* \brief pobiera bit z zadanej pozycji"
* \param *num - liczba z ktorej wyciagamy bit
* \param position - nr bitu liczac od 0 od strony prawej
* \retrurn true - bit 1, false - bit 0
*/
bool get_bit(int num, int position) { return ( 1 & (num >> position) ); }

public: 

/**
* \brief konstruktor bezparametrowy, zeruje tablice wynikow
*/
Test3() { for(int i=0; i<6; i++) this->count[i] = 0; }

/**
* \brief testuje losowsc zadanej proby metoda "Test serii"
* \param *gen - wskaznik do generatora
* \retrurn wskaznik poprawnosci testu
*/
double test(absGen *gen);


/**
* \brief wypisuje rezultat testu na podane wyjscie
* \param &out strumien wyjscia
*/
void print(std::ostream &out);


};	
	
	
#endif
