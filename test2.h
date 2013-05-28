#ifndef TEST2_H
	#define TEST2_H
	
/**
* \class klasa test dla generatora liczb
* \brief klasa sprawdzajaca roznice pomiedzy mediana odleglosci pomiedzy liczbami
* \brief a srednia szerokoscia przedzialu
*/	
	
class Test2 : public absTest {

/**
 \param median - mediana odleglosci pomiedzy testowanymi liczbami
 \param width - szerokosc przedzialu dla rownomiernego rozkladu
 \param maxwidth - maxymalna zanotowana szerokosc
*/
double median;
double width;
double maxwidth;

/**
 * \brief sortuje tablice podana jako argument
 * \param *array - wskaznik do tablicy
 * \param size - rozmiar tablicy
 */
void sort(int* array, int size);

public:

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

/**
 * \brief metoda pobiera wyliczona mediane
 */
double get_median(void) { return median; };
		
};	
	
#endif
