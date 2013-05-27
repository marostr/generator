#ifndef ABSGEN_H
  #define ABSGEN_H

class absGen {

protected:
	int seed;
	int rangeBeg;
	int rangeEnd;
	unsigned amount;
	int* result;

public:
	absGen();
	absGen(int, int, int, int);
	virtual ~absGen();	//wirtualny destruktor

	void setBeg(int _rangeBeg) { rangeBeg=_rangeBeg; } //settery, gettery
	void setEnd(int _rangeEnd) { rangeEnd=_rangeEnd; }
	void setSeed(int _seed) { seed=_seed; }
	int getBeg() { return rangeBeg; }
	int getEnd() { return rangeEnd; }
	int getAmount() { return amount; }
	int getSeed() { return seed; }
	int* getResult() { return result; }

	int& operator()(int);

	void setAmount(int);
	virtual void randomize()=0;	//wirtualna, bo kazdy generator inaczej losuje
	virtual void print(std::ostream &out = std::cout)=0; 	//wirtualna, zeby moc wypisywac nazwe generatora
	};

#endif
