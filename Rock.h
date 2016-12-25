#ifndef Rock_h
#define Rock_h

#include "Tool.h"
using namespace std;

class Rock : public Tool{
	public:
		int fight(Tool*);
		Rock();
};

#endif
