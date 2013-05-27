#include "aghInclude.h"



double Test1::test(absGen *gen)
{
int sum=0;	
int* array = gen->getResult();	
	
for(int i=0; i<gen->getAmount(); i++)
	sum=sum + array[i];
	
double diff = ((double)sum/((double)gen->getAmount())) - 
((double)(gen->getEnd()-gen->getBeg())/2+(double)gen->getBeg()); // odleglosc od srodka przedzialu losowania

this->diff = diff;
return diff;
}


void Test1::print(std::ostream &out) 
{
out << "#SREDNIA_TEST#: (roznica srodka przedzialu i sredniej)\n";
out << "odleglosc: "<< this->get_diff() << "\n";

}
	
	 

