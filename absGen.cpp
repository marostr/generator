#include "aghInclude.h"

absGen::absGen()
{
	seed = 0;
	rangeBeg = 0;
	rangeEnd = 0;
	amount = 0;
	result = NULL;
}

absGen::absGen(int _seed, int _rangeBeg, int _rangeEnd, int _amount) : seed(_seed), rangeBeg(_rangeBeg), rangeEnd(_rangeEnd), amount(_amount)
{
	if (_rangeBeg > _rangeEnd) throw aghException(-1, "Wrong range!");
	result = new int[_amount];
}

absGen::~absGen()
{
	delete [] result;
	result = NULL;
}

void absGen::setAmount(int _amount)
{
amount = _amount;	//zmiana ilosci losowan
delete [] result;
result = new int [amount];	//powiekszanie tablicy
}

int& absGen::operator()(int i)
{
	if (i >= amount) throw aghException(-1, "Index out of range!")
	return this->result[i];
}

