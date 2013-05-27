#ifndef ABSSYSGEN_H
  #define ABSSYSGEN_H
class absSysGen : public absGen {

public:	
	absSysGen();
	absSysGen(int, int, int, int);
	absSysGen(const absSysGen &);
	
	void randomize();
	void print(std::ostream &out = std::cout);
};

#endif
