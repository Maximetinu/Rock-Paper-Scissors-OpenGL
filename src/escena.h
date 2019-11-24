#ifndef _ESCENA_H
#define _ESCENA_H
#include <string>
using namespace std;

class Escena {
private:

// variables que definen la posicion de la camara en coordenadas polares
GLfloat Observer_distance;
GLfloat Observer_angle_x;
GLfloat Observer_angle_y;

// variables que controlan la ventana y la transformacion de perspectiva
GLfloat Width,Height,Front_plane,Back_plane;

int mode;
bool ajedrez;
int figura;
float R, G, B;
int grueso;
int escala;
int dedo;
float angulo_codo_x, angulo_codo_y;


private:
	void clear_window();
	void draw_objects();
	void cambiarPincel();

	//Transformación de cámara
	void change_projection();
	void change_observer();


public:
     Escena();
	void inicializar(int UI_window_width,int UI_window_height);
	void redimensionar(int newWidth,int newHeight) ;

	void dibujar() ;

	// Interacción con la escena
	int teclaPulsada(unsigned char Tecla1,int x,int y) ;
	void teclaEspecial(int Tecla1,int x,int y);


};
#endif