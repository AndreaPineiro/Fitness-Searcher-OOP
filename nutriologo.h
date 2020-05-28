/*
Proyecto Buscador
Andrea Piñeiro Cavazos
A01705681
28/05/2020
*/


#ifndef NUTRIOLOGO_H_
#define NUTRIOLOGO_H_

#include <string>
#include <iostream>
#include <sstream>
#include <vector>

#include "servicio.h"

using namespace std;

//Declaración de la clase Nutrioólogo que hereda de Servicio
class Nutriologo: public Servicio{
	//Declaro variables de instancia
	private:
		float precio_consulta;
		string ciudad;


	//Declaro los métodos del objeto
	public: 
		Nutriologo():Servicio("NUTRICIÓN",""){}; //Constructor default

		Nutriologo(string nom_nutri, float precio_c, string ciud):Servicio("NUTRICIÓN", nom_nutri), precio_consulta(precio_c),ciudad(ciud){};

		float get_precio_consulta() {return precio_consulta;}
		string get_ciudad() {return ciudad;}

		void set_precio_consulta(float nuevo_precio) {precio_consulta = nuevo_precio;}
		void set_ciudad (string nueva_ciudad) {ciudad = nueva_ciudad;}

		string mostrar();
};

/*Aquí se define el método mostrar que es una sobreescritura del método Servicios; 
Se despliegan todos los datos del nutriólogo. */
string Nutriologo::mostrar(){
	stringstream aux;
	aux << nombre_servicio << endl << "\tNombre: " << nombre << endl << "\tCiudad: " <<
	ciudad << endl << "\tPrecio por Consulta: $" << precio_consulta  << endl << "\tEstrellas: "
	<< puntaje() << endl << "\tReseñas: "  << get_resenas() << endl << "\tInscritos: " << get_inscritos()<< endl << endl; 
	return aux.str();
}

#endif