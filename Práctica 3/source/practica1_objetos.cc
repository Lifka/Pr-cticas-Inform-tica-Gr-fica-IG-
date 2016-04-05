/**********************************

	Izquierdo Vera, Javier
	javierizquierdovera@gmail.com
	Práctica 1
	3ºB1
	UGR

***********************************/

//**************************************************************************
// Práctica 1
//
// Domingo Martin Perandres 2013-2016
//
// GPL
//**************************************************************************

#include "stdlib.h"
#include "stdio.h"
#include <GL/glut.h>
#include <ctype.h>
#include <objetos.h>
#include <file_ply_stl.h>
#include "objeto_articulado.h"
#define X 0
#define Y 1
#define Z 2

#define tapar 1
#define sintapar 0
#define yes 1
#define no 0

#define puntos 0
#define aristas 1
#define solido 2
#define ajedrez 3



// variables que definen la posicion de la camara en coordenadas polares
GLfloat Observer_distance;
GLfloat Observer_angle_x;
GLfloat Observer_angle_y;

// variables que controlan la ventana y la transformacion de perspectiva
GLfloat Window_width,Window_height,Front_plane,Back_plane;

// variables que determninan la posicion y tamaño de la ventana X
int UI_window_pos_x=50,UI_window_pos_y=50,UI_window_width=500,UI_window_height=500;

escorpion esc;
int modo = 0;
int pinzaizq = 0;
int pinzader = 0;
int pinzaizq2 = 0;
int pinzader2 = 0;
int pinzaizq3 = 0;
int pinzader3 = 0;
bool cerrar_abrir_pinza_izquierda = true;
bool cerrar_abrir_pinza_derecha = true;
bool morder = false;
int cola_mov = 0;
int andar = 0;
int girar = 0;
int velocidad = 1;

//**************************************************************************
//
//***************************************************************************

void clear_window()
{

glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
}


//**************************************************************************
// Funcion para definir la transformación de proyeccion
//***************************************************************************

void change_projection()
{

glMatrixMode(GL_PROJECTION);
glLoadIdentity();

// formato(x_minimo,x_maximo, y_minimo, y_maximo,Front_plane, plano_traser)
//  Front_plane>0  Back_plane>PlanoDelantero)
glFrustum(-Window_width,Window_width,-Window_height,Window_height,Front_plane,Back_plane);
}

//**************************************************************************
// Funcion para definir la transformación de vista (posicionar la camara)
//***************************************************************************

void change_observer()
{

// posicion del observador
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glTranslatef(0,0,-Observer_distance);
glRotatef(Observer_angle_x,1,0,0);
glRotatef(Observer_angle_y,0,1,0);
}

//**************************************************************************
// Funcion que dibuja los ejes utilizando la primitiva grafica de lineas
//***************************************************************************

void draw_axis()
{
glBegin(GL_LINES);
// eje X, color rojo
glColor3f(1,0,0);
glVertex3f(-AXIS_SIZE,0,0);
glVertex3f(AXIS_SIZE,0,0);
// eje Y, color verde
glColor3f(0,1,0);
glVertex3f(0,-AXIS_SIZE,0);
glVertex3f(0,AXIS_SIZE,0);
// eje Z, color azul
glColor3f(0,0,1);
glVertex3f(0,0,-AXIS_SIZE);
glVertex3f(0,0,AXIS_SIZE);
glEnd();
}


//**************************************************************************
// Funcion que dibuja los objetos
//***************************************************************************

// Creamos ambos objetos
_piramide piramide(4.0,5.0);
_cubo cubo(4.0);


void draw_estrella(){

// CUBO
	switch(modo){
		case 0: cubo.draw_puntos(1,0,1,5); 
			break;
		case 1: cubo.draw_aristas(0,1,1,4);
			break;
		case 2: cubo.draw_solido(2,0,1);
			break;
		case 3: cubo.draw_solido_ajedrez(1,1,0,0,0,0.3);
			break;
	}

//ARRIBA
	// Desplazamos arriba
	glTranslatef(0,4,0);

		switch(modo){
		case 0: piramide.draw_puntos(1,0,1,5); 
			break;
		case 1: piramide.draw_aristas(1,0,1,4);
			break;
		case 2: piramide.draw_solido(0,1,1);
			break;
		case 3: piramide.draw_solido_ajedrez(1,1,0,0,0,0.3);
			break;
	}
	// corrección
	glTranslatef(0,-4,0);


// ABAJO
	glRotatef(180,1,0,1); // Rotaos sobre x e y 180 para ir abajo

		switch(modo){
		case 0: piramide.draw_puntos(1,0,1,5); 
			break;
		case 1: piramide.draw_aristas(1,0,1,4);
			break;
		case 2: piramide.draw_solido(0,1,1);
			break;
		case 3: piramide.draw_solido_ajedrez(1,1,0,0,0,0.3);
			break;
	}
	glRotatef(180,1,0,1); // Corregimos la rotacción


// DERECHA
	// Desplazamos derecha
	glTranslatef(0,4,4); // Transladamos 4 arriba y 4 a la derecha
	glRotatef(90,1,0,0); // Giramos 90 grados sobre x

		switch(modo){
		case 0: piramide.draw_puntos(1,0,1,5); 
			break;
		case 1: piramide.draw_aristas(1,0,1,4);
			break;
		case 2: piramide.draw_solido(0,1,1);
			break;
		case 3: piramide.draw_solido_ajedrez(1,1,0,0,0,0.3);
			break;
	}
	// corrección
	glRotatef(270,1,0,0); // corregimos la rotación
	glTranslatef(0,-4,-4); // volvemos al eje 0,0



// IZQUIERDA
	glRotatef(-90,1,0,0); //rotamos -90 sobre la x

		switch(modo){
		case 0: piramide.draw_puntos(1,0,1,5); 
			break;
		case 1: piramide.draw_aristas(1,0,1,4);
			break;
		case 2: piramide.draw_solido(0,1,1);
			break;
		case 3: piramide.draw_solido_ajedrez(1,1,0,0,0,0.3);
			break;
	}
	// corrección
	glRotatef(90,1,0,0); // corregimos la rotacción


}

void pruebasRevolucion(){
/*
	objetoPly objetoplyX("./ply/perfil2.ply");
	objetoPly objetoplyY("./ply/perfil.ply");
	objetoPly objetoplyZ("./ply/perfil3.ply");
*/
	objetoPly objetoplyY("./ply/perfil.ply");
	revolucion revolucionobj(objetoplyY,10.0,Y,0);

		switch(modo){
		case 0: revolucionobj.draw_puntos(0,0,0,3);
			break;
		case 1: revolucionobj.draw_aristas(0,0,0,3);
			break;
		case 2: revolucionobj.draw_solido(0,0,0);
			break;
		case 3: revolucionobj.draw_solido_ajedrez(1,1,0,0,0,0.3);
			break;
		case 4: revolucionobj.redefine(objetoplyY,10.0,X,1);
			revolucionobj.draw_solido_ajedrez(1,1,0,0,0,0.3);
			break;
		case 5: revolucionobj.redefine(objetoplyY,10.0,Y,1);
			revolucionobj.draw_solido_ajedrez(1,1,0,0,0,0.3);
			break;
		case 6: revolucionobj.redefine(objetoplyY,10.0,Z,1);
			revolucionobj.draw_solido_ajedrez(1,1,0,0,0,0.3);
			break;
		}

}

void prueba_extrusion()
{

	vector<_vertex3f> prueba_ext;
	prueba_ext.resize(4);
	prueba_ext[0].x = 0;
	prueba_ext[0].y = 0;
	prueba_ext[0].z = 0;

	prueba_ext[1].x = 0;
	prueba_ext[1].y = 0;
	prueba_ext[1].z = 1;

	prueba_ext[2].x = 1;
	prueba_ext[2].y = 0;
	prueba_ext[2].z = 1;

	prueba_ext[3].x = 1;
	prueba_ext[3].y = 0;
	prueba_ext[3].z = 0;
	extrusion ext(prueba_ext, 5, Y, 5,true);
	ext.draw_solido_ajedrez(0,0,0,0,0,1);
	//ext.draw_puntos(0,0,0,3);


}

	
void draw_objects()
{

	esc.draw(modo,1,0,0,0,0,0,0.21);



}


//**************************************************************************
//
//***************************************************************************

void draw_scene(void)
{

clear_window();
change_observer();
draw_axis();
draw_objects();
glutSwapBuffers();
}



//***************************************************************************
// Funcion llamada cuando se produce un cambio en el tamaño de la ventana
//
// el evento manda a la funcion:
// nuevo ancho
// nuevo alto
//***************************************************************************

void change_window_size(int Ancho1,int Alto1)
{
change_projection();
glViewport(0,0,Ancho1,Alto1);
glutPostRedisplay();
}


//***************************************************************************
// Funcion llamada cuando se produce aprieta una tecla normal
//
// el evento manda a la funcion:
// codigo de la tecla
// posicion x del raton
// posicion y del raton
//***************************************************************************

void normal_keys(unsigned char Tecla1,int x,int y)
{

	if (toupper(Tecla1)=='1')
		modo = 0;
	else if (toupper(Tecla1)=='2')
		modo = 1;
	else if (toupper(Tecla1)=='3')
		modo = 2;
	else if (toupper(Tecla1)=='4')
		modo = 3;


/************************************************/
/*				PINZA IZQUIERDA					*/
/***********************************************/
	else if (toupper(Tecla1)=='Q'){
		pinzaizq++;
		esc.setInclinacionPinzaIzq(pinzaizq);
	}else if (toupper(Tecla1)=='A'){
		pinzaizq--;
		esc.setInclinacionPinzaIzq(pinzaizq);
	}else if (toupper(Tecla1)=='W'){
		pinzaizq2++;
		esc.setInclinacionPinzaIzq2(pinzaizq2);
	}else if (toupper(Tecla1)=='S'){
		pinzaizq2--;
		esc.setInclinacionPinzaIzq2(pinzaizq2);
	}else if (toupper(Tecla1)=='E'){
		pinzaizq3++;
		esc.setInclinacionPinzaIzq3(pinzaizq3);
	}else if (toupper(Tecla1)=='D'){
		pinzaizq3--;
		esc.setInclinacionPinzaIzq3(pinzaizq3);
	}else if (toupper(Tecla1)=='Z'){
		cerrar_abrir_pinza_izquierda = !cerrar_abrir_pinza_izquierda;
		esc.setCerrarAbrirPinzaIzq(cerrar_abrir_pinza_izquierda);
	}


/************************************************/
/*				PINZA DERECHA					*/
/***********************************************/
	else if (toupper(Tecla1)=='R'){
		pinzader++;
		esc.setInclinacionPinzaDer(pinzader);
	}
	else if (toupper(Tecla1)=='F'){
		pinzader--;
		esc.setInclinacionPinzaDer(pinzader);
	}

	else if (toupper(Tecla1)=='T'){
		pinzader2++;
		esc.setInclinacionPinzaDer2(pinzader2);
	}
	else if (toupper(Tecla1)=='G'){
		pinzader2--;
		esc.setInclinacionPinzaDer2(pinzader2);
	}

	else if (toupper(Tecla1)=='Y'){
		pinzader3++;
		esc.setInclinacionPinzaDer3(pinzader3);
	}
	else if (toupper(Tecla1)=='H'){
		pinzader3--;
		esc.setInclinacionPinzaDer3(pinzader3);
	}


	else if (toupper(Tecla1)=='C'){
		cerrar_abrir_pinza_derecha = !cerrar_abrir_pinza_derecha;
		esc.setCerrarAbrirPinzaDer(cerrar_abrir_pinza_derecha);
	}


/************************************************/
/*				PINZA AMBAS					*/
/***********************************************/

	else if (toupper(Tecla1)=='X'){
		cerrar_abrir_pinza_derecha = !cerrar_abrir_pinza_derecha;
		cerrar_abrir_pinza_izquierda = !cerrar_abrir_pinza_izquierda;
		esc.setCerrarAbrirPinzaDer(cerrar_abrir_pinza_derecha);
		esc.setCerrarAbrirPinzaIzq(cerrar_abrir_pinza_izquierda);
	}

/************************************************/
/*						BOCA					*/
/***********************************************/
	else if (toupper(Tecla1)=='M'){
		morder = !morder;
		esc.setMorder(morder);
	}
/************************************************/
/*						COLA					*/
/***********************************************/
	else if (toupper(Tecla1)=='B'){
		cola_mov++;
		esc.setColaMov(cola_mov);
	}
	else if (toupper(Tecla1)=='N'){
		cola_mov--;
		esc.setColaMov(cola_mov);
	}
	else if (toupper(Tecla1)==' '){
		cola_mov=-100;
		/*pinzader = 100;
		pinzaizq = 100;
		pinzaizq2 = -15;
		pinzaizq3 = 15;
		pinzader3 = 15;*/
		cerrar_abrir_pinza_derecha = true;
		cerrar_abrir_pinza_izquierda = true;
		esc.setColaMov(cola_mov);
		esc.setCerrarAbrirPinzaDer(cerrar_abrir_pinza_derecha);
		esc.setCerrarAbrirPinzaIzq(cerrar_abrir_pinza_izquierda);
	}
/************************************************/
/*						ANDAR					*/
/***********************************************/
	else if (toupper(Tecla1)=='I'){
		andar=andar + velocidad;
		esc.setAndar(andar);
	}
	else if (toupper(Tecla1)=='K'){
		andar--;
		esc.setAndar(andar);
	}
	else if (toupper(Tecla1)=='J'){
		girar--;
		esc.setGirar(girar);
	}
	else if (toupper(Tecla1)=='L'){
		girar++;
		esc.setGirar(girar);
	}
	
	
/************************************************/
/*			    	VELOCIDAD					*/
/***********************************************/

	else if (toupper(Tecla1)=='9'){
		velocidad++;
	}
	else if (toupper(Tecla1)=='8'){
		velocidad--;
		if (velocidad < 1)
			velocidad = 1;
	}

	glutPostRedisplay();
}

//***************************************************************************
// Funcion llamada cuando se produce aprieta una tecla especial
//
// el evento manda a la funcion:
// codigo de la tecla
// posicion x del raton
// posicion y del raton

//***************************************************************************

void special_keys(int Tecla1,int x,int y)
{

switch (Tecla1){
	case GLUT_KEY_LEFT:Observer_angle_y--;break;
	case GLUT_KEY_RIGHT:Observer_angle_y++;break;
	case GLUT_KEY_UP:Observer_angle_x--;break;
	case GLUT_KEY_DOWN:Observer_angle_x++;break;
	case GLUT_KEY_PAGE_UP:Observer_distance*=1.2;break;
	case GLUT_KEY_PAGE_DOWN:Observer_distance/=1.2;break;
	}
glutPostRedisplay();
}



//***************************************************************************
// Funcion de incializacion
//***************************************************************************

void initialize(void)
{
// se inicalizan la ventana y los planos de corte
Window_width=10;
Window_height=10;
Front_plane=10;
Back_plane=1000;

// se inicia la posicion del observador, en el eje z
Observer_distance=2*Front_plane;
Observer_angle_x=0;
Observer_angle_y=0;

// se indica cual sera el color para limpiar la ventana	(r,v,a,al)
// blanco=(1,1,1,1) rojo=(1,0,0,1), ...
glClearColor(1,1,1,1);

// se habilita el z-bufer
glEnable(GL_DEPTH_TEST);
//
change_projection();
//
glViewport(0,0,UI_window_width,UI_window_height);
}


//***************************************************************************
// Programa principal
//
// Se encarga de iniciar la ventana, asignar las funciones e comenzar el
// bucle de eventos
//***************************************************************************

int main(int argc, char **argv)
{

// se llama a la inicialización de glut
glutInit(&argc, argv);

// se indica las caracteristicas que se desean para la visualización con OpenGL
// Las posibilidades son:
// GLUT_SIMPLE -> memoria de imagen simple
// GLUT_DOUBLE -> memoria de imagen doble
// GLUT_INDEX -> memoria de imagen con color indizado
// GLUT_RGB -> memoria de imagen con componentes rojo, verde y azul para cada pixel
// GLUT_RGBA -> memoria de imagen con componentes rojo, verde, azul y alfa para cada pixel
// GLUT_DEPTH -> memoria de profundidad o z-bufer
// GLUT_STENCIL -> memoria de estarcido
glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

// posicion de la esquina inferior izquierdad de la ventana
glutInitWindowPosition(UI_window_pos_x,UI_window_pos_y);

// tamaño de la ventana (ancho y alto)
glutInitWindowSize(UI_window_width,UI_window_height);

// llamada para crear la ventana, indicando el titulo (no se visualiza hasta que se llama
// al bucle de eventos)
glutCreateWindow("Práctica 3");

// asignación de la funcion llamada "dibujar" al evento de dibujo
glutDisplayFunc(draw_scene);
// asignación de la funcion llamada "cambiar_tamanio_ventana" al evento correspondiente
glutReshapeFunc(change_window_size);
// asignación de la funcion llamada "tecla_normal" al evento correspondiente
glutKeyboardFunc(normal_keys);
// asignación de la funcion llamada "tecla_Especial" al evento correspondiente
glutSpecialFunc(special_keys);

// funcion de inicialización
initialize();

// inicio del bucle de eventos
glutMainLoop();
return 0;
}