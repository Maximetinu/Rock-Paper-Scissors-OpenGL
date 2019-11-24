#ifndef _PUNTO_H
#define _PUNTO_H

class Punto{

private:
	float x;
	float y;
	float z;
public:
	Punto();

	void setx(float x_);
	void sety(float y_);
	void setz(float z_);

	float getx();
	float gety();
	float getz();

};
#endif