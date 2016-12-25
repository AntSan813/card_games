#ifndef Tool_h
#define Tool_h

#include <iostream>

using namespace std;

class Tool{
	public: 
		string type;
		Tool();
		string getType();
		virtual int fight(Tool*);

};

#endif
