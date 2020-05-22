#ifndef BUSCADOR_H_
#define BUSCADOR_H_

#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include "servicio.h"
#include "usuario.h"
#include "nutriologo.h"
#include "entrenamiento.h"

using namespace std;
const int MAX = 1000;

class Buscador {
	private:
		Servicio *serv[MAX];
		Usuario *usua[MAX];

		int iserv;
		int iusua;

	public:
		Buscador(): iserv(0), iusua(0){};

		void crea_ejemplos();
		void muestra_servicios();
		void muestra_servicios(string tipo_serv);
		void muestra_usuarios();

		void agrega_gimnasio(string t, float precio, int promo,string nom, string ciud, float esp, long tel, int d);
		void agrega_online(string t, float precio, int promo,int clases, string web);
		void agrega_nutriologo(string nom_nutri, float precio_c, string ciud);
		void agrega_usuario(string nom);
};

//Crea objetos para Servicio y para Usuarios y guarda estos objetos en la posición iserv o
//iusua del arreglo
//new crea el objeto usando polimorfismo 
void Buscador::crea_ejemplos(){
	serv[iserv] = new Gimnasio("crossfit",50, 20,"Saiger","Queretaro",350,4423277564,5);
	iserv++;
	serv[iserv] = new Gimnasio("trx",100,0,"Logma","Pachuca",200,7721546374,5);
	iserv++;
	serv[iserv] = new Online("trx",30,0,3,"https://argen.com");
	iserv++;
	serv[iserv] = new Online("HIIT",20,10,4,"https://entrenamiento.com");
	iserv++;
	serv[iserv] = new Nutriologo("Sofía García",350,"Queretaro");
	iserv++;
	serv[iserv] = new Nutriologo("Ernesto Salgado",150,"Pachuca");
	iserv++;

	usua[iusua] = new Usuario("Ramon Martínez");
	iusua++;
	usua[iusua] = new Usuario("Andrea Piñeiro");
	iusua++;
}

/* Esta funcion muestra todos los servicios disponibles, usando el numero de servicio
 * para recorrer el arreglo de serv y usar punteros y polimorfismo para acceder al método
 * mostrar. 
 * (->) es lo mismo que (*serv[i]).mostrar();
 * lo cual representa que tengo un puntero que va hacia un servicio nuevo, y con * muestro
 * el valor dentro de lo que señala el puntero
*/
void Buscador::muestra_servicios(){
	for(int i=0;i<iserv; i++)
		cout << serv[i]->mostrar();
}

/* En esta función se muestran solo los servicios que coinciden con algun tipo:
 * ENTRENAMIENTO ONLINE, GIMNASIO, NUTRICIÓN
 * Se usa recorre el arreglo igual que en la función pasada y con punteros se accede
 * al nombre del servicio; si este coincide se accede al método mostrar.
*/
void Buscador::muestra_servicios(string tipo_serv){
	for(int i=0;i<iserv;i++){
		if(serv[i]->get_nombre_servicio() == tipo_serv)
			cout << serv[i]->mostrar();
	}
}

/* Esta funcion muestra todos los usuarios registrados, usando el numero de servicio
 * para recorrer el arreglo de serv y usar punteros y polimorfismo para acceder al método
 * mostrar. */
void Buscador::muestra_usuarios(){
	for(int i=0; i<iusua; i++)
		cout << usua[i]->mostrar();
}

// Esta función agrega un objeto gimnasio al arreglo de servicios
void Buscador::agrega_gimnasio(string t, float precio, int promo,string nom, string ciud, float esp, long tel, int d){
	serv[iserv] = new Gimnasio (t,precio,promo,nom,ciud,esp,tel,d);
	iserv++;
}

// Esta función agrega un objeto entrenamiento online al arreglo de servicios
void Buscador::agrega_online(string t, float precio, int promo,int clases, string web){
	serv[iserv] = new Online(t, precio,promo,clases,web);
	iserv++;
}

// Esta función agrega un objeto nutriolog al arreglo de servicios
void Buscador::agrega_nutriologo(string nom_nutri, float precio_c, string ciud){
	serv[iserv] = new Nutriologo(nom_nutri, precio_c, ciud);
	iserv++;
}

// Esta función agrega un objeto usuario al arreglo de usuarios
void Buscador::agrega_usuario(string nom){
	usua[iusua] = new Usuario(nom);
	iusua++;
}

#endif
