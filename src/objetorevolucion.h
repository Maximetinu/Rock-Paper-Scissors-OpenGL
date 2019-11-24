#ifndef _OBJETOREVOLUCION_H_
#define _OBJETOREVOLUCION_H_

#include "objeto3d.h"
#include "ply.h"

class ObjetoRevolucion : public Objeto3D {
private:
	std::vector <std::vector<float> > matrizTransformacion;
	int lados;
	int tamano_perfil;
public:
	ObjetoRevolucion(Ply& objetoPLY, int lados);
	Punto punto_por_matriz(Punto p_a_rotar);
	void inicializarMatriz(double ang);
	void rotarPuntos();
	void crearCaras();
	void crearTapas();
};

#endif