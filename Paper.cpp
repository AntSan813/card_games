#ifndef Paper_cpp
#define Paper_cpp

#include <iostream>
#include "Paper.h"

using namespace std;

Paper::Paper(){
	Tool paper;
	type = "Paper";
}
int Paper::fight(Tool* x){
	if(x->getType() == "Paper")
                return 0;
        else if(x->getType() == "Rock")
                return 1;
        else if(x->getType() == "Scissor")
                return 2;
	
}

#endif
