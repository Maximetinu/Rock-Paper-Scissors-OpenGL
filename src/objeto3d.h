#ifndef _OBJETO3D_H
#define _OBJETO3D_H
#include <vector>
#include "triangulo.h"
#include "punto.h"
#include <GL/gl.h>
    #include <GL/glut.h>

class Objeto3D{

public:

	std::vector <Triangulo> triangulos;
	std::vector <Punto> vertices;

	void dibujar1_5(float r , float g , float b , bool ajedrez);
	void dibujar2_0(float r , float g , float b , bool ajedrez);
	void dibujar_ajedrez(float r, float g, float b);

	
};
#endif