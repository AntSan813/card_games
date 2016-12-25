#ifndef Scissor_h
#define Scissor_h

#include "Tool.h"
using namespace std;

class Scissor : public Tool{
	public:
		int fight(Tool*);
		Scissor();
};

#endif
