#include "objetorevolucion.h"
#include <cmath>
#include "file_ply_stl.h"
#include <string>
#include <iostream>

using namespace std;

ObjetoRevolucion::ObjetoRevolucion(Ply& objetoPLY, int lados_){
	
	vertices=objetoPLY.vertices;
	triangulos=objetoPLY.triangulos;
	lados = lados_;
	tamano_perfil = vertices.size();

	double angulo = (2*M_PI)/lados;
	inicializarMatriz(angulo);

	//Rotamos los puntos
	rotarPuntos();
	crearCaras();
	crearTapas();
}

void ObjetoRevolucion::rotarPuntos(){
	Punto p_aux;
	vector <Punto> perfil_auxiliar = vertices;
	for(int i = 0 ; i < lados ; i++){
		for (int j = 0 ; j < tamano_perfil ; j++){
			p_aux = punto_por_matriz(perfil_auxiliar[j]);
			vertices.push_back(p_aux);
			perfil_auxiliar[j] = p_aux;
		}
	}
}

void ObjetoRevolucion::crearCaras(){
	Triangulo tri_aux;
	for (int i = 0 ; i < lados ; i++){
		unsigned int inicioPerfil, finPerfil;
        inicioPerfil = i * tamano_perfil;
        finPerfil = inicioPerfil + tamano_perfil;

        for (unsigned int i = inicioPerfil+1, k = finPerfil+1; i < finPerfil; i++, k++){
        	tri_aux.setv1(i-1);
        	tri_aux.setv2(k-1);
        	tri_aux.setv3(k);
        	triangulos.push_back(tri_aux);
        	tri_aux.setv1(i-1);
        	tri_aux.setv2(k);
        	tri_aux.setv3(i);
       		triangulos.push_back(tri_aux);
		}
	}
}

void ObjetoRevolucion::crearTapas(){
	Punto central;
	Triangulo tapa_aux;
	//Si primera x=0,como estamos rotando en el eje Y significa que no le hace falta tapa de abajo
	if (vertices.front().getx()){
    
     	Triangulo tapa_aux;
     	central.setx(0.0);
     	central.sety(vertices.front().gety());
     	central.setz(0.0);
    	vertices.push_back(central);

    	for (int i = 0; i < lados; i++){
     		int perfilactual = i * tamano_perfil;
     		int siguientePerfil = perfilactual + tamano_perfil;
     		tapa_aux.setv1(vertices.size()-1);
     		tapa_aux.setv2(siguientePerfil);
     		tapa_aux.setv3(perfilactual);
     		triangulos.push_back(tapa_aux);
     	}
    }
    //Si ultima x del perfil =0,como estamos rotando en el eje Y significa que no le hace falta tapa de arriba
    if (vertices[tamano_perfil-1].getx()){

    	central.setx(0.0);
    	central.sety(vertices[tamano_perfil-1].gety());
    	central.setz(0.0);
    	vertices.push_back(central); 

    	for (int i =0; i<lados; i++){
     		int perfilactual = (i+1) * tamano_perfil -1;
     		int siguientePerfil = perfilactual + tamano_perfil;
     		tapa_aux.setv1(vertices.size()-1);
     		tapa_aux.setv2(perfilactual);
     		tapa_aux.setv3(siguientePerfil);
     		triangulos.push_back(tapa_aux);
     	}
    }	
}

Punto ObjetoRevolucion::punto_por_matriz(Punto p_a_rotar){
	Punto p;

	p.setx(		p_a_rotar.getx()*matrizTransformacion[0][0]+
				p_a_rotar.gety()*matrizTransformacion[1][0]+
				p_a_rotar.getz()*matrizTransformacion[2][0]);

	p.sety(		p_a_rotar.getx()*matrizTransformacion[0][1]+
				p_a_rotar.gety()*matrizTransformacion[1][1]+
				p_a_rotar.getz()*matrizTransformacion[2][1]);

	p.setz(		p_a_rotar.getx()*matrizTransformacion[0][2]+
				p_a_rotar.gety()*matrizTransformacion[1][2]+
				p_a_rotar.getz()*matrizTransformacion[2][2]);

	return p;
}

void ObjetoRevolucion::inicializarMatriz(double ang){
	matrizTransformacion.resize(3);
	matrizTransformacion[0].resize(3);
	matrizTransformacion[1].resize(3);
	matrizTransformacion[2].resize(3);

	matrizTransformacion[0][0] =  cos(ang) 	;
	matrizTransformacion[0][1] =  0 			;
	matrizTransformacion[0][2] = -sin(ang) 	;
	matrizTransformacion[1][0] =  0				;
	matrizTransformacion[1][1] =  1				;
	matrizTransformacion[1][2] =  0				;
	matrizTransformacion[2][0] =  sin(ang)	;
	matrizTransformacion[2][1] =  0				;
	matrizTransformacion[2][2] =  cos(ang) 	;
}