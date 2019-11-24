#include "cubo.h"

Cubo::Cubo(int size){
	triangulos.resize(12);
	vertices.resize(8);

	vertices[0].setx(0);
	vertices[0].sety(0);
	vertices[0].setz(0);

	vertices[1].setx(size);
	vertices[1].sety(0);
	vertices[1].setz(0);

	vertices[2].setx(0);
	vertices[2].sety(0);
	vertices[2].setz(-size);

	vertices[3].setx(size);
	vertices[3].sety(0);
	vertices[3].setz(-size);

	vertices[4].setx(0);
	vertices[4].sety(size);
	vertices[4].setz(0);

	vertices[5].setx(size);
	vertices[5].sety(size);
	vertices[5].setz(0);

	vertices[6].setx(0);
	vertices[6].sety(size);
	vertices[6].setz(-size);

	vertices[7].setx(size);
	vertices[7].sety(size);
	vertices[7].setz(-size);

	/*
	v0: abajo frontal izquierda - origen de coordenadas (0,0,0)
	v1: abajo frontal derecha (1,0,0)
	v2: abajo fondo izquierda (0,0,-1)
	v3: abajo fondo derecha  (1,0,-1)

	V4: arriba frontal izquierda (0,1,0)
	v5: arriba frontal derecha (1,1,0)
	v6: arriba fondo izquierda (0,1,-1)
	v7: arriba fondo derecha (1,1,-1)
	*/

	//BASE
	triangulos[0].setv1(0);
	triangulos[0].setv2(2);
	triangulos[0].setv3(1);

	triangulos[1].setv1(2);
	triangulos[1].setv2(3);
	triangulos[1].setv3(1);

	//CARA IZQUIERDA
	triangulos[2].setv1(0);
	triangulos[2].setv2(6);
	triangulos[2].setv3(2);

	triangulos[3].setv1(6);
	triangulos[3].setv2(0);
	triangulos[3].setv3(4);

	//CARA DERECHA
	triangulos[4].setv1(1);
	triangulos[4].setv2(3);
	triangulos[4].setv3(5);

	triangulos[5].setv1(5);
	triangulos[5].setv2(3);
	triangulos[5].setv3(7);

	//CARA FRONTAL
	triangulos[6].setv1(0);
	triangulos[6].setv2(1);
	triangulos[6].setv3(4);

	triangulos[7].setv1(4);
	triangulos[7].setv2(1);
	triangulos[7].setv3(5);

	/*
	v0: abajo frontal izquierda - origen de coordenadas (0,0,0)
	v1: abajo frontal derecha (1,0,0)
	v2: abajo fondo izquierda (0,0,-1)
	v3: abajo fondo derecha  (1,0,-1)

	V4: arriba frontal izquierda (0,1,0)
	v5: arriba frontal derecha (1,1,0)
	v6: arriba fondo izquierda (0,1,-1)
	v7: arriba fondo derecha (1,1,-1)
	*/

	//CARA TRASERA
	triangulos[8].setv1(2);
	triangulos[8].setv2(6);
	triangulos[8].setv3(3);

	triangulos[9].setv1(3);
	triangulos[9].setv2(6);
	triangulos[9].setv3(7);

	//CARA SUPERIOR
	triangulos[10].setv1(4);
	triangulos[10].setv2(5);
	triangulos[10].setv3(6);

	triangulos[11].setv1(6);
	triangulos[11].setv2(5);
	triangulos[11].setv3(7);

}
