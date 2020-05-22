#include <iostream>
#include <string>

#include"buscador.h"
using namespace std;

//En este main se muestra que funcionan los métodos en buscador.h
int main(){
	Buscador fitever;

	fitever.crea_ejemplos();
	cout << "Ejemplos creados!" << endl << endl;

	cout << "\t\tS E R V I C I O S\t\t\n\n";
	fitever.muestra_servicios();
	cout << endl << endl;

	cout << "\t\tN U T R I C I Ó N\t\t\n\n";
	fitever.muestra_servicios("NUTRICIÓN");
	cout << endl << endl;

	cout << "\t\tU S U A R I O S\t\t\n\n";
	fitever.muestra_usuarios();
	cout << endl << endl;

	cout << "\t\tAGREGA GIMNASIO\t\t\n\n";
	fitever.agrega_gimnasio("box",100,40,"AX12","Pachuca",400,7713277338,6);

	cout << "\t\tAGREGA ENTRENAMIENTO ONLINE\t\t\n\n";
	fitever.agrega_online("crossfit",45,0,4,"https//online.com");

	cout << "\t\tAGREGA NUTRIÓLOGO\t\t\n\n";
	fitever.agrega_nutriologo("Mariana Díaz",100,"Querétaro");

	cout << "\t\tAGREGA USUARIO\t\t\n\n";
	fitever.agrega_usuario("Ximena");

	cout << "\t\tS E R V I C I O S\t\t\n\n";
	fitever.muestra_servicios();
	cout << endl << endl;

}