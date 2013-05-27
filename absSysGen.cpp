#include "aghInclude.h"
absSysGen::absSysGen() : absGen() {	srand( time(NULL) ); }

absSysGen::absSysGen(int _seed, int _rangeBeg, int _rangeEnd, int _amount) : absGen(_seed, _rangeBeg, _rangeEnd, _amount) {	srand( time(NULL) );} //ustawienia licznika losowania na podstawie czasu z komputera

absSysGen::absSysGen(const absSysGen &pattern)
{
	seed = pattern.seed;
	rangeBeg = pattern.rangeBeg;
	rangeEnd = pattern.rangeEnd;
	amount = pattern.amount;
	delete [] result;
	result = new int [amount];
	
	for (unsigned int i=0; i<amount; i++)
	{
		result[i] = pattern.result[i];
	}
}

void absSysGen::randomize()
{
	for(unsigned int i=0; i<amount; i++)
	{
		int x= (rand()+seed);		//systemowy generator liczb wykorzystujący ziarno
		result[i] =  ( (x>=0?x:-x ) % (rangeEnd-rangeBeg+1) ) + rangeBeg; 
	}
}

void absSysGen::print(std::ostream &out)
{
	out << "#Systemowy generator liczb losowych#\n";
	out << "Wylosowane liczby: ";
	for (unsigned i=0; i < amount; i++)
		out << (*this)(i) << " ";
	out << endl;
}
