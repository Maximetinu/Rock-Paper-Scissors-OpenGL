#ifndef _TRIANGULO_H
#define _TRIANGULO_H

#include "punto.h"
#include <vector>

class Triangulo{

private:
	int v1, v2, v3;

public:
	Triangulo();

	void setv1( int v1_);
	void setv2( int v2_);
	void setv3( int v3_);

	int getv1();
	int getv2();
	int getv3();
};
#endif