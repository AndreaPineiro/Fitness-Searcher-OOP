/*
Proyecto Buscador
Andrea Piñeiro Cavazos
A01705681
28/05/2020
*/

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

  cout << "\t\tU S U A R I O S\t\t\n\n";
  fitever.muestra_usuarios();
  cout << endl << endl;

  cout << "\t\tAGREGA GIMNASIO\t\t\n\n";
  fitever.agrega_gimnasio("AX12","box",100,40,"Pachuca",400,7713277338,6);

  cout << "\t\tAGREGA ENTRENAMIENTO ONLINE\t\t\n\n";
  fitever.agrega_online("Orux","crossfit",45,0,4,"https//online.com");

  cout << "\t\tAGREGA NUTRIÓLOGO\t\t\n\n";
  fitever.agrega_nutriologo("Mariana Díaz",100,"Querétaro");

  cout << "\t\tAGREGA USUARIO\t\t\n\n";
  fitever.agrega_usuario("Ximena González");

  cout << "\t\tAGREGAMOS CALIFICACIONES\t\t\n\n";
  fitever.agrega_calificacion("Black Bull", 9);
  fitever.agrega_calificacion("AX12", 10);
  fitever.agrega_calificacion("Black Bull", 8);
  fitever.agrega_calificacion("Orux", 5);
  fitever.agrega_calificacion("Mariana Díaz", 2);
  fitever.agrega_calificacion("Mariana Díaz", 8);
  
  cout << "\t\tAGREGAMOS RESEÑAS\t\t\n\n";
  fitever.agrega_reseña("AX12", "Muy buen gimnasio");
  fitever.agrega_reseña("AX12", "Horrible!!");
  fitever.agrega_reseña("Orux", "Excelente servicio");
  fitever.agrega_reseña("Orux", "Muy buen personal");

  cout << "\t\tINSCRIBIMOS USUARIOS EN SERVICIOS\t\t\n\n";
  fitever.inscribe_client("AX12", "Ximena González");
  fitever.inscribe_client("AX12", "Ernesto Salgado");
  fitever.inscribe_client("Black Bull", "Andrea Piñeiro");
  fitever.inscribe_client("Mariana Díaz", "Ximena González");
  fitever.inscribe_client("Mariana Díaz", "Ramón Martínez");

  cout << "\t\tMODIFICAMOS DATOS\t\t\n\n";fitever.modifica_precio("AX12", 150.50);
  fitever.modifica_promocion("AX12",10);
  fitever.agregar_entrenador("AX12","Jaime Pérez");
  fitever.agregar_horario("AX12","7:30");


  cout << "\t\tS E R V I C I O S\t\t\n\n";
  fitever.muestra_servicios();
  cout << endl << endl;

  cout << "\t\tN U T R I C I Ó N\t\t\n\n";
  fitever.muestra_servicios("NUTRICIÓN");
  cout << endl << endl;

  cout << "\t\tB U S C A R   A X 1 2\t\t\n";
  fitever.buscar_servicio("GIMNASIO","AX12");

  cout << "\t\tB U S C A R    M A R I A N A    D Í A Z\t\t\n";
  fitever.buscar_servicio("NUTRICIÓN","Mariana Díaz");

  cout << "\t\tB U S C A R    E N   P A C H U C A\t\t\n";
  fitever.buscar_serv_cerca("Pachuca");

}