#ifndef Rps.h
#define Rps.h

#include "Tool.h"
#include <iostream>
#include <string>

using namespace std;

class Rps : public Tool{
	public: 
		int fight(Tool*);					
		void setType(string typ);
		

};	

#endif
