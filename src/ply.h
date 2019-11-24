#ifndef _PLY_H_
#define _PLY_H_

#include "objeto3d.h"

class Ply : public Objeto3D{
public:
	Ply(char* nombreArchivo);
	void setPLY(char* nombreArchivo);
};

#endif