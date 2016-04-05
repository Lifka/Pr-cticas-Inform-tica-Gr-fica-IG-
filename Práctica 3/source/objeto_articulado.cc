/**********************************

	Izquierdo Vera, Javier
	javierizquierdovera@gmail.com
	Práctica 
	3ºB1
	UGR

***********************************/

#include "objetos.h"
#include "objeto_articulado.h"
#include <file_ply_stl.h>
#include <cmath>


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

#define derecha 0
#define izquierda 1

using namespace std;

/**************************** <PATA superior> ******************************************/

pata_superior::pata_superior(float altura_, float anchura_){
	altura = altura_;
	anchura = anchura_;

	vector<_vertex3f> perfil;

	int partes = 6;
	float partei = altura / partes;
	float anchurai = anchura / 2;


	perfil.resize(partes);

	
	for(int i = 0; i < partes; i++){

		perfil[i].x=partei*i;

		if ((i + 2 == partes) || (i == 1)){ 
			perfil[i].y=anchura / 3;
		} else if ((i + 1 == partes) || (i == 0)){
			perfil[i].y=anchura / 4;
		} else {
			perfil[i].y=anchura / 2;
		}


		perfil[i].z=0;

	}


	revolucion pata_revolucionada(perfil,10.0,X,tapar);
	pata_revolucionada.getRevolution(vertices, caras);
}


/**************************** </PATA inferior> ***************************************/

/**************************** <PATA> ******************************************/

pata_inferior::pata_inferior(float altura_, float anchura_){
	altura = altura_;
	anchura = anchura_;

	vector<_vertex3f> perfil;

	int partes = 6;
	float partei = altura / partes;
	float anchurai = anchura / 2;


	perfil.resize(partes);

	
	for(int i = 0; i < partes; i++){

		perfil[i].y=partei*i;

		if (i - 3 == 0){ 
			perfil[i].x=anchura / 4;
		} else if (i + 1 == partes){
			perfil[i].x=anchura / 3;
		}else if (i - 2 == 0){
			perfil[i].x=anchura / 5;
		}else if (i - 1 == 0){
			perfil[i].x=anchura / 6;
		} else {
			perfil[i].x=anchura / 2;
		}


		perfil[i].z=0;

	}


	revolucion pata_revolucionada(perfil,10.0,Y,tapar);
	pata_revolucionada.getRevolution(vertices, caras);
}


/**************************** </PATA> ***************************************/




/**************************** <PATA> ******************************************/


pata::pata(float altura_superior_,  float anchura_superior_, float altura_inferior_, float anchura_inferior_){
	altura_superior = altura_superior_;
	altura_inferior = altura_inferior_;
	anchura_inferior = anchura_inferior_;
	anchura_superior = anchura_superior_;
}


void pata::draw (int modo, int grosor, float r1, float g1, float b1, float r2, float g2, float b2){
	pata_inferior pata_inferior(altura_inferior, anchura_inferior);
	pata_superior pata_superior(altura_superior, anchura_superior);

	glPushMatrix();
	glTranslatef(0.3,altura_inferior-0.7,0);
	glRotatef(-20,0,0,1); 
	pata_superior.draw(modo,grosor,r1,g1,b1,r2,g2,b2);
	glPopMatrix();


	glPushMatrix();
	glRotatef(-10,0,0,1); 
	pata_inferior.draw(modo,grosor,r1,g1,b1,r2,g2,b2);
	glPopMatrix();

}

/**************************** </PATA> ***************************************/



/**************************** <cola> ******************************************/

cola::cola(float altura_){	
	altura = altura_;
}

void cola::draw(int mode, int grosor, float r1, float g1, float b1, float r2, float g2, float b2, int cola_mov){
	piezaCuerpo pieza(altura);



		glPushMatrix();
		glRotatef(-50,0,0,1);
		glRotatef(90,0,1,0);
		glTranslatef(4,2.4+2/1.5,-1-(1+1/3.0));
		glScalef( 1.00, 0.6, 1.00);
		pieza.draw(mode, grosor, r1, g1, b1, r2, g2, b2);
		glPopMatrix();


		pieza.redefine(altura-0.5);
		glPushMatrix();
		glRotatef(-50,0,0,1);
		glRotatef(90,0,1,0);
		glTranslatef(4,2.0+3/1.5,-1-(2+2/3.0));
		glScalef( 1.00, 0.6, 1.00);
		pieza.draw(mode, grosor, r1, g1, b1, r2, g2, b2);
		glPopMatrix();


		glPushMatrix();
		glRotatef(-70,0,0,1);
		glRotatef(90,0,1,0);
		glTranslatef(4,1.0+3/1.5,-3.5-(2+2/3.0));
		glScalef( 1.00, 0.6, 1.00);
		pieza.draw(mode, grosor, r1, g1, b1, r2, g2, b2);
		glPopMatrix();


		pieza.redefine(altura-1);
		glPushMatrix();
		glRotatef(50,0,0,1);
		glRotatef(90,0,1,0);
		glTranslatef(4,3.8,5.5);
		glScalef( 1.00, 0.6, 1.00);
		pieza.draw(mode, grosor, r1, g1, b1, r2, g2, b2);
		glPopMatrix();


		glPushMatrix();
		glRotatef(30,0,0,1);
		glRotatef(90,0,1,0);
		glTranslatef(4,5.8,4.8);
		glScalef( 1.00, 0.6, 1.00);
		pieza.draw(mode, grosor, r1, g1, b1, r2, g2, b2);
		glPopMatrix();


		pieza.redefine(altura-1.5);
		glPushMatrix();
		glRotatef(20,0,0,1);
		glRotatef(90,0,1,0);
		glTranslatef(4,6.8,4.8);
		glScalef( 1.00, 0.6, 1.00);
		pieza.draw(mode, grosor, r1, g1, b1, r2, g2, b2);
		glPopMatrix();


		pieza.redefine(altura-2.0);
		glPushMatrix();
		glRotatef(10,0,0,1);
		glRotatef(90,0,1,0);
		glTranslatef(4,7.8,3.8);
		glScalef( 1.00, 0.6, 1.00);
		pieza.draw(mode, grosor, r1, g1, b1, r2, g2, b2);
		glPopMatrix();


		pieza.redefine(altura-2.5);
		glPushMatrix();
		glRotatef(90,0,1,0);
		glTranslatef(4,8.5,3.0);
		glScalef( 1.00, 0.6, 1.00);
		pieza.draw(mode, grosor, r1, g1, b1, r2, g2, b2);
		glPopMatrix();

		glPushMatrix();
		glRotatef(90,0,1,0);
		glTranslatef(4,8.5,3.4);
		glScalef( 1.00, 0.6, 1.00);
		pieza.draw(mode, grosor, r1, g1, b1, r2, g2, b2);
		glPopMatrix();

/* BOLA CON AGUIJÓN */
		int mov_aguijon = cola_mov;

		if (abs(cola_mov) > 5)
			mov_aguijon = -5;
		if (cola_mov >= 0)
			mov_aguijon = 2;


		glPushMatrix();
			glRotatef(mov_aguijon,0,1,0);

			pieza.redefine(altura-2.0);
			glPushMatrix();
				glRotatef(90,0,1,0);
				glTranslatef(4,8.0,3.4);
				glScalef( 1.00, 0.6, 1.00);
				pieza.draw(mode, grosor, r1, g1, b1, r2, g2, b2);
			glPopMatrix();

			cilindro pincho(0.1,2);
			glPushMatrix();
				glRotatef(70,0,0,1);
				glTranslatef(8.0,-1,-4.0);
				pincho.draw(mode, grosor, r1, g1, b1, r2, g2, b2);
			glPopMatrix();

		glPopMatrix();




}

/**************************** </cola> ***************************************/

/**************************** <pinzaSuperior> ******************************************/

pinzaElipse::pinzaElipse(float radio_){
	radio = radio_;
	create();
}


void pinzaElipse::redefine(float radio_){
	radio = radio_;
	create();

}

void pinzaElipse::create(){

	vector<_vertex3f> perfil;

	int tam = 12;
	perfil.resize(tam);

	for (int i = 0; i < tam; i++){
		perfil[i].z = 0+radio*cos(2.0*M_PI*i/tam/2);
		perfil[i].y = 0+radio/2*sin(2.0*M_PI*i/tam/2);
		
	}

	revolucion cuerpo_revolucion(perfil,10.0, Z,1);
	cuerpo_revolucion.getRevolution(vertices, caras);

}

/**************************** </pinzaSuperior> ***************************************/

/**************************** <pinza> ******************************************/

pinza::pinza(float anchura_){
	anchura = anchura_;
}



void pinza::draw(int modo, int grosor, float r1, float g1, float b1, float r2, float g2, float b2, int npinza,
	int inclinacion_pinza,int inclinacion_pinza2,int inclinacion_pinza3,int cerrar_abrir_pinza){
	pinzaElipse elipse(anchura/2);
	pata_superior pata_superior2(anchura/2, 1);
	pata_superior pata_superior(anchura, 1);


	glPushMatrix();

	if (npinza == derecha){
		inclinacion_pinza = -inclinacion_pinza;
		inclinacion_pinza2 = -inclinacion_pinza2;
		inclinacion_pinza3 = -inclinacion_pinza3;
	}

	glRotatef(inclinacion_pinza,0,0,1);

	//Circulo articulación
	glPushMatrix();
	glTranslatef(0,0,0);
	glScalef( 1.00, 1, 0.5);
	elipse.draw(modo, grosor, r1, g1,  b1,  r2,  g2,  b2);
	glPopMatrix();


	// panta1
	glPushMatrix();
	glTranslatef(0,0,0);
	glRotatef(45,0,1,0);
	pata_superior2.draw(modo, grosor, r1, g1,  b1,  r2,  g2,  b2);
	glPopMatrix();

	//Circulo articulación
	glPushMatrix();
	glTranslatef(0.5,0,-0.5);
	glScalef( 1.00, 1, 0.5);
	elipse.draw(modo, grosor, r1, g1,  b1,  r2,  g2,  b2);
	glPopMatrix();

	//pata2
	glPushMatrix();	

	glRotatef(inclinacion_pinza2,0,0,1);



	glRotatef(inclinacion_pinza3,1,0,0);

	glPushMatrix();
	glTranslatef(anchura/4+0.1,0,-anchura/4);
	glRotatef(-30,0,1,0);
	pata_superior.draw(modo, grosor, r1, g1,  b1,  r2,  g2,  b2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(anchura+anchura/2-0.3,0,anchura/2-0.1);
	
	glRotatef(60,0,1,0);
	if (npinza == derecha)
		glRotatef(180,0,0,1);


/**********PINZA**************/

	// "MANO"
	elipse.redefine(1.5);
	glPushMatrix();
	glScalef( 1.00, 1, anchura/4+0.2);
	elipse.draw(modo, grosor, r1, g1,  b1,  r2,  g2,  b2);
	glPopMatrix();

	//PARTE PEQUEÑA

	glPushMatrix();
	glRotatef(cerrar_abrir_pinza,1,0,0);

	elipse.redefine(1);
	glPushMatrix();
	glScalef( 1.00, 0.5, 1);
	glTranslatef(0,-anchura/2-0.3,anchura/2-0.2);
	elipse.draw(modo, grosor, r1, g1,  b1,  r2,  g2,  b2);
	glPopMatrix();
	glPopMatrix();


	//PARTE GRANDE
	elipse.redefine(1.5);
	glPushMatrix();
	glScalef( 1.00, 0.5, 1);
	glTranslatef(0,anchura/2-0.3,anchura/2-0.2);
	elipse.draw(modo, grosor, r1, g1,  b1,  r2,  g2,  b2);
	glPopMatrix();
/********************************/
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();


}


/**************************** </pinza> ***************************************/





/**************************** <piezaCuerpo> ******************************************/

void piezaCuerpo::generate(){

	float radio = altura/2;

	vector<_vertex3f> perfil;
	int tam = 6;
	perfil.resize(tam);

	for (int i = 0; i < tam; i++){
		perfil[i].z = radio/2+radio/2*cos(2.0*M_PI*i/(tam*2));
		perfil[i].y = radio/2+radio/2*sin(2.0*M_PI*i/(tam*2));
		perfil[i].x = 0;
		
	}



	revolucion cuero_revolucionado(perfil,10.0,Z,1);
	cuero_revolucionado.getRevolution(vertices, caras);
}

piezaCuerpo::piezaCuerpo(float altura_){
	altura = altura_;
	generate();

}


void piezaCuerpo::redefine(float altura_){
	altura = altura_;
	generate();

}

/**************************** </piezaCuerpo> ***************************************/




/**************************** <cuerpo> ******************************************/

cuerpo::cuerpo(float altura_, float profundidad_){
	altura = altura_;
	profundidad = profundidad_;
}

void cuerpo::draw(int mode, int grosor, float r1, float g1, float b1, float r2, float g2, float b2){
	piezaCuerpo pieza(altura);



	for(int i = 0; i < profundidad; i++){
		glPushMatrix();
		glTranslatef(0,(profundidad-i)/5.0,i+2+i/3.0);
		glRotatef((profundidad-i)*5.0,1,0,0);
		glScalef( 1.00, 0.6, 1.00);
		pieza.draw(mode, grosor, r1, g1, b1, r2, g2, b2);
		glPopMatrix();
	}



}
/**************************** </cuerpo> ***************************************/


/**************************** <boca> ******************************************/

boca::boca(float altura_, float anchura_){
	altura = altura_;
	anchura = anchura_;
}


void boca::draw(int mode, int grosor, float r1, float g1, float b1, float r2, float g2, float b2, int morder){
	
	_piramide pir(anchura,altura);
	glPushMatrix();
	glRotatef(morder,1,0,0);
	pir.draw(mode, grosor, r1, g1, b1, r2, g2, b2);
	glPopMatrix();
}

/**************************** </boca> ***************************************/



/**************************** <escorpion> ******************************************/


escorpion::escorpion(){
	 inclinacion_pinza_izq = 0;
	 inclinacion_pinza_der = 0;
	 inclinacion_pinza_izq2 = 0;
	 inclinacion_pinza_der2 = 0;
	 inclinacion_pinza_izq3 = 0;
	 inclinacion_pinza_der3 = 0;
	 cerrar_abrir_pinza_izquierda = 0;
	 cerrar_abrir_pinza_derecha = 0;
	 morder = 0;
	 cola_mov = 0;
	 andar = 0;
	 girar = 0;
	 mode = 0;
}

void escorpion::drawPatas(int grosor, float r1, float g1, float b1, float r2, float g2, float b2){
	int altura_pata_superior = 3;
	int anchura_pata_superior = 1;
	int altura_pata_inferior = 3;
	int anchura_pata_inferior = 1;

	int total_patas = 4;


	pata pata1(altura_pata_superior,anchura_pata_superior,altura_pata_inferior,anchura_pata_inferior);
	int pata_mov = andar%total_patas;

	for(int i = 0; i < total_patas; i++){
		
		glPushMatrix();
		if (abs(pata_mov) == i)
			glTranslatef(0,1,0);

		glPushMatrix();
		glTranslatef(i*2+2+0.5,0,0);
		glRotatef(90,0,1,0);
		glScalef(1,1.3+(total_patas-i)/10.0,1);
		pata1.draw(mode, grosor, r1, g1, b1, r2, g2, b2);
		glPopMatrix();

		glPopMatrix();
	}


	glPushMatrix();
	glRotatef(180,0,1,0);
	for(int i = 0; i < total_patas; i++){
		
		glPushMatrix();
		if (abs(pata_mov) == i)
			glTranslatef(0,1,0);

		glPushMatrix();
		glTranslatef(i*2 - total_patas *2-0.5,0,8);
		glRotatef(90,0,1,0);
		glScalef(1,1.3+i/10.0,1);
		pata1.draw(mode, grosor, r1, g1, b1, r2, g2, b2);
		glPopMatrix();

		glPopMatrix();
	}
	glPopMatrix();

}


void escorpion::drawCola(int grosor, float r1, float g1, float b1, float r2, float g2, float b2){
	float altura = 3.5;

	cola cola(altura);
	cola.draw(mode, grosor, r1, g1, b1, r2, g2, b2, cola_mov);
	

}


void escorpion::drawCuerpo(int grosor, float r1, float g1, float b1, float r2, float g2, float b2){
	float altura = 4.0;
	float profundidad = 6.0;

	cuerpo cuerpo(altura,profundidad);

	glPushMatrix();
	glRotatef(90,0,1,0);
	glTranslatef(4,2,0);
	cuerpo.draw(mode, grosor, r1, g1, b1, r2, g2, b2);
	glPopMatrix();
	

}


void escorpion::drawPinzas(int grosor, float r1, float g1, float b1, float r2, float g2, float b2){
	float anchura = 2.0;

	pinza pinzas(anchura);

	glPushMatrix();
	glPushMatrix();
	glTranslatef(10,2,-6);
	glRotatef(20,0,1,0);
	pinzas.draw(mode, grosor, r1, g1, b1, r2, g2, b2,izquierda,inclinacion_pinza_izq,inclinacion_pinza_izq2,
		inclinacion_pinza_izq3, cerrar_abrir_pinza_izquierda);
	glPopMatrix();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(10,2,-2);
	glRotatef(180,1,0,0);
	glRotatef(20,0,1,0);
	pinzas.draw(mode, grosor, r1, g1, b1, r2, g2, b2,derecha,inclinacion_pinza_der,inclinacion_pinza_der2,
	 inclinacion_pinza_der3, cerrar_abrir_pinza_derecha);
	glPopMatrix();
	

}

void escorpion::drawboca(int grosor, float r1, float g1, float b1, float r2, float g2, float b2){
	float altura = 1.0;
	float anchura = 0.5;

	boca boca1(altura,anchura);



	glPushMatrix();
	glTranslatef(10.5,2,-3.9);
	glRotatef(-90,0,0,1);
	boca1.draw(mode, grosor, r1, g1, b1, r2, g2, b2, morder);
	glPopMatrix();



	glPushMatrix();
	glPushMatrix();
	glTranslatef(10.5,1.45,-4.1);
	glRotatef(-90,0,0,1);
	glRotatef(180,0,1,0);
	boca1.draw(mode, grosor, r1, g1, b1, r2, g2, b2, morder);
	glPopMatrix();	
	glPopMatrix();
	

}


void escorpion::draw(int modo, int grosor, float r1, float g1, float b1, float r2, float g2, float b2,
	int inclinacion_pinza_izq_,int inclinacion_pinza_der_, int inclinacion_pinza_izq2_,int inclinacion_pinza_der2_,
	int inclinacion_pinza_izq3_, int inclinacion_pinza_der3_, bool cerrar_abrir_pinza_izquierdab_,
	bool cerrar_abrir_pinza_derechab_, bool morderb_, int cola_mov_, int andar_, int girar_){

	setInclinacionPinzaIzq(inclinacion_pinza_izq_);
	setInclinacionPinzaDer(inclinacion_pinza_der_);
	setInclinacionPinzaIzq2(inclinacion_pinza_izq2_);
	setInclinacionPinzaDer2(inclinacion_pinza_der2_);
	setInclinacionPinzaIzq3(inclinacion_pinza_izq3_);
	setInclinacionPinzaDer3(inclinacion_pinza_der3_);
	setCerrarAbrirPinzaIzq(cerrar_abrir_pinza_izquierdab_);
	setCerrarAbrirPinzaDer(cerrar_abrir_pinza_derechab_);
	setMorder(morderb_);
	setColaMov(cola_mov_);
	setAndar(andar_);
	setGirar(girar_);
	setMode(modo);


	draw(modo, grosor, r1, g1, b1, r2, g2, b2);
}


void escorpion::draw(int modo, int grosor, float r1, float g1, float b1, float r2, float g2, float b2){
	setMode(modo);

	glPushMatrix();


	glRotatef(girar,0,1,0);

	glPushMatrix();
	glTranslatef(andar,0,0);

	// PATAS
	drawPatas(grosor, r1, g1, b1, r2, g2, b2);

	// CUERPO
	glPushMatrix();
	if (andar%2 == 0)
		glTranslatef(0,0.3,0);
	drawCuerpo(grosor, r1, g1, b1, r2, g2, b2);

	// COLA
	glPushMatrix();
	glRotatef(cola_mov,0,0,1);
	if (cola_mov < -1)
		glTranslatef(cola_mov/15.00,abs(cola_mov)/20.00,0);
	drawCola(grosor, r1, g1, b1, r2, g2, b2);
	glPopMatrix();

	// PINZAS
	drawPinzas(grosor, r1, g1, b1, r2, g2, b2);

	// BOCA
	drawboca(grosor, r1, g1, b1, r2, g2, b2);
	glPopMatrix();

	glPopMatrix();

	glPopMatrix();

}


void escorpion::setInclinacionPinzaIzq(int& v){
	if(v > 70)
		inclinacion_pinza_izq = 70;
	else
		inclinacion_pinza_izq = v;

	v = inclinacion_pinza_izq;
}

void escorpion::setInclinacionPinzaDer(int& v){
	if(v > 70)
		inclinacion_pinza_der = 70;
	else
		inclinacion_pinza_der = v;

	v = inclinacion_pinza_der;

}

void escorpion::setInclinacionPinzaIzq2(int& v){
	if(v > 35)
		inclinacion_pinza_izq2 = 35;
	else
		inclinacion_pinza_izq2 = v;

	v = inclinacion_pinza_izq2;
}

void escorpion::setInclinacionPinzaDer2(int& v){
	if(v > 35)
		inclinacion_pinza_der2 = 35;
	else
		inclinacion_pinza_der2 = v;

	v = inclinacion_pinza_der2;
}

void escorpion::setInclinacionPinzaIzq3(int& v){
	if(v > 35)
		inclinacion_pinza_izq3 = 35;
	else
		inclinacion_pinza_izq3 = v;

	v = inclinacion_pinza_izq3;
}

void escorpion::setInclinacionPinzaDer3(int& v){
	if(v > 35)
		inclinacion_pinza_der3 = 35;
	else
		inclinacion_pinza_der3 = v;

	v = inclinacion_pinza_der3;

}

void escorpion::setCerrarAbrirPinzaIzq(bool v){
	if (!v)
		cerrar_abrir_pinza_izquierda = -30;
	else
		cerrar_abrir_pinza_izquierda = 0;
}

void escorpion::setCerrarAbrirPinzaDer(bool v){
	if (!v)
		cerrar_abrir_pinza_derecha = -30;
	else
		cerrar_abrir_pinza_derecha = 0;

}

void escorpion::setMorder(bool v){
	if (v)
		morder = -30;
	else
		morder = 0;

}

void escorpion::setColaMov(int& v){
	if(v < -25)
		cola_mov = -25;
	else if(v >5)
		cola_mov = 5;
	else
		cola_mov = v;

	v = cola_mov;
}

void escorpion::setAndar(int v){
	andar = v;
}

void escorpion::setGirar(int v){
	girar = v;
}

void escorpion::setMode(int v){
	mode = v;
}


/**************************** </escorpion> ***************************************/