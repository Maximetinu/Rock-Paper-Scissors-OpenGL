#include "punto.h"

Punto::Punto(){
}

void Punto::setx(float x_){
	x = x_;
}
void Punto::sety(float y_){
	y = y_;
}
void Punto::setz(float z_){
	z = z_;
}

float Punto::getx(){
	return x;
}
float Punto::gety(){
	return y;
}
float Punto::getz(){
	return z;
}