/*
Proyecto Buscador
Andrea Piñeiro Cavazos
A01705681
28/05/2020
*/

#ifndef SERVICIO_H_
#define SERVICIO_H_

#include <string>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

/*Aquí se crea la clase servicio, que es una clase abstracta, servicio va a ser
padre de otras dos clases Entrenamiento y Nutriólgos. Los atributos de servicios 
son calificaciones que le da el usuario, reseñas, nombre de los usuarios inscritos 
y el nombre del servicio.*/
class Servicio{
	//Declaración de atributos
	protected: 
		vector <int> calificaciones;
		vector <string> resenas;
		vector <string> inscritos;
		string nombre_servicio;
		string nombre;

	//Declaración de los métodos del objeto
	public:
		Servicio(): nombre_servicio(""), nombre(""){}; //Constructor por default
		Servicio(string nom_serv, string nom):nombre_servicio(nom_serv),nombre(nom){}; //Constructor que recibe nombre del servicio

		//Getters
		string get_nombre() {return nombre;}
		string get_resenas();
		string get_inscritos();
		string get_nombre_servicio(){return nombre_servicio;}

		//Setters
		void set_calificacion_nueva(int nueva_calif) {calificaciones.push_back(nueva_calif);}
		void set_nueva_resena(string nueva_resena) {resenas.push_back(nueva_resena);}
		void set_nuevo_inscrito(string nuevo_inscrito) {inscritos.push_back(nuevo_inscrito);}
		void set_nombre(string nuevo_nombre) {nombre = nuevo_nombre;}

		double puntaje();
		virtual string mostrar()=0;
};


//Aquí se iteran los vectores para mostrar sus respectivos elementos
//Para las reseñas e inscritos se crea una sola string concatenada
string Servicio::get_resenas(){
  	string strresen="";
  	int num=resenas.size();
	if (num==0){
		strresen="";
	} else {
		for (vector <string>::iterator i=(resenas.begin()) ; i != resenas.end() ; i++){
			strresen = strresen + "\n\t\t" + "<< " + (*i) + " >>";
		}
	}
	return strresen;
}

string Servicio::get_inscritos(){
	string strinscr;
	int num=inscritos.size();
	if (num==0){
		strinscr="";
	} else {
		strinscr=inscritos[0];
		for (vector <string>::iterator i=(inscritos.begin()+1) ; i != inscritos.end() ; i++){
			strinscr = strinscr + " , " + (*i);
		}
	}
	return strinscr;
}

//Esta función lo que hace es iterar en el vector de calificaciones para sumarlas 
//y obtener el promedio.
double Servicio::puntaje(){
	double promedio;
  	int suma=0;
  	int num=calificaciones.size();
  	if (num==0){
  		promedio= 0;
  	}else{
  		for (int i =0; i < num; i++){
    		suma=suma+calificaciones[i];
  		}
  		promedio=suma/num;
  	}
	return promedio;
}

#endif