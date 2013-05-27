#include "aghInclude.h"
absLinGen::absLinGen() : absGen() {}

absLinGen::absLinGen(int _seed, int _rangeBeg, int _rangeEnd, int _amount) : absGen(_seed, _rangeBeg, _rangeEnd, _amount) {}

absLinGen::absLinGen(const absLinGen &pattern)
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

void absLinGen::randomize()
{
	for(unsigned int i=0; i<amount; i++)
	{
		int x = ( (173+i) * ( (seed+i) << 2) + (233+i) ); 	//liniowy algorytm na losowanie, uwzgledniajacy ziarno
		result[i] = ( (x>=0?x:-x ) % (rangeEnd-rangeBeg+1) ) + rangeBeg; 
	}
}

void absLinGen::print(std::ostream &out)
{
	out << "#Liniowy generator liczb losowych#\n";
	out << "Wylosowane liczby: ";
	for (unsigned i=0; i < amount; i++)
		out << (*this)(i) << " ";	
	out << endl;
}
