#ifndef TEST1_H
	#define TEST1_H
    
    #include "absTest.h"
    
    
class Test1 : public absTest {
/**
* \class klasa testujaca generator losowy
* \author Maniek
* \brief oblicza srednia i mierzy odleglosc od srodka przedzialu
*/
 
 
/**
 * \param diff - roznica sredniej i srodka przedzialu
 */ 
double diff;
 
 public:

/**
* \retrurn pobrana wartosc diff
*/
double get_diff(void) {return diff;};

/**
* \brief testuje wylosowane przez generator liczby, dostajac sie do wskaznika
* \param *gen - wskaznik do generatora
* \retrurn wskaznik poprawnosci testu
*/
double test(absGen *ptr);

/**
* \brief wypisuje rezultat testu na podane wyjscie
* \param &out strumien wyjscia
*/
void print(std::ostream &out);


};



#endif
