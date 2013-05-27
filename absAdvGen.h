#ifndef ABSADVGEN_H
  #define ABSADVGEN_H
class absAdvGen : public absGen {

public:	
	absAdvGen();
	absAdvGen(int, int, int, int);
	absAdvGen(const absAdvGen &);
	
	void randomize();
	void print(std::ostream &out = std::cout);
};

#endif
