#ifndef Marble_cpp
#define Marble_cpp

#include "Marble.h"
#include <iostream>
#include <string>

using namespace std;

Marble::Marble(){}
Marble::Marble(string c){
	color = c;
}

void Marble::setColor(string c){
	color = c;
}

string Marble::getColor(){
	return color;
}

#endif
