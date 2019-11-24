#include "triangulo.h"

#include "triangulo.h"

Triangulo::Triangulo(){
}

void Triangulo::setv1(int v1_){
	v1 = v1_;
}
void Triangulo::setv2(int v2_){
	v2 = v2_;
}
void Triangulo::setv3(int v3_){
	v3 = v3_;
}

int Triangulo::getv1(){
	return v1;
}
int Triangulo::getv2(){
	return v2;
}
int Triangulo::getv3(){
	return v3;
}