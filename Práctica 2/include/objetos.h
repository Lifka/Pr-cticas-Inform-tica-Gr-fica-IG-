//**************************************************************************
// Juan Carlos Gallardo Morales 3ºB(b1) 
// Universidad de Granada
// 7 Octubre 2015
//
// Práctica 1 usando objetos
//
//**************************************************************************

#include <vector>
#include <GL/gl.h>
#include "vertex.h"
#include <stdlib.h>
#include <file_ply_stl.h>
#define X 0
#define Y 1
#define Z 2

using namespace std;

const float AXIS_SIZE=5000;

//*************************************************************************
// clase punto
//*************************************************************************

class _puntos3D
{
public:
  
	_puntos3D();
	void draw_puntos(float r, float g, float b, int grosor);

	vector<_vertex3f> vertices;
};

//*************************************************************************
// clase triángulo
//*************************************************************************

class _triangulos3D: public _puntos3D
{
public:

	_triangulos3D();
	void draw_aristas(float r, float g, float b, int grosor);
	void draw_solido(float r, float g, float b);
	void draw_solido_ajedrez(float r1, float g1, float b1, float r2, float g2, float b2);

	vector<_vertex3i> caras;
};


//*************************************************************************
// clase cubo
//*************************************************************************

class _cubo: public _triangulos3D
{
public:

	_cubo(float tam=0.5);
};


//*************************************************************************
// clase piramide
//*************************************************************************

class _piramide: public _triangulos3D
{
public:

	_piramide(float tam=0.5, float al=0.75);
};





class objetoPly: public _triangulos3D{
private:
	void getPoints(vector<float> vertices_float);
	void getFaces(vector<int> faces_int);

public:
	objetoPly(const char * name);
	objetoPly();
	objetoPly& operator =(objetoPly &obj1);
	void read(const char * name);

};


template <class Type> class _matrix4{

private:
	vector<vector<Type> > matrix;
public:
	_matrix4();
	Type get(int fil, int col);
	void set(int fil, int col, Type val);
	void initializeRotationX(float angulo);
	void initializeRotationY(float angulo);
	void initializeRotationZ(float angulo);
	void initializeIdentidad();

};



class revolucion: public _triangulos3D{
private:
	_matrix4<float> matriz_revolucion;
	float angulo;
	float pasos;
	int size_perfil;
	int eje;
	bool tapar;
	void createRevolution();
	void initializeMatrix();
	void getPointsRevolution();
	void getFacesRevolution();
	void getTapas();
public:
	revolucion(objetoPly &objeto, float pa, int eje, bool con_tapa);
	revolucion(float pa, int eje, bool con_tapa);
	void redefine(objetoPly &objeto, float pa, int eje, bool con_tapa);
};
