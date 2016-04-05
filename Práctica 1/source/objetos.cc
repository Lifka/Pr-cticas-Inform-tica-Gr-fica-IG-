/**********************************

	Izquierdo Vera, Javier
	javierizquierdovera@gmail.com
	Práctica 1
	3ºB1
	UGR

***********************************/

#include "objetos.h"

using namespace std;


_puntos3D::_puntos3D(){

}

// Dibujar los vértices - función básica
void _puntos3D::draw_puntos(float r, float g, float b, int grosor){
	
	// Color
	glColor3f(r,g,b);
	// Grosor
	glPointSize(grosor);

	glBegin(GL_POINTS);
	// Dibujamos cada uno de los vértices
	for(vector<_vertex3f>::iterator it = vertices.begin(); it != vertices.end(); ++it){
			//glVertex3f((*it).x,(*it).y,(*it).z);
			glVertex3fv((GLfloat *) &(*it)); // Vector con las tres coordenadas --> x,y,z
	}
	glEnd();

}

//*************************************************************************
// clase triángulo
//*************************************************************************

_triangulos3D::_triangulos3D(){
}

void _triangulos3D::draw_aristas(float r, float g, float b, int grosor){
	// Cada cara define tres puntos diferentes --> una cara del triángulo
	// Un punto = 3 coordenadas en el espacio
	glColor3f(r,g,b);
	// Ha de ser GL_FRONT_AND_BACK para que salgan las líneas de atrás y de delante
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE); // GL_LINE --> arista
	glPointSize(grosor);
	glBegin(GL_TRIANGLES);
	// En cada iteración -> una cara
	for(int i = 0; i < caras.size(); i++){
			// Primer vértice de la cara i
			glVertex3f(vertices[caras[i]._0].x,vertices[caras[i]._0].y,vertices[caras[i]._0].z);
			// Segundo vértice de la cara i
			glVertex3f(vertices[caras[i]._1].x,vertices[caras[i]._1].y,vertices[caras[i]._1].z);
			// Tercer vértice de la cara i
			glVertex3f(vertices[caras[i]._2].x,vertices[caras[i]._2].y,vertices[caras[i]._2].z);

	}
	glEnd();
}

void _triangulos3D::draw_solido(float r, float g, float b){

	glColor3f(r,g,b);
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL); //GL_FILL --> relleno
	glBegin(GL_TRIANGLES);
	// Dibujamos cada una de las caras de nuevo
	for(int i = 0; i < caras.size(); i++){
			glVertex3f(vertices[caras[i]._0].x,vertices[caras[i]._0].y,vertices[caras[i]._0].z);
			glVertex3f(vertices[caras[i]._1].x,vertices[caras[i]._1].y,vertices[caras[i]._1].z);
			glVertex3f(vertices[caras[i]._2].x,vertices[caras[i]._2].y,vertices[caras[i]._2].z);

	}
	glEnd();   

}

// Ajedrez --> caras contiguas alternan entre dos colores distintos
void _triangulos3D::draw_solido_ajedrez(float r1, float g1, float b1, float r2, float g2, float b2){
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
	glBegin(GL_TRIANGLES);
	for(int i = 0; i < caras.size(); i++){
		if (i%2) // Si es impar, usamos el color 2
			glColor3f(r2,g2,b2);
		else // Si es par, usamos el color 1
			glColor3f(r1,g1,b1);

			// Dibujamos una cara de un color y en la siguiente iteración del otro color
			glVertex3f(vertices[caras[i]._0].x,vertices[caras[i]._0].y,vertices[caras[i]._0].z);
			glVertex3f(vertices[caras[i]._1].x,vertices[caras[i]._1].y,vertices[caras[i]._1].z);
			glVertex3f(vertices[caras[i]._2].x,vertices[caras[i]._2].y,vertices[caras[i]._2].z);

	}
	glEnd(); 
}

//*************************************************************************
// clase cubo
//*************************************************************************

_cubo::_cubo(float tam){
	vertices.resize(8); // un cubo tiene 8 vértices
	caras.resize(12); // un cubo tiene 12 caras

	// Como partimos del eje, tenemos que usar el radio
	//tam/=2; 

	// Asignar vértices y caras

	// VÉRTICES:*************************
	// BASE
	// izquierda frontal
	vertices[0].x=0;
	vertices[0].y=0;
	vertices[0].z=tam;
	//derecha frontal
	vertices[1].x=tam;
	vertices[1].y=0;
	vertices[1].z=tam;
	//derecha trasera
	vertices[2].x=tam;
	vertices[2].y=0;
	vertices[2].z=0;
	// izquierda trasera
	vertices[3].x=0;
	vertices[3].y=0;
	vertices[3].z=0;

	//SUPERIOR
	vertices[4].x=0;
	vertices[4].y=tam; //0 + tam
	vertices[4].z=tam;
	//derecha frontal
	vertices[5].x=tam;
	vertices[5].y=tam;
	vertices[5].z=tam;
	//derecha trasera
	vertices[6].x=tam;
	vertices[6].y=tam;
	vertices[6].z=0;
	// izquierda trasera
	vertices[7].x=0;
	vertices[7].y=tam;
	vertices[7].z=0;


	// CARAS:*************************
	// (en las caras se guarda el índice en el que están los vértices)
	// FRONTAL
	caras[1]._0 = 0;
	caras[1]._1 = 5;
	caras[1]._2 = 4;

	caras[0]._0 = 0;
	caras[0]._1 = 1;
	caras[0]._2 = 5;

	// CARA DERECHA
	caras[3]._0 = 1;
	caras[3]._1 = 6;
	caras[3]._2 = 5;

	caras[2]._0 = 1;
	caras[2]._1 = 2;
	caras[2]._2 = 6;


	//CARA TRASERA
	caras[4]._0 = 7;
	caras[4]._1 = 2;
	caras[4]._2 = 6;

	caras[5]._0 = 3;
	caras[5]._1 = 2;
	caras[5]._2 = 7;

	//CARA IZQUIERDA
	caras[6]._0 = 4;
	caras[6]._1 = 3;
	caras[6]._2 = 7;

	caras[7]._0 = 0;
	caras[7]._1 = 3;
	caras[7]._2 = 4;

	//CARA INFERIOR
	caras[8]._0 = 0;
	caras[8]._1 = 2;
	caras[8]._2 = 3;

	caras[9]._0 = 0;
	caras[9]._1 = 1;
	caras[9]._2 = 2;


	//CARA SUPERIOR
	caras[10]._0 = 4;
	caras[10]._1 = 5;
	caras[10]._2 = 6;

	caras[11]._0 = 4;
	caras[11]._1 = 6;
	caras[11]._2 = 7;




}


//*************************************************************************
// clase piramide
//*************************************************************************

_piramide::_piramide(float tam, float al){
	vertices.resize(5); // una pirámide tiene 5 vértices
	caras.resize(6); // una pirámide tiene 6 caras

	//tam/=2;

	// Asignar vértices y caras

	// VÉRTICES:*************************
	// BASE
	// Vértice 0: (izquierda frotal)
	vertices[0].x=0;
	vertices[0].y=0;
	vertices[0].z=tam;
	// Vértice 1: (derecha frotal)
	vertices[1].x=tam;
	vertices[1].y=0;
	vertices[1].z=tam;
	// Vértice 2: (derecha trasera)
	vertices[2].x=tam;
	vertices[2].y=0;
	vertices[2].z=0;
	// Vértice 3: (izquierda trasera)
	vertices[3].x=0;
	vertices[3].y=0;
	vertices[3].z=0;

	//PICO
	// Vértice 4:
	vertices[4].x=tam/2;
	vertices[4].y=al; // altura
	vertices[4].z=tam/2;


	// CARAS:************************* 
	// (en las caras se guarda el índice en el que están los vértices)
	// BASE
	//frontal
	caras[0]._0=0;
	caras[0]._1=1;
	caras[0]._2=2;
	//trasera
	caras[1]._0=0;
	caras[1]._1=2;
	caras[1]._2=3;

	//FRONTAL ALTURA
	caras[2]._0=0;
	caras[2]._1=1;
	caras[2]._2=4;

	//DERECHA ALTURA
	caras[3]._0=1;
	caras[3]._1=2;
	caras[3]._2=4;

	// TRASERA ALTURA
	caras[4]._0=2;
	caras[4]._1=3;
	caras[4]._2=4;


	//IZQUIERDA ALTURA
	caras[5]._0=0;
	caras[5]._1=4;
	caras[5]._2=3;
}