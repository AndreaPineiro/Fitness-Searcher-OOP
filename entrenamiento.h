#ifndef ENTRENAMIENTO_H_
#define ENTRENAMIENTO_H_



#include <string>
#include <iostream>
#include <sstream>
#include <vector>

#include "servicio.h"

using namespace std;

//Declaración de la clase Entrenamiento que hereda de Servicios y es una clase abstracta;
//de esta clase heredarán otras dos Gimnasios y Entrenamiento Online
class Entrenamiento: public Servicio{
	//Variables de instancia
	protected:
		string tipo;
    	vector <string> horarios;
		vector <string> entrenadores;
		float precio_clase;
		int promocion;

	//Métodos del objeto
	public:
		Entrenamiento():Servicio(){}; //Constructor default
		Entrenamiento(string nom_serv,string t, float precio, int promo):Servicio(nom_serv), tipo(t), precio_clase(precio),promocion(promo){};

		//Declaración de getters
		string get_tipo(){return tipo;}
		string get_horarios();
		string get_entrenadores();
		float get_precio_clase(){return precio_clase;}
		int get_promocion(){return promocion;}

		//Declaración de setters
		void set_tipo(string nuevo_tipo){tipo=nuevo_tipo;}
		void set_horario_nuevo(string nuevo_horario){horarios.push_back(nuevo_horario);}
		void set_entrenador_nuevo(string nuevo_entrenador){entrenadores.push_back(nuevo_entrenador);}
		void set_precio_clase(float nuevo_precio){precio_clase = nuevo_precio;}
		void set_promocion(int nueva_promo){promocion=nueva_promo;}

		//Se crean métodos virtuales, para usar sobreescritura en las clases de Gimnasio y Entrenamiento Online
		virtual float precio_por_mes()=0;
		float precio_con_promo();
    	virtual string mostrar()=0;
    
};

//Aquí se definen los getters instanciando los vectores para crear una cadena concatenada
string Entrenamiento::get_horarios(){
 	string strhor;
 	int num=horarios.size();
 	if (num==0){
 		strhor="";
 	} else {
 		strhor=horarios[0];
  		for (vector <string>::iterator i=(horarios.begin()+1); i != horarios.end();i++){
    		strhor= strhor +" , "+(*i);
  		}
  	}
  	return strhor;
}

string Entrenamiento::get_entrenadores(){
	string strentre;
	int num=entrenadores.size();
	if (num==0){
		strentre="";
	} else {
		strentre=entrenadores[0];
		for (vector <string>::iterator i=(entrenadores.begin()+1); i != entrenadores.end();i++){
    		strentre= strentre +" , "+(*i);
  		}
  	}
  	return strentre;
}

//Esta función obtiene el precio mensual con la promoción
float Entrenamiento::precio_con_promo(){
	float precio_promo;
	precio_promo = precio_por_mes()*(100-promocion)/100;
	return precio_promo;
}



//Se crea la clase gimnasio que hereda de Entrenamiento
class Gimnasio: public Entrenamiento {
	private:
		string nombre;
		string ciudad;
		float espacio;
		long telefono;
		int dias;

	public:
		Gimnasio():Entrenamiento("GIMNASIO","",0,0){};
		Gimnasio(string t, float precio, int promo,string nom, string ciud, float esp, long tel, int d):
		Entrenamiento("GIMNASIO", t, precio, promo), nombre(nom), ciudad(ciud), espacio(esp),telefono(tel), dias (d){};

		string get_nombre() {return nombre;}
		string get_ciudad() {return ciudad;}
		float get_espacio() {return espacio;}
		long get_telefono() {return telefono;}
		int get_dias() {return dias;}

		void set_nombre(string nuevo_nombre) {nombre = nuevo_nombre;}
		void set_ciudad(string nueva_ciudad) {ciudad = nueva_ciudad;}
		void set_espacio(float nuevo_espacio) {espacio = nuevo_espacio;}
		void set_telefono(long nuevo_telefono) {telefono = nuevo_telefono;}
		void set_dias(int nuevo_dias) {dias = nuevo_dias;}

		//Aquí se encuentra la sobreescritura de los métodos virtuales 
		float precio_por_mes() {return precio_clase * dias *4;}
		string mostrar();
};

//Se define el métoo sobreescrito en el que se despliega la información del Gimnasio
string Gimnasio::mostrar(){
		stringstream aux;
    	aux << nombre_servicio << endl << "\tNombre: " << nombre << endl << "\tCiudad: " << ciudad <<  endl << "\tTipo de entrenamiento: " << tipo << endl
    	<< "\tPromoción: "  << promocion << endl << "\tPrecio por Mes: " << precio_por_mes() << endl << "\tPrecio con Promoción: " << precio_con_promo() << endl << "\tTelefono: " << telefono << endl << "\tEntrenadores: " <<
    	get_entrenadores() << endl << "\tHorarios: " << get_horarios() << endl << "\tDías que abre: " << dias << endl << "\tTamaño del Local: " << espacio << endl 
    	<< "\tEstrellas: " << puntaje() << endl << "\tReseñas: "  << get_resenas() << endl << "\tInscritos: " << get_inscritos()<< endl << endl;  
    return aux.str();
}


//Se crea la clase gimnasio que hereda de Entrenamiento
class Online: public Entrenamiento{
	//Atributos
	private:
		int clases_por_semana;
		string sitio_web;

	//Métodos
	public:
		Online():Entrenamiento("ENTRENAMIENTO ONLINE","",0,0){};

		Online(string t, float precio, int promo,int clases, string web):
		Entrenamiento("ENTRENAMIENTO ONLINE", t, precio, promo), clases_por_semana(clases),sitio_web(web){};

		int get_clases_por_sem() {return clases_por_semana;}
		string get_sitio_web() {return sitio_web;}

		void set_clases_por_sem(int num_clases) {clases_por_semana = num_clases;}
		void set_sitio_web(string nuevo_sitio) {sitio_web = nuevo_sitio;}

		float precio_por_mes() {return precio_clase * clases_por_semana * 4;};
		//Sobreescritura de método mostrar()
		string mostrar ();

};

//Se define el método mostrar en el que se crea una string con los datos del Entrenamiento online
string Online::mostrar(){
		stringstream aux;
    	aux << nombre_servicio << endl << "\tTipo de entrenamiento: " << tipo << endl << "\tClases por Semana: " << clases_por_semana << endl << "\tPromoción: "  
    	<< promocion << endl << "\tPrecio por Mes: " << precio_por_mes() << endl << "\tPrecio con Promoción: " << precio_con_promo() << endl << "\tEntrenadores: " << get_entrenadores() << endl << "\tHorarios: " << get_horarios() 
    	<< endl << "\tSitio Web: " << sitio_web << endl << "\tEstrellas: " << puntaje() << endl << "\tReseñas: "  << get_resenas() << endl << "\tInscritos: " << get_inscritos()<< endl << endl;  
    return aux.str();
}


#endif


