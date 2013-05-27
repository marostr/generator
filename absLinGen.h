#ifndef ABSLINGEN_H
  #define ABSLINGEN_H
class absLinGen : public absGen {

public:	
	absLinGen();
	absLinGen(int, int, int, int);
	absLinGen(const absLinGen &);
	
	void randomize();	
	void print(std::ostream &out = std::cout);	//wypisywanie, default - na ekran
};

#endif
