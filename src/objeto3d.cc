#include "objeto3d.h"

void Objeto3D::dibujar1_5(float r , float g , float b, bool ajedrez){

	glBegin(GL_TRIANGLES);
	for(int i = 0 ; i < triangulos.size() ; i++){
		if (ajedrez && i%2!=0)
			glColor3f(r-0.1 , g-0.1 , b-0.1);
		else
			glColor3f(r , g , b);

		glVertex3f(vertices[ triangulos[i].getv1() ].getx() , vertices[ triangulos[i].getv1() ].gety() , vertices[ triangulos[i].getv1() ].getz());
		glVertex3f(vertices[ triangulos[i].getv2() ].getx() , vertices[ triangulos[i].getv2() ].gety() , vertices[ triangulos[i].getv2() ].getz());
		glVertex3f(vertices[ triangulos[i].getv3() ].getx() , vertices[ triangulos[i].getv3() ].gety() , vertices[ triangulos[i].getv3() ].getz());
	}
	glEnd();



}

void Objeto3D::dibujar2_0(float r , float g , float b, bool ajedrez){
	if (ajedrez)
		dibujar_ajedrez(r , g , b);
	else{
		glColor3f( r , g , b);
		glEnableClientState( GL_VERTEX_ARRAY );
		glVertexPointer( 3, GL_FLOAT, 0, &vertices[0] );
		glDrawElements( GL_TRIANGLES, 3*triangulos.size() , GL_UNSIGNED_INT, &triangulos[0] ) ;
	}
}



void Objeto3D::dibujar_ajedrez(float r, float g, float b){

		std::vector <Triangulo> pares, impares;

		for (int i = 0 ; i < triangulos.size(); i+=2 ){
			pares.push_back(triangulos[i]);
		}
		for (int i = 1 ; i < triangulos.size(); i+=2 ){
			impares.push_back(triangulos[i]);
		}
	
		glColor3f(r , g , b);
		glEnableClientState( GL_VERTEX_ARRAY );
		glVertexPointer( 3, GL_FLOAT, 0, &vertices[0] );
		glDrawElements( GL_TRIANGLES, 3*pares.size() , GL_UNSIGNED_INT, &pares[0] ) ;

		glColor3f(r-0.1 , g-0.1 , b-0.1);
		glEnableClientState( GL_VERTEX_ARRAY );
		glVertexPointer( 3, GL_FLOAT, 0, &vertices[0] );
		glDrawElements( GL_TRIANGLES, 3*impares.size() , GL_UNSIGNED_INT, &impares[0] ) ;

}