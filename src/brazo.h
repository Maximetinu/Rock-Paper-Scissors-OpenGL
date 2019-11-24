#ifndef _BRAZO_H
#define _BRAZO_H

#include <GL/gl.h>
    #include <GL/glut.h>

class Brazo{
private:
	float longitud_falanges; //Tamaño base
	float long_proximal;
	float long_media;
	float long_distal;
	float gordura;
	float ancho_mano;
	float long_antebrazo;
	float long_biceps;

	float a_z_codo, a_y_codo;
	float a_z_muneca, a_x_muneca;
	float a_menique_proximal, a_menique_medio, a_menique_distal;
	float a_anular_proximal, a_anular_medio, a_anular_distal;
	float a_corazon_proximal, a_corazon_medio, a_corazon_distal;
	float a_indice_proximal, a_indice_medio, a_indice_distal, a_y_negacion;
	float a_pulgar_proximal, a_pulgar_distal;
	float grado_apertura_dedos;

public:
	Brazo();
	void dibujar();
	void manoPPT();

	void girarCodoIzquierda();
	void girarCodoDerecha();
	void contraerCodo();
	void estirarCodo();

	void contraerMuneca();
	void estirarMuneca();
	void rotarMunecaDerecha();
	void rotarMunecaIzquierda();

	void abrirMano();
	void cerrarMano();
	void abrirManoMax();
	void cerrarManoMax();

	void separarDedos();
	void juntarDedos();
	void separarDedosMax();
	void juntarDedosMax();

	void abrirMenique();
	void cerrarMenique();
	void abrirMeniqueMax();
	void cerrarMeniqueMax();

	void abrirAnular();
	void cerrarAnular();
	void abrirAnularMax();
	void cerrarAnularMax();

	void abrirCorazon();
	void cerrarCorazon();
	void abrirCorazonMax();
	void cerrarCorazonMax();

	void abrirIndice();
	void cerrarIndice();
	void abrirIndiceMax();
	void cerrarIndiceMax();

	void abrirPulgar();
	void cerrarPulgar();
	void abrirPulgarMax();
	void cerrarPulgarMax();

	void piedra();
	void papel();
	void tijeras();

	void negacion();
	void ok();
	void corteManga();
	void heavy();
	void victory();
	void telefono();
	void garra();
	void contarHasta5();

private:
	void biceps();
	void antebrazo();
	void mano(); //Público para el Piedra Papel y Tijeras

	void pulgar();
	void indice();
	void corazon();
	void anular();
	void menique();

	void falangeProximal();
	void falangeMedia();
	void falangeDistal();

	void limitarAngulos();
};
#endif