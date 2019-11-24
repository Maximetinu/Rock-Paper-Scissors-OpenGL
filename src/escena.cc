#include <cstdio>
#include <iostream>
#include <GL/gl.h>
    #include <GL/glut.h>
#include "escena.h"
#include "ejes.h"
#include "cubo.h"
#include "piramide.h"
#include "tetraedro.h"
#include "ply.h"
#include "objetorevolucion.h"
#include "brazo.h"

// DEFINIR VERSIÓN 1 PARA DIBUJAR EN 1.5 O VERSION 2 PARA DIBUJAR EN 2.0
#define version 2

//INICIALIZAR TAMAÑOS DE LAS FIGURAS
Ejes ejes;
Cubo cubo(40);
Tetraedro tetraedro(40);
Piramide piramide(40, 40);
char n_A_[256] = "perfil";
Ply objetoPLY(n_A_);
ObjetoRevolucion objRevol(objetoPLY, 8);
Brazo brazo;
Brazo brazo2;

Escena::Escena(){
    Front_plane=50;
    Back_plane=2000;
    Observer_distance = 4*Front_plane;
    Observer_angle_x = Observer_angle_y=0;
}



void Escena::inicializar(int UI_window_width,int UI_window_height) {

    mode = 1;
    ajedrez = false;
    figura = 6;
    R=0.35; G=0.35; B=0.35;
    grueso=1.0;
    escala = 1;
    dedo=0;

	glClearColor(1,1,1,1);

	glEnable(GL_DEPTH_TEST);	
    glEnable(GL_CULL_FACE);

	this->change_projection();
	Width=UI_window_width/10;
	Height=UI_window_height/10;
	glViewport(0,0,UI_window_width,UI_window_height);

}


//**************************************************************************
// Funcion que dibuja objetos en la escena
//***************************************************************************

void Escena::draw_objects() {
    switch(figura){
        case 1:
            if (version == 1)
                cubo.dibujar1_5(R , G , B , ajedrez);
           else
                cubo.dibujar2_0(R , G , B , ajedrez);
        break;
        case 2:
            if (version == 1)
                tetraedro.dibujar1_5(R, G, B, ajedrez);
            else
                tetraedro.dibujar2_0(R, G, B, ajedrez);
        break;
        case 3:
            if (version == 1)
                piramide.dibujar1_5(R, G, B, ajedrez);
            else
                piramide.dibujar2_0(R, G, B, ajedrez);
        break; 
        //glScalef porque el perfil.ply se ve demasiado pequeño, ni siquiera alcanza el zoom
        case 4: //glScalef(20,20,20); 
            if (version == 1)
                objetoPLY.dibujar1_5(R, G, B, ajedrez);
            else
                objetoPLY.dibujar2_0(R, G, B, ajedrez);
        break;
        case 5: glScalef(20,20,20);
            if (version == 1)
                objRevol.dibujar1_5(R, G, B, ajedrez);
            else
                objRevol.dibujar2_0(R, G, B, ajedrez);
        break;
        case 6:
            glScalef(0.4,0.4,0.4);
            glRotatef(45,0,1,0);
            glRotatef(-50,0,0,1);
            glTranslatef(-350,0,0);                
                brazo.dibujar();
        break;
        case 7:
                glScalef(0.5,0.5,0.5);
            glPushMatrix();
                glTranslatef(-275,0,0);
                glColor3f(0.6,0,0);
                brazo.manoPPT();
            glPopMatrix();
            glPushMatrix();
                glScalef(-1,1,1);
                glTranslatef(-275,0,0);
                glColor3f(0,0,0.5);
                glDisable(GL_CULL_FACE);
                brazo2.manoPPT();
                glEnable(GL_CULL_FACE);
            glPopMatrix();
        break;
    }
}


void Escena::dibujar() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); // Limpiar la pantalla
	change_observer();

    glLineWidth(1);
	ejes.draw_axis();

    cambiarPincel();
	draw_objects();
}

int Escena::teclaPulsada(unsigned char Tecla1,int x,int y) {

    std::cout << "Tecla " << Tecla1<< std::endl;
    switch (/*toupper*/(Tecla1)){
    	case 'Q': return 1;
    		break;
    	// MODO PUNTOS
    	case 'P': 	mode = 0;
    		break;
    	// MODO ALAMBRE
    	case 'O': 	mode = 1;
    		break;
    	// MODO SÓLIDO
    	case 'I':   mode = 2;
    		break;
        // MODO AJEDREZ
        case 'U':   mode = 3;
            break;
        case '1': figura = 1;
            break;
        case '2': figura = 2;
            break;
        case '3': figura = 3;
            break;
        case '4': figura = 4;
            /*cout << "Introduce el nombre del archivo PLY: " << endl;
            cin >> n_A_;
            objetoPLY.setPLY(n_A_);*/
            break;
        case '5': figura = 5;
        break;
        case '6': figura = 6;
        break;
        case '7': figura =7;
        break;
        case 'J': escala++;
            break;
        case 'H': escala--;
            break;
        case 'R': R= 0.8 ; G= 0.1 ; B= 0.1;
            break;
        case 'G': R= 0.1 ; G= 0.8 ; B= 0.1;
            break;
        case 'B': R= 0.1 ; G= 0.1 ; B= 0.8;
            break;
        case 'K': grueso++;
            break;
        case 'L': grueso--;
            break;
        case 'a':  brazo.girarCodoIzquierda();break;
        case 'd':  brazo.girarCodoDerecha();break;
        case 'w':  brazo.estirarCodo();break;
        case 's':  brazo.contraerCodo();break;
        case 'q':  brazo.rotarMunecaIzquierda();break;
        case 'e':  brazo.rotarMunecaDerecha();break;
        case 'r':  brazo.estirarMuneca();break;
        case 'f':  brazo.contraerMuneca();break;
        case 't':  brazo.abrirMenique();break;
        case 'g':  brazo.cerrarMenique();break;
        case 'y':  brazo.abrirAnular();break;
        case 'h':  brazo.cerrarAnular();break;
        case 'u':  brazo.abrirCorazon();break;
        case 'j':  brazo.cerrarCorazon();break;
        case 'i':  brazo.abrirIndice();break;
        case 'k':  brazo.cerrarIndice();break;
        case 'o':  brazo.abrirPulgar();break;
        case 'l':  brazo.cerrarPulgar();break;
        case ',':  brazo.juntarDedos();break;
        case '.':  brazo.separarDedos();break;
        case '\'': brazo.abrirMano();break;
        case '0':  brazo.cerrarMano();break;

        case 'z':  brazo.piedra();break;
        case 'x':  brazo.papel();break;
        case 'c':  brazo.tijeras();break;

        case 'b':  brazo2.piedra();break;
        case 'n':  brazo2.papel();break;
        case 'm':  brazo2.tijeras();break;
    } 
    return 0;
}

void Escena::teclaEspecial(int Tecla1,int x,int y) {
switch (Tecla1){
	case GLUT_KEY_LEFT:Observer_angle_y--;break;
	case GLUT_KEY_RIGHT:Observer_angle_y++;break;
	case GLUT_KEY_UP:Observer_angle_x--;break;
	case GLUT_KEY_DOWN:Observer_angle_x++;break;
	case GLUT_KEY_PAGE_UP:Observer_distance*=1.2;break;
	case GLUT_KEY_PAGE_DOWN:Observer_distance/=1.2;break;
	}

	std::cout << Observer_distance << std::endl;
}


//**************************************************************************
// Funcion para definir la transformación de proyeccion
//***************************************************************************

void Escena::change_projection()  {
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glFrustum(-Width,Width,-Height,Height,Front_plane,Back_plane);
}


void Escena::redimensionar(int newWidth,int newHeight) {
change_projection();
Width=newWidth/10;
Height=newHeight/10;
glViewport(0,0,newWidth,newHeight);
}


//**************************************************************************
// Funcion para definir la transformación de vista (posicionar la camara)
//***************************************************************************



void Escena::change_observer() {

// posicion del observador
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glTranslatef(0,0,-Observer_distance);
glRotatef(Observer_angle_x,1,0,0);
glRotatef(Observer_angle_y,0,1,0);
}


//**************************************************************************
// Funcion para cambiar los modos de dibujo antes de dibujar.
//***************************************************************************

void Escena::cambiarPincel() {
    //0: puntos ; 1:alambres ; 2:solido ; 3:ajedrez
    if(mode == 0)
        glPolygonMode(GL_FRONT_AND_BACK , GL_POINT);
    else if(mode == 1)
        glPolygonMode(GL_FRONT_AND_BACK , GL_LINE);
    else if(mode == 2 || mode == 3)
        glPolygonMode(GL_FRONT_AND_BACK , GL_FILL);

    glColor3f(R,G,B);
    
    if (mode == 3)
        ajedrez = true;
    else
        ajedrez = false;

    glPointSize(grueso);
    glLineWidth(grueso);
    glScalef(escala,escala,escala);
}


