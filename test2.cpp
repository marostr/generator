#include "aghInclude.h"


void Test2::sort(int *array,int size)
{
int max;
int max_i;

//if(size<=0) throw aghException(1,"size <= 0 !");

for(int i=0; i<size; ++i)
{
max=array[i];		
max_i=i;
	for(int d=i+1; d<size; d++)
	{
		if(array[d]>=max) 
		{
			max=array[d];
			max_i=d;
		}
	}
int tmp;
tmp=array[i];
array[i]=array[max_i];
array[max_i]=tmp;
}


}


void Test2::print(std::ostream &out)
{
out << "#MEDIANA_TEST#: (mediana odleglosci pomiedzy kolejnymi liczbami)\n";
out << "mediana: " << this->median << "  wart. oczekiwana: " <<this->width << "  max. odlegl. :"<<this->maxwidth<<"\n";	

}

double Test2::test(absGen *gen)
{

int *temp = new int[gen->getAmount()]; //wywoluje tablice tymczasowa zeby nie psuc sortowaniem bazowej	

//if(temp==NULL) throw aghException(0,"MemAllocFailed!");

for(int i=0; i<gen->getAmount(); i++)
temp[i] = * ( gen->getResult() + i);	
this->sort(temp, gen->getAmount() ); //sortuje ja, do liczenia odleglosci miedzy liczbami
	

int x;
//od teraz tablica temp bedzie tablica odleglosci
for(int i=0; i<gen->getAmount() - 1; i++)
	{
		x= temp[i]-temp[i+1];
		temp[i]=(x>=0?x:-x); //wart. bezwzgl.
	}
this->sort(temp,gen->getAmount()-1); //od teraz odleglosci sa tylko w n-1 elementach
								      //sortowanie do liczenia mediany
this->maxwidth = temp[0]; //najdluzszy przedzial

if( (gen->getAmount()-1)%2 == 0) this->median=(temp[(gen->getAmount()-1)/2]+temp[(gen->getAmount()-1)/2-1])/2; //znajdywanie mediany
else this->median=temp[(gen->getAmount()-1)/2];

delete [] temp;	


this->width= (( double)gen->getEnd() - (double)gen->getBeg())/ ((double)gen->getAmount() + 1); //szerokosc calk. / ilosc licz+1


return this->width - this->median;
}
