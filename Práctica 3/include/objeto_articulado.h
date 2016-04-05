/**********************************

	Izquierdo Vera, Javier
	javierizquierdovera@gmail.com
	Práctica 
	3ºB1
	UGR

***********************************/

#ifndef _OBJETO_ARTICULADO
#define _OBJETO_ARTICULADO
#include <vector>
#include <GL/gl.h>
#include "vertex.h"
#include <stdlib.h>
#include <file_ply_stl.h>
#include <objetos.h>
#define X 0
#define Y 1
#define Z 2



using namespace std;



class cola: public _triangulos3D{
private:
	float altura;

public:
	cola(float altura_);
	void draw (int modo, int grosor, float r1, float g1, float b1, float r2, float g2, float b2, int cola_mov);
	
};

class pinzaElipse: public _triangulos3D{
private:
	float radio;
	void create();

public:
	pinzaElipse(float radio_);
	void redefine(float radio_);
	
};

class pinza: public _triangulos3D{
private:
	float anchura;

public:
	pinza(float anchura);
	void draw (int modo, int grosor, float r1, float g1, float b1, float r2, float g2, float b2, int npinza,
		int inclinacion_pinza, int inclinacion_pinza2, int inclinacion_pinza3, int cerrar_abrir_pinza);
	
};



class pata: public _triangulos3D{
private:
	float altura_superior;
	float altura_inferior;
	float anchura_inferior;
	float anchura_superior;

public:
	pata(float altura_superior_, float altura_inferior_,float anchura_superior_, float anchura_inferior_);
	void draw (int modo, int grosor, float r1, float g1, float b1, float r2, float g2, float b2);
	
};


class pata_superior: public _triangulos3D{
private:
	float altura;
	float anchura;
public:
	pata_superior(float altura_, float anchura_);
	
};



class pata_inferior: public _triangulos3D{
private:
	float altura;
	float anchura;

public:
	pata_inferior(float altura_, float anchura_);
	
};


class piezaCuerpo: public _triangulos3D{
private:
	float altura;
	void generate();

public:
	piezaCuerpo(float altura_);
	void redefine (float altura_);
	
};


class cuerpo: public _triangulos3D{
private:
	float altura;
	float profundidad;


public:
	cuerpo( float altura_, float profundidad_);
	void draw (int modo, int grosor, float r1, float g1, float b1, float r2, float g2, float b2);
	
};

class boca: public _triangulos3D{
private:
	float altura;
	float anchura;


public:
	boca( float altura_, float anchura_);
	void draw (int modo, int grosor, float r1, float g1, float b1, float r2, float g2, float b2, int morder);
	
};


class escorpion: public _triangulos3D{
private:
	float anchura;
	float altura;
	float giro_escorpion;
	float translacion_cola_inferior;
	float translacion_cola_superior;
	float min_cola_inferior;
	float min_cola_superior;

	// Movimiento
	int inclinacion_pinza_izq;
	int inclinacion_pinza_der;
	int inclinacion_pinza_izq2;
	int inclinacion_pinza_der2;
	int inclinacion_pinza_izq3;
	int inclinacion_pinza_der3;
	int cerrar_abrir_pinza_izquierda;
	int cerrar_abrir_pinza_derecha;
	int morder;
	int cola_mov;
	int andar;
	int girar;
	int mode;


	// Dibujo por partes
	void drawCola (int grosor, float r1, float g1, float b1, float r2, float g2, float b2);
	void drawPatas (int grosor, float r1, float g1, float b1, float r2, float g2, float b2);
	void drawCuerpo (int grosor, float r1, float g1, float b1, float r2, float g2, float b2);
	void drawPinzas (int grosor, float r1, float g1, float b1, float r2, float g2, float b2);
	void drawboca (int grosor, float r1, float g1, float b1, float r2, float g2, float b2);


public:
	escorpion();

	void draw (int modo=2, int grosor=2, float r1=0, float g1=0, float b1=0, float r2=1, float g2=0, float b2=0);

	void draw (int modo, int grosor, float r1, float g1, float b1, float r2, float g2, float b2,
		int inclinacion_pinza_izq,int inclinacion_pinza_der,int inclinacion_pinza_izq2,int inclinacion_pinza_der2,
		int inclinacion_pinza_izq3,int inclinacion_pinza_der3,bool cerrar_abrir_pinza_izquierda,
		bool cerrar_abrir_pinza_derecha, bool morderb, int cola_mov, int andar, int girar);


	void setInclinacionPinzaIzq(int& v);
	void setInclinacionPinzaDer(int& v);
	void setInclinacionPinzaIzq2(int& v);
	void setInclinacionPinzaDer2(int& v);
	void setInclinacionPinzaIzq3(int& v);
	void setInclinacionPinzaDer3(int& v);
	void setCerrarAbrirPinzaIzq(bool v);
	void setCerrarAbrirPinzaDer(bool v);
	void setMorder(bool v);
	void setColaMov(int& v);
	void setAndar(int v);
	void setGirar(int v);
	void setMode(int v);
	
};

#endif
