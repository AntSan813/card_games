#ifndef Scissor_cpp
#define Scissor_cpp

#include <iostream>
#include "Scissor.h"

using namespace std;

Scissor::Scissor(){
	Tool scissor;
	type = "Scissor";

}
int Scissor::fight(Tool* x){
	if(x->getType() == "Scissor")
                return 0;
        else if(x->getType() == "Paper")
                return 1;
        else if(x->getType() == "Rock")
                return 2;

}

#endif
