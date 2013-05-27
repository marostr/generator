#include "aghInclude.h"

double Test3::test(absGen *gen)
{
bool bit;
bool series;
int length=0; //poczatkowa dlugosc to 0
int num;	

bit = get_bit(*(gen->getResult()), 0); 

	
for(int i=0; i< gen->getAmount(); ++i) // dla kazdej liczby z tablicy
{
num = *(gen->getResult()+i); //zapisuje do zmiennej liczbe  z ktorej wyciagamy bity
	   
   for(unsigned int nbit=0; nbit<sizeof(int)*8; ++nbit)
   {
	 //jesli mamy taki sam bit jak ostatnio  ((1&1)=1, (1&0)=0), to zwieksz dlugosc
	 //jak nie to zmien ostatni bit, zlam serie
	 if(  get_bit(num,nbit) == bit ) length++;
	 else { series = false; bit=!bit; }
	  
	  
	 if(series == false) //jesli skonczyla sie seria:
	 {                    //zaleznie od dlugosci serii dolicza do odpowiedniej klasy
	  if(length == 1) (this->count[0])++;
	  else if(length == 2)  (this->count[1])++;
	  else if(length == 3)  (this->count[2])++;
	  else if(length == 4)  (this->count[3])++;
	  else if(length == 5)  (this->count[4])++;
	  else 	(this->count[5])++;
		
	  length=1;	//jeden bit juz jest pojedynczym ciagiem
	  series=true;
     }
	}
}	 
return 0;	  
}


void Test3::print(std::ostream &out)
{
out << "#BITOWY_TEST#: (liczebnosc podciagow n-bitowych, [n_elementow]liczebnosc_klasy)\n";
out << "[1]"<<count[0]<<"  [2]"<<count[1]<<"  [3]"<<count[2]<<"  [4]"<<count[3]<<"  [5]"<<count[4]<<"  [6+]"<<count[5]<<std::endl;
}
