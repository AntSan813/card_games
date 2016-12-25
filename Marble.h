#ifndef Marble_h
#define Marble_h

#include <iostream>
#include <string>
using namespace std;

class Marble{
	protected:
		string color;
	public:
		Marble();	
		Marble(string);
		void setColor(string);
		string getColor();
};

#endif
