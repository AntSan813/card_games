#ifndef Monte_cpp
#define Monte_cpp

#include "Monte.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;

template <typename M>
Monte<M>::Monte(){}
template <typename M>
Monte<M>::Monte(M t1, M t2, M t3){
	arrayThings[0] = t1;
	arrayThings[1] = t2;
	arrayThings[2] = t3;		
}

template <typename M>
void Monte<M>::setThing1(M t1){
	arrayThings[0] = t1;
}

template <typename M>
void Monte<M>::setThing2(M t2){
	arrayThings[1] = t2;
}

template <typename M>
void Monte<M>::setThing3(M t3){
	arrayThings[2] = t3;
}

template <typename M>
void Monte<M>::randomize(int x){
	int position;
	M temp;
	for(int i = 0; i < 7; i++){
		position = rand()%3;
		temp = arrayThings[x];
		arrayThings[x] = arrayThings[position];
		arrayThings[position] = temp;
	}
}

template <typename M>
M Monte<M>::pick(int x){
	return arrayThings[x];

}

#endif
