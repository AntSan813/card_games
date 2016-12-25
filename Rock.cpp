#ifndef Rock_cpp
#define Rock_cpp

#include <iostream>
#include "Rock.h"

using namespace std;

Rock::Rock(){
	Tool rock;
	type = "Rock";
}
int Rock::fight(Tool *x){
	if(x->getType() == "Rock")
		return 0;
	else if(x->getType() == "Scissor")
		return 1;
	else if(x->getType() == "Paper")
		return 2;
}

#endif
