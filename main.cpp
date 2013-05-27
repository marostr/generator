#include "aghInclude.h"
int main()
{
	absLinGen glin;
	absSysGen gsys;
	absAdvGen gadv;
	
	Test1 t;
	Test2 tt;
	Test3 ttt;
	
	absGen *gptr[3] = { &glin, &gsys, &gadv};
	absTest *tptr[3] = { &t, &tt, &ttt };
	
	std::fstream plik_wyniki;
	std::fstream plik_liczby;


plik_wyniki.open("wyniki.txt", ios::out);
if(plik_wyniki.good() == false) {std::cout<<"blad otwierania pliku wyniki testow!"; return -1;}
plik_liczby.open("liczby.txt", ios::out);
if(plik_liczby.good() == false) {std::cout<<"blad otwierania pliku liczby!"; return -1;}





for(int g=0; g<3; g++)
{
plik_wyniki<<"Generator["<<g+1<<"]\n";
std::cout<<"Generator["<<g+1<<"]\n";
    for(int t=0; t<3; t++)
	{
	tptr[t]->set_gen(gptr[g], -7, 10, 0,100 );
	gptr[g]->randomize();
	
	tptr[t]->test(gptr[g]);
	
	tptr[t]->print(std::cout);
	tptr[t]->print(plik_wyniki);
	}	
plik_wyniki<<"\n\n";
std::cout<<"\n\n";
}	

for(int i=0; i<3; i++)
{
gptr[i]->print(std::cout); std::cout<<std::endl;
gptr[i]->print(plik_liczby); plik_liczby<<std::endl<<std::endl;
}
plik_wyniki.close();
plik_liczby.close();
	
	
}
