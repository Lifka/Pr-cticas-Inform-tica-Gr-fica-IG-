/**********************************

	Izquierdo Vera, Javier
	javierizquierdovera@gmail.com
	Práctica 1
	3ºB1
	UGR

***********************************/

#include "objetos.h"
#include <file_ply_stl.h>
#include <cmath>



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

void _triangulos3D::draw(int mode, int grosor, float r1, float g1, float b1, float r2, float g2, float b2){

	if (mode == puntos)
		draw_puntos(r1,g1,b1,grosor);
	else if (mode == aristas)
		draw_aristas(r1,g1,b1,grosor);
	else if (mode == solido)
		draw_solido(r1,g1,b1);
	else if (mode == ajedrez)
		draw_solido_ajedrez(r1,g1,b1,r2,g2,b2);


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


//*************************************************************************
// Objeto PLY
//*************************************************************************

// Leer Ply
void objetoPly::read(const char * name){
	_file_ply ply;
	vector<float> vertices_float;
	vector<int> faces_int;

	if (ply.open((char *)name))
		cerr << "Error al abrir " << name << endl;

	if (ply.read(vertices_float, faces_int))
		cerr << "Error al leer " << name << endl;

	if (ply.close())
		cerr << "Error al cerrar " << name << endl;

	getPoints(vertices_float);
	getFaces(faces_int);
}

objetoPly::objetoPly(const char * name){
	read(name);
}


objetoPly::objetoPly(){
}

// Operador de asignación
objetoPly& objetoPly::operator =( objetoPly &obj1){
	vertices = obj1.vertices;
	caras = obj1.caras;
	return (*this);
}


// Obtener los vértices de un vector de float
void objetoPly::getPoints(vector<float> vertices_float){
	for(vector<float>::iterator it = vertices_float.begin(); it != vertices_float.end(); ++it){

		// Cada vértice está formado por un x, un y, y un z (van todos seguidos en el vector)
		_vertex3f vert;
		// Obtener x
		vert.x = (*it);
		++it;
		// Obtener y
		vert.y = (*it);
		++it;
		// Obtener z
		vert.z = (*it);
		vertices.push_back(vert);
	}

}

// Obtener las caras de un vector de int
void objetoPly::getFaces(vector<int> faces_int){
	for(vector<int>::iterator it = faces_int.begin(); it != faces_int.end(); ++it){

		// Cada cara está formada por tres vértices (triángulo) (van todos seguidos en el vector):
		_vertex3i vert;
		// Primera cara
		vert._0 = (*it);
		++it;
		// Segunda cara
		vert._1 = (*it);
		++it;
		// Tercera cara
		vert._2 = (*it);
		caras.push_back(vert);
	}

}



//*************************************************************************
// Matriz
//*************************************************************************

template <class Type> 
_matrix4<Type>::_matrix4::_matrix4(){
	matrix.resize(4);
	for(int i = 0; i < matrix.size(); i++)
		matrix[i].resize(4);
}

template <class Type> 
Type _matrix4<Type>::_matrix4::get(int fil, int col){
	return matrix[fil][col];
}

template <class Type> 
void _matrix4<Type>::_matrix4::set(int fil, int col, Type val){
	matrix[fil][col] = val;
}


template <class Type> 
void _matrix4<Type>::_matrix4::initializeIdentidad(){
	
	// Matriz identidad
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			if (i == j)
				matrix[i][j] = 1;
			else 
				matrix[i][j] = 0;
		}

	}
}

template <class Type> 
void _matrix4<Type>::_matrix4::initializeRotationX(float angulo){
	
	initializeIdentidad();

	// Casos especiales en la matriz de rotación
	matrix[1][1] = cos(angulo);
	matrix[1][2] = -sin(angulo);
	matrix[2][1] = sin(angulo);
	matrix[2][2] = cos(angulo);
}

template <class Type> 
void _matrix4<Type>::_matrix4::initializeRotationY(float angulo){
	
	initializeIdentidad();

	// Casos especiales en la matriz de rotación
	matrix[0][0] = cos(angulo);
	matrix[0][2] = -sin(angulo);
	matrix[2][0] = sin(angulo);
	matrix[2][2] = cos(angulo);
}

template <class Type> 
void _matrix4<Type>::_matrix4::initializeRotationZ(float angulo){
	
	initializeIdentidad();

	// Casos especiales en la matriz de rotación
	matrix[0][0] = cos(angulo);
	matrix[0][1] = -sin(angulo);
	matrix[1][0] = sin(angulo);
	matrix[1][1] = cos(angulo);
}


//*************************************************************************
// clase revolución
//*************************************************************************


revolucion::revolucion(vector<_vertex3f> &vertices_, float pa, int eje_, bool con_tapa)
:pasos(pa), eje(eje_), taparb(con_tapa){
	// Ángulo de rotación es en función del número de pasos
	vertices = vertices_;
	angulo = 2 * M_PI / pasos;
	size_perfil = vertices_.size();
	createRevolution();
}

revolucion::revolucion(objetoPly &objeto,float pa, int eje_, bool con_tapa)
:pasos(pa), eje(eje_), taparb(con_tapa){
	vertices = objeto.vertices;
	// Ángulo de rotación es en función del número de pasos
	angulo = 2 * M_PI / pasos;

	size_perfil = vertices.size();

	// caras = objeto.caras; NO HAY CARAS
	createRevolution();
}

void revolucion::redefine(objetoPly &objeto,float pa, int eje_, bool con_tapa){
	pasos = pa; 
	eje = eje_;
	vertices = objeto.vertices;
	// Ángulo de rotación es en función del número de pasos
	angulo = 2 * M_PI / pasos;
	taparb = con_tapa;

	size_perfil = vertices.size();

	// caras = objeto.caras; NO HAY CARAS
	createRevolution();
}

void revolucion::getPointsRevolution(){
	// Vector auxiliar (nuevo perfil):
	vector<_vertex3f> nuevo_perfil(vertices);
	// Vector auxiliar (nuevo perfil) --> el perfil siempre es del mismo tamaño
	nuevo_perfil.resize(size_perfil);

	for(int i = 0; i < pasos; i++){ // Número del perfil
		for(int j = 0; j < size_perfil; j++){ // Vértices del perfil
			// Auxiliar
			_vertex3f vertice_rotado;

			// Rotamos los vértices uno por uno
			vertice_rotado = nuevo_perfil[j] * matriz_revolucion;

			/*
			También podríamos haberlo calculado sin la matriz (haciéndolo a mano):

			vertice_rotado.x= vertices_rotados[j].x*cos(angulo)- vertices_rotados[j].z*sin(angulo);
            vertice_rotado.z= vertices_rotados[j].x*sin(angulo)+vertices_rotados[j].z*cos(angulo);
            vertice_rotado.y= vertices_rotados[j].y;
            */

			// DEBUG:
			//cout << vertice_rotado.x << " " << vertice_rotado.y << " " << vertice_rotado.z << endl;

            // Metemos el nuevo vértice rotado al final del vector de puntos de la figura:
			vertices.push_back(vertice_rotado);
			// Guardamos el vector rotado para volver a rotarlo en el siguiente perfil:
			nuevo_perfil[j] = vertice_rotado;
		}
	}
}


void revolucion::getFacesRevolution(){
	// Variables auxiliares
	_vertex3i caras_aux;
	int perfil_actual;
	int perfil_siguiente;
	int vertice_actual;
	int vertice_siguiente;

	for(int i = 0; i < pasos-1; i++){ // Desplazamiento del perfil

			// Para entenderlo mejor....
			perfil_actual = i*size_perfil;
			perfil_siguiente = (i+1)*size_perfil;

			for(int j = 0; j < size_perfil-1; j++){ // Desplazamiento en los puntos del perfil
				// Para entenderlo mejor....
				vertice_actual = j;
				vertice_siguiente = j+1;

				// Primer triángulo (hay que ir de izquierda a derecha siempre)
				caras_aux._0 = perfil_actual + vertice_actual; 
				caras_aux._1 = perfil_siguiente + vertice_actual;
				caras_aux._2 = perfil_actual + vertice_siguiente;
				caras.push_back(caras_aux);
				
				// Segundo triángulo
				caras_aux._0 = perfil_siguiente + vertice_actual;
				caras_aux._1 = perfil_siguiente + vertice_siguiente;
				caras_aux._2 = perfil_actual + vertice_siguiente;
				caras.push_back(caras_aux);
	  	}
	}

	// Hay un caso especial, que es la cara que une el final y el principio

	perfil_actual = (pasos-1) * size_perfil; // Último perfil
	perfil_siguiente = 0; // Primer perfil

	for(int j = 0; j < size_perfil-1; j++){ // Desplazamiento en los puntos del perfil
		// Para entenderlo mejor....
		vertice_actual = j;
		vertice_siguiente = j+1;

		// Primer triángulo (hay que ir de izquierda a derecha siempre)
		caras_aux._0 = perfil_actual + vertice_actual; 
		caras_aux._1 = perfil_siguiente + vertice_actual;
		caras_aux._2 = perfil_actual + vertice_siguiente;
		caras.push_back(caras_aux);
				
		// Segundo triángulo
		caras_aux._0 = perfil_siguiente + vertice_actual;
		caras_aux._1 = perfil_siguiente + vertice_siguiente;
		caras_aux._2 = perfil_actual + vertice_siguiente;
		caras.push_back(caras_aux);
	  }
}

void revolucion::getTapas(){

	// ARRIBA: ********************************************
	// Vértice:
	_vertex3f punto_arriba;

	if (eje == X){
		punto_arriba.x = vertices[size_perfil-1].x; // Último X (dibujado de abajo a arriba)
		punto_arriba.y = 0;// Siempre centrado en el eje
		punto_arriba.z = 0;// Siempre centrado en el eje
	} else if (eje == Y){
		punto_arriba.x = 0; // Siempre centrado en el eje
		punto_arriba.y = vertices[size_perfil-1].y; // Último Y (dibujado de abajo a arriba)
		punto_arriba.z = 0;// Siempre centrado en el eje
	} else {
		punto_arriba.x = 0; // Siempre centrado en el eje
		punto_arriba.y = 0;// Siempre centrado en el eje
		punto_arriba.z = vertices[size_perfil-1].z; // Último Z (dibujado de abajo a arriba)
	}
	vertices.push_back(punto_arriba);


	// Caras:

	_vertex3i caras_aux;
	int perfil_actual;
	int perfil_siguiente;
	int vertice_actual;
	int vertice_siguiente;


	for(int i = 0; i < pasos-1; i++){

		perfil_actual = i * size_perfil;
		perfil_siguiente = (i + 1) * size_perfil;
		vertice_actual = perfil_actual + size_perfil - 1;
		vertice_siguiente = perfil_siguiente + size_perfil - 1;

		caras_aux._0 = vertice_actual;
		caras_aux._1 = vertice_siguiente;
		caras_aux._2 = vertices.size()-1;
		caras.push_back(caras_aux);
	}


	perfil_actual = (pasos - 1) * size_perfil;
	perfil_siguiente = 0;
	vertice_actual = perfil_actual + size_perfil - 1;
	vertice_siguiente = perfil_siguiente + size_perfil - 1;

	caras_aux._0 = vertice_actual;
	caras_aux._1 = vertice_siguiente;
	caras_aux._2 = vertices.size()-1;
	caras.push_back(caras_aux);



	// ABAJO: ********************************************
	// Vértice:
	_vertex3f punto_abajo;
	if (eje == X){
		punto_abajo.x = vertices[0].x; // Último X (dibujado de abajo a arriba)
		punto_abajo.y = 0; // Siempre centrado en el eje
		punto_abajo.z = 0; // Siempre centrado en el eje
	} else if (eje == Y){
		punto_abajo.x = 0; // Siempre centrado en el eje
		punto_abajo.y = vertices[0].y; // Último Y (dibujado de abajo a arriba)
		punto_abajo.z = 0;// Siempre centrado en el eje
	} else {
		punto_abajo.x = 0; // Siempre centrado en el eje
		punto_abajo.y = 0; // Siempre centrado en el eje
		punto_abajo.z = vertices[0].z; // Último Z (dibujado de abajo a arriba)
	}
	vertices.push_back(punto_abajo);

	// Caras:
	for(int i = 0; i < pasos-1; i++){

		perfil_actual = i * size_perfil;
		perfil_siguiente = (i + 1) * size_perfil;
		vertice_actual = perfil_actual;
		vertice_siguiente = perfil_siguiente;

		caras_aux._0 = vertice_actual;
		caras_aux._1 = vertice_siguiente;
		caras_aux._2 = vertices.size()-1;
		caras.push_back(caras_aux);
	}


	perfil_actual = (pasos - 1) * size_perfil;
	perfil_siguiente = 0;
	vertice_actual = perfil_actual;
	vertice_siguiente = perfil_siguiente;

	caras_aux._0 = vertice_actual;
	caras_aux._1 = vertice_siguiente;
	caras_aux._2 = vertices.size()-1;
	caras.push_back(caras_aux);

}

void revolucion::createRevolution(){
	// Obtenemos la matriz de rotación
	initializeMatrix();

	// Puntos
	getPointsRevolution();

	// Caras
	getFacesRevolution();

	// Tapar
	if (taparb)
		getTapas();
}

void revolucion::initializeMatrix(){
	// Obtenemos la matriz de rotación
	if (eje == X)
		matriz_revolucion.initializeRotationX(angulo);
	else if (eje == Y)
		matriz_revolucion.initializeRotationY(angulo);
	else
		matriz_revolucion.initializeRotationZ(angulo);
}

void revolucion::getRevolution(vector<_vertex3f> &vertices_, vector<_vertex3i> &caras_){
	vertices_ = vertices;
	caras_ = caras;
}



/********************** EXTRUSION ************************************/


extrusion::extrusion(vector<_vertex3f> &vertices_, float pa, int eje_, float tamanio_, bool tapar_){
	vertices = vertices_;
	pasos = pa;
	eje = eje_;
	distancia = tamanio_/pa;
	tam_perfil = vertices_.size();
	taparb = tapar_;
	tamanio = tamanio_;
	createExtrusion();
}


void extrusion::createExtrusion(){
	getPoints();
	getFaces();
	if (taparb){
		if (tam_perfil == 3)
			getTapasTriangular();
		else
			getTapas();
	}
}


void extrusion::getExtrusion(vector<_vertex3f> &vertices_,vector<_vertex3i> &caras_){
	vertices_ = vertices;
	caras_ = caras;
}

void extrusion::getPoints(){

	_vertex3f aux;

	for(int i = 1; i < pasos; i++){
		for(int j = 0; j < tam_perfil; j++)
			if(eje == X){
				aux.x = vertices[j].x + distancia*i;
				aux.y = vertices[j].y;
				aux.z = vertices[j].z;
				vertices.push_back(aux);
			} else if(eje == Y){
				aux.x = vertices[j].x;
				aux.y = vertices[j].y + distancia*i;
				aux.z = vertices[j].z;
				vertices.push_back(aux);

			} else {
				aux.x = vertices[j].x;
				aux.y = vertices[j].y;
				aux.z = vertices[j].z + distancia*i;
				vertices.push_back(aux);

			}

	}
}


void extrusion::getFaces(){

	_vertex3i caras_aux;
	int perfil_actual;
	int perfil_siguiente;
	int vertice_actual;
	int vertice_siguiente;

	for(int i = 0; i < pasos-1; i++){ // Desplazamiento del perfil

			// Para entenderlo mejor....
			perfil_actual = i*tam_perfil;
			perfil_siguiente = (i+1)*tam_perfil;

			for(int j = 0; j < tam_perfil-1; j++){ // Desplazamiento en los puntos del perfil
				// Para entenderlo mejor....
				vertice_actual = j;
				vertice_siguiente = j+1;

				// Primer triángulo (hay que ir de izquierda a derecha siempre)
				caras_aux._0 = perfil_actual + vertice_actual; 
				caras_aux._1 = perfil_siguiente + vertice_actual;
				caras_aux._2 = perfil_actual + vertice_siguiente;
				caras.push_back(caras_aux);
				
				// Segundo triángulo
				caras_aux._0 = perfil_siguiente + vertice_actual;
				caras_aux._1 = perfil_siguiente + vertice_siguiente;
				caras_aux._2 = perfil_actual + vertice_siguiente;
				caras.push_back(caras_aux);
	  	}
	}

	// Hay un caso especial, que es la cara que une el final y el principio

	for(int i = 0; i < pasos-1; i++){ // Desplazamiento del perfil
		perfil_actual = i*tam_perfil;
		perfil_siguiente = (i+1)*tam_perfil;

		// Para entenderlo mejor....
		vertice_actual = 0;
		vertice_siguiente = tam_perfil-1;

		// Primer triángulo (hay que ir de izquierda a derecha siempre)
		caras_aux._0 = perfil_actual + vertice_actual; 
		caras_aux._1 = perfil_siguiente + vertice_actual;
		caras_aux._2 = perfil_actual + vertice_siguiente;
		caras.push_back(caras_aux);
					
		// Segundo triángulo
		caras_aux._0 = perfil_siguiente + vertice_actual;
		caras_aux._1 = perfil_siguiente + vertice_siguiente;
		caras_aux._2 = perfil_actual + vertice_siguiente;
		caras.push_back(caras_aux);

	}
}


void extrusion::getTapasTriangular(){

	_vertex3i caras_aux;
	caras_aux._0 = 0; 
	caras_aux._1 = 1;
	caras_aux._2 = 2;
	caras.push_back(caras_aux);
	caras_aux._0 = vertices.size()-3; 
	caras_aux._1 = vertices.size()-2; 
	caras_aux._2 = vertices.size()-1; 
	caras.push_back(caras_aux);


}

void extrusion::getTapas(){

	float mayor_x = vertices[0].x;
	float mayor_y = vertices[0].y;
	float mayor_z = vertices[0].z;

	for(int i = 1; i < tam_perfil; i++){
		if (vertices[i].x > mayor_x)
			mayor_x = vertices[i].x;

		if (vertices[i].z > mayor_z)
			mayor_z = vertices[i].z;

		if (vertices[i].y > mayor_y)
			mayor_y = vertices[i].y;
	}

	// ARRIBA: ********************************************
	// Vértice:
	_vertex3f punto_arriba;

	if (eje == X){
		punto_arriba.x = tamanio-1 + vertices[0].x; // Último X (dibujado de abajo a arriba)
		punto_arriba.y = mayor_y / 2.0;// Siempre centrado en el eje
		punto_arriba.z = mayor_z / 2.0;// Siempre centrado en el eje
	} else if (eje == Y){
		punto_arriba.x = mayor_x / 2.0; // Siempre centrado en el eje
		punto_arriba.y = tamanio-1 + vertices[0].y; // Último Y (dibujado de abajo a arriba)
		punto_arriba.z = mayor_z / 2.0;// Siempre centrado en el eje
	} else if (eje == Z) {
		punto_arriba.x = mayor_x / 2.0; // Siempre centrado en el eje
		punto_arriba.y = mayor_y / 2.0;// Siempre centrado en el eje
		punto_arriba.z = tamanio-1 + vertices[0].z; // Último Z (dibujado de abajo a arriba)
	}
	vertices.push_back(punto_arriba);


	// Caras:

	_vertex3i caras_aux;
	int perfil_actual;
	int perfil_siguiente;
	int vertice_actual;
	int vertice_siguiente;


	for(int i = 0; i < tam_perfil-1; i++){

		vertice_actual = tam_perfil*(pasos-1)+i;
		vertice_siguiente = vertice_actual +1;

		caras_aux._0 = vertice_actual;
		caras_aux._1 = vertice_siguiente;
		caras_aux._2 = vertices.size()-1;
		caras.push_back(caras_aux);

	}


	vertice_actual = vertices.size()-2;
	vertice_siguiente = vertices.size()-1-tam_perfil;

	caras_aux._0 = vertice_actual;
	caras_aux._1 = vertice_siguiente;
	caras_aux._2 = vertices.size()-1;
	caras.push_back(caras_aux);


	// ABAJO: ********************************************
	// Vértice:
	_vertex3f punto_abajo;
	if (eje == X){
		punto_abajo.x = vertices[0].x; // Último X (dibujado de abajo a arriba)
		punto_abajo.y = mayor_y / 2.0; // Siempre centrado en el eje
		punto_abajo.z = mayor_z / 2.0; // Siempre centrado en el eje
	} else if (eje == Y){
		punto_abajo.x = mayor_x / 2.0; // Siempre centrado en el eje
		punto_abajo.y = vertices[0].y; // Último Y (dibujado de abajo a arriba)
		punto_abajo.z = mayor_z / 2.00;// Siempre centrado en el eje
	} else if (eje == Z)  {
		punto_abajo.x = mayor_x / 2.0; // Siempre centrado en el eje
		punto_abajo.y = mayor_y / 2.0; // Siempre centrado en el eje
		punto_abajo.z = vertices[0].z; // Último Z (dibujado de abajo a arriba)
	}
	vertices.push_back(punto_abajo);

	// Caras:
	for(int i = 0; i < tam_perfil-1; i++){

		vertice_actual = i;
		vertice_siguiente = vertice_actual +1;

		caras_aux._0 = vertice_actual;
		caras_aux._1 = vertice_siguiente;
		caras_aux._2 = vertices.size()-1;
		caras.push_back(caras_aux);
	}


	vertice_actual = tam_perfil -1;
	vertice_siguiente = 0;

	caras_aux._0 = vertice_actual;
	caras_aux._1 = vertice_siguiente;
	caras_aux._2 = vertices.size()-1;
	caras.push_back(caras_aux);

}




/**************************** <cilindro> ******************************************/

cilindro::cilindro(float altura_, float anchura_){
	altura = altura_;
	anchura = anchura_;

	vector<_vertex3f> perfil;
	int tam = 10;
	perfil.resize(tam);

	for (int i = 0; i < tam; i++){
		perfil[i].z = altura_/2+altura_/2*cos(2.0*M_PI*i/tam);
		perfil[i].y = altura_/2+altura_/2*sin(2.0*M_PI*i/tam);
		
	}

	extrusion cuerpo_extrusion(perfil,anchura_, X, anchura_,tapar);
	cuerpo_extrusion.getExtrusion(vertices, caras);

}



/**************************** </cilindro> ******************************************/

