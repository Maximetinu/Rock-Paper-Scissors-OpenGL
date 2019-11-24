#include "ply.h"
#include <iostream>
#include <string>
#include <vector>
#include "file_ply_stl.h"

Ply::Ply(char* nombreArchivo){

	setPLY(nombreArchivo);

}

void Ply::setPLY(char* nombreArchivo){

	_file_ply file_PLY;

	std::vector <int> triangulos_PLY;
	std::vector <float> vertices_PLY;

	char _nombreArchivo_[256];

	strcpy(_nombreArchivo_ , "modelos_ply/");
	strcat(_nombreArchivo_, nombreArchivo);
	strcat(_nombreArchivo_, ".ply");

	file_PLY.open(_nombreArchivo_);
	file_PLY.read(vertices_PLY,triangulos_PLY);
	file_PLY.close();

	vertices.resize(vertices_PLY.size()/3);
	triangulos.resize(triangulos_PLY.size()/3);

	//Rellenar vector de vértices del Objeto3D
	int j = 0;
	for (int i = 0 ; i < vertices_PLY.size() ; i+=3){
		vertices[j].setx(vertices_PLY[i]);	
		vertices[j].sety(vertices_PLY[i+1]);
		vertices[j].setz(vertices_PLY[i+2]);
		j++;
	}
	
	//Rellenar vector de triángulos del Objeto3D
	j = 0;
	for (int i = 0 ; i < triangulos_PLY.size() ; i+=3){
		triangulos[j].setv1(triangulos_PLY[i]);	
		triangulos[j].setv2(triangulos_PLY[i+1]);
		triangulos[j].setv3(triangulos_PLY[i+2]);
		j++;
	}
}