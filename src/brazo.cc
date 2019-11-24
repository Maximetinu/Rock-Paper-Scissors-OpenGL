#include "brazo.h"

void esfera(float largura, float altura, float profundidad){
	glPushMatrix();
		glScalef(largura,altura,profundidad);
		glTranslatef(1,0,0);
	    GLUquadricObj *quadric;
	    quadric = gluNewQuadric();
	    gluSphere(quadric,1,36,18);
    glPopMatrix();
}

void Brazo::limitarAngulos(){
	if(a_z_codo>=150) a_z_codo = 150;
	if(a_z_codo<=0) a_z_codo = 0;

	if(a_y_codo>=60) a_y_codo = 60;
	if(a_y_codo<=-60) a_y_codo = -60;

	if(a_z_muneca>=80) a_z_muneca = 80;
	if(a_z_muneca<=-60) a_z_muneca = -60;

	if(a_x_muneca>=80) a_x_muneca = 80;
	if(a_x_muneca<=-20) a_x_muneca = -20;

	if(a_menique_proximal>=120) a_menique_proximal = 120;
	if(a_menique_proximal<=0) a_menique_proximal = 0;
	if(a_menique_medio>=90) a_menique_medio = 90;
	if(a_menique_medio<=0) a_menique_medio = 0;
	if(a_menique_distal>=90) a_menique_distal = 90;
	if(a_menique_distal<=0) a_menique_distal = 0;

	if(a_anular_proximal>=120) a_anular_proximal = 120;
	if(a_anular_proximal<=0) a_anular_proximal = 0;
	if(a_anular_medio>=90) a_anular_medio = 90;
	if(a_anular_medio<=0) a_anular_medio = 0;
	if(a_anular_distal>=90) a_anular_distal = 90;
	if(a_anular_distal<=0) a_anular_distal = 0;

	if(a_corazon_proximal>=120) a_corazon_proximal = 120;
	if(a_corazon_proximal<=0) a_corazon_proximal = 0;
	if(a_corazon_medio>=90) a_corazon_medio = 90;
	if(a_corazon_medio<=0) a_corazon_medio = 0;
	if(a_corazon_distal>=90) a_corazon_distal = 90;
	if(a_corazon_distal<=0) a_corazon_distal = 0;

	if(a_indice_proximal>=120) a_indice_proximal = 120;
	if(a_indice_proximal<=0) a_indice_proximal = 0;
	if(a_indice_medio>=90) a_indice_medio = 90;
	if(a_indice_medio<=0) a_indice_medio = 0;
	if(a_indice_distal>=90) a_indice_distal = 90;
	if(a_indice_distal<=0) a_indice_distal = 0;

	if(a_pulgar_proximal>=120) a_pulgar_proximal = 120;
	if(a_pulgar_proximal<=0) a_pulgar_proximal = 0;
	if(a_pulgar_distal>=90) a_pulgar_distal = 90;
	if(a_pulgar_distal<=0) a_pulgar_distal = 0;

	if(grado_apertura_dedos<=0) grado_apertura_dedos = 0;
	if(grado_apertura_dedos>=10) grado_apertura_dedos = 10;
}

Brazo::Brazo(){
	longitud_falanges = 12;
	gordura = 8;
	long_distal = longitud_falanges;
	long_media = longitud_falanges*1.5;
	long_proximal = long_media*1.5;
	ancho_mano = longitud_falanges*4.2;
	long_antebrazo = ancho_mano*3;
	long_biceps = long_antebrazo*1.2;

	a_z_codo = 70; a_y_codo = 0;
	a_z_muneca = 30; a_x_muneca = 0;
	a_menique_proximal = 25; a_menique_medio = 25; a_menique_distal = 25;
	a_anular_proximal = 30; a_anular_medio = 30; a_anular_distal = 30; 
	a_corazon_proximal = 30; a_corazon_medio = 30; a_corazon_distal = 30;
	a_indice_proximal = 30; a_indice_medio = 30; a_indice_distal = 30; //a_y_negacion = 0;
	a_pulgar_proximal = 20; a_pulgar_distal = 20;
	grado_apertura_dedos = 0;
}

void Brazo::dibujar(){
	limitarAngulos();
	biceps();
	glPushMatrix();
		glTranslatef(long_biceps*2,0,0);
		glRotatef(a_z_codo,0,0,1);
		glRotatef(a_y_codo,0,1,0);
		antebrazo();
		glPushMatrix();
			glTranslatef(long_antebrazo*2,0,0);
			glRotatef(a_z_muneca,0,0,1);
			glRotatef(a_x_muneca,1,0,0);
			mano();
		glPopMatrix();
	glPopMatrix();
}
//Partes
	void Brazo::biceps(){esfera(long_biceps,gordura*5,ancho_mano*1.2);}

	void Brazo::antebrazo(){esfera(long_antebrazo,gordura*4,ancho_mano*1.15);}

	void Brazo::manoPPT(){
		limitarAngulos();
		glRotatef(90,1,0,0);
		glRotatef(30,0,1,0);
		mano();
	}
	void Brazo::mano(){
		esfera(ancho_mano,gordura*3,ancho_mano);
		glPushMatrix();
			glTranslatef(ancho_mano,0,ancho_mano);
			glRotatef(a_pulgar_proximal,-0.6,0,1);
			glRotatef(-grado_apertura_dedos*6,0,1,0);
			pulgar();
		glPopMatrix();
		glPushMatrix();
			glTranslatef(ancho_mano*1.80,0,ancho_mano-gordura*2.75);
			glRotatef(a_indice_proximal,0,0,1);
			glRotatef(-grado_apertura_dedos*3,0,1,0);
			//glRotatef(a_y_negacion,0,1,0);
			indice();
		glPopMatrix();
		glPushMatrix();
			glTranslatef(ancho_mano*2,0,gordura);
			glRotatef(a_corazon_proximal,0,0,1);
			glRotatef(-grado_apertura_dedos,0,1,0);
			corazon();
		glPopMatrix();
		glPushMatrix();
			glTranslatef(ancho_mano*1.80,0,-ancho_mano+gordura*4.75);
			glRotatef(a_anular_proximal,0,0,1);
			glRotatef(-grado_apertura_dedos*(-1.5),0,1,0);
			anular();
		glPopMatrix();
		glPushMatrix();
			glTranslatef(ancho_mano*1.5,0,-ancho_mano+gordura*1.5);
			glRotatef(a_menique_proximal,0,0,1);
			glRotatef(-grado_apertura_dedos*(-3),0,1,0);
			menique();
		glPopMatrix();
	}

//Dedos
	void Brazo::pulgar(){
		glScalef(0.95,1,1.1);
		glTranslatef(-long_proximal/2,0,0);
		glRotatef(-60,1,0,0);
		falangeProximal();//Proximal anatomicamente
		glTranslatef(long_proximal*2,0,0);
		glPushMatrix();
			glRotatef(a_pulgar_distal,0,0,1);
			falangeDistal();
		glPopMatrix();
	}

	void Brazo::indice(){
		falangeProximal();
		glTranslatef(long_proximal*2,0,0);
		glPushMatrix();
			glRotatef(a_indice_medio,0,0,1);
			falangeMedia();
			glTranslatef(long_media*2,0,0);
			glPushMatrix();
				glRotatef(a_indice_distal,0,0,1);
				falangeDistal();
			glPopMatrix();
		glPopMatrix();
	}

	void Brazo::corazon(){
		glScalef(1.15,1,1);
		falangeProximal();
		glTranslatef(long_proximal*2,0,0);
		glPushMatrix();
			glRotatef(a_corazon_medio,0,0,1);
			falangeMedia();
			glTranslatef(long_media*2,0,0);
			glPushMatrix();
				glRotatef(a_corazon_distal,0,0,1);
				falangeDistal();
			glPopMatrix();
		glPopMatrix();
	}

	void Brazo::anular(){
		glScalef(1.075,1,1); //Estoy haciendo los dedos a mi imagen y semejanza. Mi anular es un pelín más largo que el índice.
		falangeProximal();
		glTranslatef(long_proximal*2,0,0);
		glPushMatrix();
			glRotatef(a_anular_medio,0,0,1);
			falangeMedia();
			glTranslatef(long_media*2,0,0);
			glPushMatrix();
				glRotatef(a_anular_distal,0,0,1);
				falangeDistal();
			glPopMatrix();
		glPopMatrix();
	}

	void Brazo::menique(){
		glScalef(0.75,1,1);
		falangeProximal();
		glTranslatef(long_proximal*2,0,0);
		glPushMatrix();
			glRotatef(a_menique_medio,0,0,1);
			falangeMedia();
			glTranslatef(long_media*2,0,0);
			glPushMatrix();
				glRotatef(a_menique_distal,0,0,1);
				falangeDistal();
			glPopMatrix();
		glPopMatrix();
	}

//Falanges
	void Brazo::falangeProximal(){
		esfera(long_proximal,gordura,gordura*1.75);
	}

	void Brazo::falangeMedia(){
		esfera(long_media,gordura,gordura*1.6);
	}

	void Brazo::falangeDistal(){
		esfera(long_distal,gordura,gordura*1.3);
	}

//Codo
	void Brazo::girarCodoIzquierda(){a_y_codo++;}
	void Brazo::girarCodoDerecha(){a_y_codo--;}
	void Brazo::contraerCodo(){a_z_codo++;}
	void Brazo::estirarCodo(){a_z_codo--;}
//Muñeca
	void Brazo::contraerMuneca(){a_z_muneca++;}
	void Brazo::estirarMuneca(){a_z_muneca--;}
	void Brazo::rotarMunecaDerecha(){a_x_muneca++;}
	void Brazo::rotarMunecaIzquierda(){a_x_muneca--;}

//Mano (dedos simultáneos)
	void Brazo::abrirMano(){
		abrirMenique();
		abrirAnular();
		abrirCorazon();
		abrirIndice();
		abrirPulgar();
	}
	void Brazo::abrirManoMax(){
		abrirMeniqueMax();
		abrirAnularMax();
		abrirCorazonMax();
		abrirIndiceMax();
		abrirPulgarMax();
	}
	void Brazo::cerrarMano(){
		cerrarMenique();
		cerrarAnular();
		cerrarCorazon();
		cerrarIndice();
		cerrarPulgar();
	}
	void Brazo::cerrarManoMax(){
		cerrarMeniqueMax();
		cerrarAnularMax();
		cerrarCorazonMax();
		cerrarIndiceMax();
		cerrarPulgarMax();
	}
//Separar dedos
	void Brazo::separarDedos(){grado_apertura_dedos++;}
	void Brazo::juntarDedos(){grado_apertura_dedos--;}
	void Brazo::separarDedosMax(){grado_apertura_dedos+=999;}
	void Brazo::juntarDedosMax(){grado_apertura_dedos-=999;}

//Meñique
	void Brazo::cerrarMenique(){
		a_menique_proximal++;
		a_menique_medio++;
		a_menique_distal++;
	}
	void Brazo::abrirMenique(){
		a_menique_proximal--;
		a_menique_medio--;
		a_menique_distal--;
	}
	void Brazo::cerrarMeniqueMax(){
		a_menique_proximal=999;
		a_menique_medio=999;
		a_menique_distal=999;
	}
	void Brazo::abrirMeniqueMax(){
		a_menique_proximal=-999;
		a_menique_medio=-999;
		a_menique_distal=-999;
	}
//Anular
	void Brazo::cerrarAnular(){
		a_anular_proximal++;
		a_anular_medio++;
		a_anular_distal++;
	}
	void Brazo::abrirAnular(){
		a_anular_proximal--;
		a_anular_medio--;
		a_anular_distal--;
	}
	void Brazo::cerrarAnularMax(){
		a_anular_proximal=999;
		a_anular_medio=999;
		a_anular_distal=999;
	}
	void Brazo::abrirAnularMax(){
		a_anular_proximal=-999;
		a_anular_medio=-999;
		a_anular_distal=-999;
	}
//Corazon
	void Brazo::cerrarCorazon(){
		a_corazon_proximal++;
		a_corazon_medio++;
		a_corazon_distal++;
	}
	void Brazo::abrirCorazon(){
		a_corazon_proximal--;
		a_corazon_medio--;
		a_corazon_distal--;
	}
	void Brazo::cerrarCorazonMax(){
		a_corazon_proximal=999;
		a_corazon_medio=999;
		a_corazon_distal=999;
	}
	void Brazo::abrirCorazonMax(){
		a_corazon_proximal=-999;
		a_corazon_medio=-999;
		a_corazon_distal=-999;
	}
//Indice
	void Brazo::cerrarIndice(){
		a_indice_proximal++;
		a_indice_medio++;
		a_indice_distal++;
	}
	void Brazo::abrirIndice(){
		a_indice_proximal--;
		a_indice_medio--;
		a_indice_distal--;
	}
	void Brazo::cerrarIndiceMax(){
		a_indice_proximal=999;
		a_indice_medio=999;
		a_indice_distal=999;
	}
	void Brazo::abrirIndiceMax(){
		a_indice_proximal=-999;
		a_indice_medio=-999;
		a_indice_distal=-999;
	}
//Pulgar
	void Brazo::cerrarPulgar(){
		a_pulgar_proximal++;
		a_pulgar_distal++;
	}
	void Brazo::abrirPulgar(){
		a_pulgar_proximal--;
		a_pulgar_distal--;
	}
	void Brazo::cerrarPulgarMax(){
		a_pulgar_proximal=999;
		a_pulgar_distal=999;
	}
	void Brazo::abrirPulgarMax(){
		a_pulgar_proximal=-999;
		a_pulgar_distal=-999;
	}
//PPT
	void Brazo::piedra(){
		cerrarManoMax();
		juntarDedosMax();
	}
	void Brazo::papel(){
		abrirManoMax();
		juntarDedosMax();
	}
	void Brazo::tijeras(){
		cerrarManoMax();
		abrirIndiceMax();
		abrirCorazonMax();
		separarDedosMax();
	}