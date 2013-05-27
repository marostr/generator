#include "aghInclude.h"
absAdvGen::absAdvGen() : absGen() {}

absAdvGen::absAdvGen(int _seed, int _rangeBeg, int _rangeEnd, int _amount) : absGen(_seed, _rangeBeg, _rangeEnd, _amount) {}

absAdvGen::absAdvGen(const absAdvGen &pattern)
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

void absAdvGen::randomize()
{
	for(unsigned int i=0; i<amount; i++)
	{
		srand(seed);
		int x= 167 * ( (unsigned)rand() << 2 ) + (239+i) ;		//bardziej zaawansowany algorytm wykorzystujacy ziarno,
		result[i] = (( x>=0?x:-x) % (rangeEnd-rangeBeg+1) ) + rangeBeg;		//przesuniecie bitowe i zmiane ziarna
		seed += result[i];
	}
}

void absAdvGen::print(std::ostream &out)
{
	out << "#Zaawansowany generator liczb losowych#\n";
	out << "Wylosowane liczby: ";
	for (unsigned i=0; i < amount; i++)
		out << (*this)(i) << " ";
	out << endl;
}
