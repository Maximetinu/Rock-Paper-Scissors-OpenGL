#include "piramide.h"

Piramide::Piramide(int base, int altura){
	triangulos.resize(6);
	vertices.resize(5);

	vertices[0].setx(0);
	vertices[0].sety(0);
	vertices[0].setz(0);

	vertices[1].setx(base);
	vertices[1].sety(0);
	vertices[1].setz(0);

	vertices[2].setx(0);
	vertices[2].sety(0);
	vertices[2].setz(base);

	vertices[3].setx(base);
	vertices[3].sety(0);
	vertices[3].setz(base);

	vertices[4].setx(base/2);
	vertices[4].sety(altura);
	vertices[4].setz(base/2);

	/*
	v0: frontal izquierda (0,0,0) ORIGEN COORDENADAS ESQUINA IZQUIERDA DELANTERA
	v1: frontal derecha (1,0,0) ESQUINA DERECHA DELANTERA
	v2: fondo izquierda (0,0,1) ESQUINA IZQUIERDA TRASERA
	v3: fondo derecha (1,0,1) ESQUINA DERECHA TRASERA
	v4: pico (0.5,H,0.5)
	*/

	//BASE
	triangulos[0].setv1(0);
	triangulos[0].setv2(1);
	triangulos[0].setv3(2);

	triangulos[1].setv1(2);
	triangulos[1].setv2(1);
	triangulos[1].setv3(3);

	//CARA IZQUIERDA
	triangulos[2].setv1(4);
	triangulos[2].setv2(2);
	triangulos[2].setv3(0);

	//CARA DERECHA
	triangulos[3].setv1(4);
	triangulos[3].setv2(1);
	triangulos[3].setv3(3);

	//CARA FRONTAL
	triangulos[4].setv1(4);
	triangulos[4].setv2(0);
	triangulos[4].setv3(1);

	//CARA TRASERA
	triangulos[5].setv1(4);
	triangulos[5].setv2(3);
	triangulos[5].setv3(2);
}