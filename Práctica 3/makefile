practica1:  objetoPly objetos objetoArticulado source/practica1_objetos.cc
	g++ -o practica1_objetos source/practica1_objetos.cc object/objetos.o object/objeto_articulado.o object/file_ply_stl.o -lglut -lGLU -lGL -lm -std=c++11 -I include

objetos: source/objetos.cc include/vertex.h include/objetos.h
	g++ -c -o object/objetos.o source/objetos.cc -I include -std=c++11 -lglut -lGLU -lGL -lm 

objetoPly: source/file_ply_stl.cc include/file_ply_stl.h
	g++ -c -o object/file_ply_stl.o source/file_ply_stl.cc -I include -std=c++11 -lglut -lGLU -lGL -lm 


objetoArticulado: objetos source/objeto_articulado.cc include/objeto_articulado.h
	g++ -c -o object/objeto_articulado.o  source/objeto_articulado.cc  -I include -std=c++11 -lglut -lGLU -lGL -lm 

