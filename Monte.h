#ifndef Monte_h
#define Monte_h

#include <iostream>

using namespace std;

template <typename M>
class Monte{
	private:
		M arrayThings[3];
	public:
		Monte();
		Monte(M,M,M);
		void setThing1(M);
		void setThing2(M);
		void setThing3(M);
		void randomize(int);
		M pick(int);
};

#include "Monte.cpp"

#endif
