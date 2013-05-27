/**
* \file absTest.h
* \author Maniek
* \version 0.1
* \brief Zawiera klasę abstrakcyjną test 
*/



#ifndef ABSTEST_H
	#define ABSTEST_H
	
	#include <ostream>
	
/**
* \class absTest
* \author Maniek
* \brief klasa abstrakcyjna test
*/

class absTest {
 
 
 public:
 
/** 
* \brief ustawia parametry za pomoca wew. metod generatora
* \param *gen - wskaznik do generatora
* \param seed - nasiono
* \param amount - ile losujemy liczb
* \param rangex1 - dolny zakres przedzialu losowania
* \param rangex2 - gorny zakres przedzialu losowania
*/
void set_gen(absGen *gen, int seed, int amount, int rangex1, int rangex2)
{
gen->setBeg(rangex1);
gen->setEnd(rangex2);
gen->setSeed(seed);
gen->setAmount(amount);
}

/**
* \brief testuje wylosowane przez generator liczby, dostajac sie do wskaznika
* \param *gen - wskaznik do generatora
* \retrurn wskaznik poprawnosci testu
*/
virtual double test(absGen *gen) = 0;


/**
* \brief wypisuje rezultat testu na podane wyjscie
* \param &out strumien wyjscia
*/
virtual void print(std::ostream &out) =0;


};




#endif



