/*
Proyecto Buscador
Andrea Piñeiro Cavazos
A01705681
28/05/2020
*/


#ifndef USUARIO_H_
#define USUARIO_H_

#include <string>
#include <iostream>
#include <sstream>


using namespace std;

//Declaración de la clase usuario
class Usuario {
	//Atributos de la clase
	private:
		string nombre;
		string intereses[100];
    int iint;

    //Métodos de la clase
	public:
		Usuario():nombre(""),iint(0){};
		Usuario(string nom):nombre(nom),iint(0){};

		string get_nombre() {return nombre;}
		string get_intereses();

		void set_intereses(string nuevo_interes);

		string mostrar();
};

//Se instancia la lista para hacer una cadena concatenada con cada uno de los elementos.
//Devuelve como string los intereses del usuario. 
string Usuario::get_intereses(){
  string strint=intereses[0];
  for (int i=1; i<iint;i++){
      strint=strint + intereses[i];
  }
  return strint;
}

//Se agrega un nuevo interes a la lista, y se incrementa el contador de intereres
void Usuario::set_intereses(string nuevo_interes){
	intereses[iint]=nuevo_interes;
	iint++;
}

//Se define el método en el que se crea una string con toda la información del usuario.
//Convierte los atributos a string, @return string con texto concatenado.
string Usuario::mostrar(){
	stringstream aux;
	aux << "USUARIO" << endl << "\tNombre: " << nombre << endl << "\tInteréses: " << get_intereses() << endl << endl;
	return aux.str();
}


#endif