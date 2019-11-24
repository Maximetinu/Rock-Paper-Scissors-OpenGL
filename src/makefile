practica: escena practica.cc
	g++ -o practica practica.cc escena.o ejes.o cubo.o piramide.o tetraedro.o objeto3d.o triangulo.o punto.o file_ply_stl.o ply.o objetorevolucion.o brazo.o -lglut -lGLU -lGL -lm

escena: ejes cubo piramide tetraedro ply objetorevolucion brazo objeto3d escena.cc escena.h
	g++ -c -o escena.o escena.cc -I .

objeto3d: punto triangulo objeto3d.cc objeto3d.h 
	g++ -c -p objeto3d.cc -I .

punto: punto.cc punto.h
	g++ -c -p punto.cc -I .

triangulo: triangulo.cc triangulo.h
	g++ -c -p triangulo.cc -I .

ejes: ejes.cc ejes.h
	g++ -c -p ejes.cc -I .

cubo: cubo.cc cubo.h
	g++ -c -p cubo.cc -I .

ply: file_ply ply.cc ply.h
	g++ -c -p ply.cc -I .

file_ply: file_ply_stl.cc file_ply_stl.h
	g++ -c -p file_ply_stl.cc -I .

objetorevolucion: objetorevolucion.cc objetorevolucion.h
	g++ -c -p objetorevolucion.cc -I .

brazo: brazo.cc brazo.h
	g++ -c -p brazo.cc -I .

clean:
	rm *.o
	rm practica

tetraedro: tetraedro.cc tetraedro.h
	g++ -c -p tetraedro.cc -I .

piramide: piramide.cc piramide.h
	g++ -c -p piramide.cc -I .

#practica: escena practica.cc
#	g++ -o practica practica.cc escena.o -lglut -lGLU -lGL -lm
#escena: escena.cc escena.h
#	g++ -c -o escena.o escena.cc -I .
