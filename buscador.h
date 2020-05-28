/*
Proyecto Buscador
Andrea Piñeiro Cavazos
A01705681
28/05/2020
*/

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
	// Se definen los atributos de la clase
  private:
    // Se usan apuntadores para las listas de servicios y usuarios
		Servicio *serv[MAX];
		Usuario *usua[MAX];

    // Estos índices servirán como referencia para saber cuántos servicios y usuarios tienen las listas
		int iserv;
		int iusua;

  // Se definen los métodos de la clase
	public:
    // Se crea un constructor vacío
		Buscador(): iserv(0), iusua(0){};

		void crea_ejemplos();
		void muestra_servicios();
		void muestra_servicios(string tipo_serv);
		void muestra_usuarios();
    void buscar_servicio(string tipo_serv, string nom);
    void buscar_serv_cerca(string ciudad);

		void agrega_gimnasio(string nom, string t, float precio, int promo, string ciud, float esp, long tel, int d);
		void agrega_online(string nom,string t, float precio, int promo,int clases, string web);
		void agrega_nutriologo(string nom_nutri, float precio_c, string ciud);
		void agrega_usuario(string nom);
    void agrega_calificacion(string nom, int calif);
    void agrega_reseña(string nom, string res);
    void inscribe_client(string nombre_serv, string nom_cliente);
    void modifica_precio(string nom, float pre);
    void modifica_promocion(string nom, float promo);
    void agregar_entrenador(string nom_gim, string nom_entrenador_nuevo);
    void agregar_horario(string nom_gim, string nuevo_horario);

};

//Crea objetos para Servicio y para Usuarios y guarda estos objetos en la posición iserv o
//iusua del arreglo
//new crea el objeto usando polimorfismo 
void Buscador::crea_ejemplos(){
	serv[iserv] = new Gimnasio("Black Bull","crossfit",50, 20,"Queretaro",350,4423277564,5);
  serv[iserv]->set_calificacion_nueva(10);
  serv[iserv]->set_nueva_resena("Muy buena opción!");
  serv[iserv]->set_nuevo_inscrito("Ximena González");
  dynamic_cast<Entrenamiento*>(serv[iserv])->set_entrenador_nuevo("Raúl Durán");
  dynamic_cast<Entrenamiento*>(serv[iserv])->set_horario_nuevo("6:30 , 8:00 , 9:30 , 18:30 , 20:00");
	iserv++;

	serv[iserv] = new Gimnasio("Logma","trx",100,0,"Pachuca",200,7721546374,5);
  serv[iserv]->set_calificacion_nueva(5);
  serv[iserv]->set_nueva_resena("Buenos entrenadores.");
  serv[iserv]->set_nuevo_inscrito("Ramón Martinez");
  dynamic_cast<Entrenamiento*>(serv[iserv])->set_entrenador_nuevo("Eduardo Carrasco");
  dynamic_cast<Entrenamiento*>(serv[iserv])->set_horario_nuevo("6:30 , 8:00 , 18:30 , 20:00");
	iserv++;

	serv[iserv] = new Online("OnlineX","trx",30,0,3,"https://argen.com");
  serv[iserv]->set_calificacion_nueva(2);
  serv[iserv]->set_nueva_resena("La calidad de los videos es muy mala.");
  serv[iserv]->set_nuevo_inscrito("Andrea Piñeiro");
  dynamic_cast<Entrenamiento*>(serv[iserv])->set_entrenador_nuevo("Norma Rodríguez");
  dynamic_cast<Entrenamiento*>(serv[iserv])->set_horario_nuevo("6:30 , 21:00");
	iserv++;

	serv[iserv] = new Online("Complex", "HIIT",20,10,4,"https://entrenamiento.com");
  serv[iserv]->set_calificacion_nueva(7);
  serv[iserv]->set_nueva_resena("Entrenamientos variados");
  dynamic_cast<Entrenamiento*>(serv[iserv])->set_entrenador_nuevo("Alicia Cavazos");
  dynamic_cast<Entrenamiento*>(serv[iserv])->set_horario_nuevo("6:30 , 9:00 , 21:00");
	iserv++;

	serv[iserv] = new Nutriologo("Sofía García",350,"Queretaro");
  serv[iserv]->set_calificacion_nueva(10);
  serv[iserv]->set_nueva_resena("Excelente servicio");
  serv[iserv]->set_nuevo_inscrito("Andrea Piñeiro");
	iserv++;

	serv[iserv] = new Nutriologo("Ernesto Salgado",150,"Pachuca");
  serv[iserv]->set_calificacion_nueva(7);
  serv[iserv]->set_nueva_resena("Regular");
  serv[iserv]->set_nuevo_inscrito("Ximena González");
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
void Buscador::agrega_gimnasio(string nom, string t, float precio, int promo, string ciud, float esp, long tel, int d){
	serv[iserv] = new Gimnasio (nom, t,precio,promo,ciud,esp,tel,d);
	iserv++;
}

// Esta función agrega un objeto entrenamiento online al arreglo de servicios
void Buscador::agrega_online(string nom,string t, float precio, int promo,int clases, string web){
	serv[iserv] = new Online(nom,t, precio,promo,clases,web);
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

// Esta función busca un servicio recibiendo dos parámetros, el tipo de servicio y el nombre 
// del gimnasio, entrenamiento online o nutriólogo
void Buscador::buscar_servicio(string tipo_serv, string nom){
	for (int i=0; i<iserv;i++){
		if ((serv[i]->get_nombre_servicio() == tipo_serv)&&(serv[i]->get_nombre()== nom)){
			cout << serv[i]->mostrar();
		}
	}
}

// Esta función busca servicios en tu ciudad (gimnasios, nutriólogos), recibe como parámetro 
// la ciudad donde vives y usa un dinamic_cast para que el Servicio adquiera la forma "hijo" 
// y pueda acceder al método de la clase hija.
void Buscador::buscar_serv_cerca(string ciudad){
	for (int i=0; i<iserv;i++){
		if (serv[i]->get_nombre_servicio()=="GIMNASIO"){
      Gimnasio *g = dynamic_cast<Gimnasio*>(serv[i]);
      if (g-> get_ciudad()==ciudad){
        cout << serv[i]-> mostrar();
      }
		} else if(serv[i]->get_nombre_servicio()=="NUTRICIÓN"){
      Nutriologo *n = dynamic_cast <Nutriologo*>(serv[i]);
      if (n-> get_ciudad()==ciudad){
        cout << serv[i]->mostrar();
      } else {
      }
    }
	}
}

// Esta función agrega una nueva calificación a algún servicio; recibe como parámetro el 
// nombre del servicio y la calificación
void Buscador::agrega_calificacion(string nom, int calif){
  for (int i=0; i<iserv; i++){
    if (serv[i]-> get_nombre()==nom){
      serv[i]->set_calificacion_nueva(calif);
    }
  }
}

// Esta función agrega una nueva reseña a algún servicio; recibe como parámetro el 
// nombre del servicio y la reseña
void Buscador::agrega_reseña(string nom, string res){
  for (int i=0; i<iserv; i++){
    if (serv[i]-> get_nombre()==nom){
      serv[i]->set_nueva_resena(res);
    }
  }
}

// Esta función inscribe a alguno de los usuarios en los servicios, se reciben como parámetros
// el nombre del servicio y el nombre del cliente.
void Buscador::inscribe_client(string nombre_serv, string nom_cliente){
  for (int i=0; i<iserv;i++){
    if (serv[i]-> get_nombre()==nombre_serv){
      serv[i]-> set_nuevo_inscrito(nom_cliente);
    }
  }
}

// Esta función modifica el precio del servicio; checa el tipo de servicio para usar un 
// dynamic_cast de la clase respectiva y acceder al método correspondiente. 
// Recibe el nombre del servicio y el nuevo precio. 
void Buscador::modifica_precio(string nom, float pre){
  for (int i=0; i<iserv;i++){
		if ((serv[i]->get_nombre_servicio()=="GIMNASIO")or(serv[i]->get_nombre_servicio()=="ENTRENAMIENTO ONLINE")){
      Entrenamiento *g = dynamic_cast<Entrenamiento*>(serv[i]);
      if (g-> get_nombre()==nom){
        g->set_precio_clase(pre);
      }
		} else if (serv[i]->get_nombre_servicio()=="NUTRICIÓN"){
      Nutriologo *n = dynamic_cast <Nutriologo*> (serv[i]);
      if (n->get_nombre()==nom){
        n-> set_precio_consulta(pre);
      }
    } else{
    }
  }
}

// Esta función modifica la promoción del servicio; checa el tipo de servicio para usar un 
// dynamic_cast de la clase respectiva y acceder al método correspondiente. 
// Recibe el nombre del servicio y la nueva promoción. 
void Buscador::modifica_promocion(string nom, float promo){
  for (int i=0; i<iserv;i++){
		if ((serv[i]->get_nombre_servicio()=="GIMNASIO")or(serv[i]->get_nombre_servicio()=="ENTRENAMIENTO ONLINE")){
      Entrenamiento *g = dynamic_cast<Entrenamiento*>(serv[i]);
      if (g-> get_nombre()==nom){
        g->set_promocion(promo);
      }
		} else{
    }
  }
}

// Esta función agrega un nuevo entrenador al vector de entrenadores; checa el tipo de servicio 
// para usar un dynamic_cast de la clase respectiva y acceder al método correspondiente. 
// Recibe el nombre del entrenamiento y del nuevo entrenador. 
void Buscador::agregar_entrenador(string nom_gim, string nom_entrenador_nuevo){
  for (int i=0; i<iserv;i++){
		if ((serv[i]->get_nombre_servicio()=="GIMNASIO")or(serv[i]->get_nombre_servicio()=="ENTRENAMIENTO ONLINE")){
      Entrenamiento *g = dynamic_cast<Entrenamiento*>(serv[i]);
      if (g-> get_nombre()==nom_gim){
        g->set_entrenador_nuevo(nom_entrenador_nuevo);
      }
		} else{
    }
  }
}

// Esta función agrega un nuevo horario al vector de horarios; checa el tipo de servicio 
// para usar un dynamic_cast de la clase respectiva y acceder al método correspondiente. 
// Recibe el nombre del entrenamiento y el nuevo horario. 
void Buscador::agregar_horario(string nom_gim, string nuevo_horario){
  for (int i=0; i<iserv;i++){
		if ((serv[i]->get_nombre_servicio()=="GIMNASIO")or(serv[i]->get_nombre_servicio()=="ENTRENAMIENTO ONLINE")){
      Entrenamiento *g = dynamic_cast<Entrenamiento*>(serv[i]);
      if (g-> get_nombre()==nom_gim){
        g->set_horario_nuevo(nuevo_horario);
      }
		} else{
    }
  }
}

//delete (serv[MAX]);
//delete (usua[MAX]);

#endif