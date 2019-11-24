#include "tetraedro.h"
#include <cmath>

Tetraedro::Tetraedro(int lado){
	triangulos.resize(4);
	vertices.resize(4);

	vertices[0].setx(-lado/2);
	vertices[0].sety(0);
	vertices[0].setz(0);

	vertices[1].setx(lado/2);
	vertices[1].sety(0);
	vertices[1].setz(0);

	vertices[2].setx(0);
	vertices[2].sety(0);
	vertices[2].setz(-sqrt(lado*lado+(lado/2)*(lado/2)));

	vertices[3].setx(0);
	vertices[3].sety(sqrt(lado*lado+(lado/2)*(lado/2)));
	vertices[3].setz(-sqrt(lado*lado+(lado/2)*(lado/2))/2);

	/*
	v0: LADO IZQUIERDA	(-lado, 0 , 0)
	v1: LADO DERECHA	(lado, 0, 0)
	v2: FONDO			(0 , 0 , X)
	v3: PICO			(0, X, 0)
	H²=A²+B²
	X=sqrt(a*a+a/2*a/2)

	Vale, tras mucho pensar, creo que al final no es un tetraedro regular. Pero bueno, tetraedro es.
	
	*/

	//CARA FRONTAL
	triangulos[0].setv1(0);
	triangulos[0].setv2(1);
	triangulos[0].setv3(3);

	//CARA IZQUIERDA
	triangulos[1].setv1(3);
	triangulos[1].setv2(2);
	triangulos[1].setv3(0);

	//CARA DERECHA
	triangulos[2].setv1(3);
	triangulos[2].setv2(1);
	triangulos[2].setv3(2);

	//BASE
	triangulos[3].setv1(0);
	triangulos[3].setv2(2);
	triangulos[3].setv3(1);
}