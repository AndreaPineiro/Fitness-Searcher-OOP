/*
Proyecto Buscador
Main
Andrea Piñeiro Cavazos
A01705681
28/05/2020
*/

#include <iostream>
#include <string>

#include"buscador.h"
using namespace std;

//Esta función crea las opciones que se desplegaran en la pantalla para el usuario 
void opciones(){
  cout << "\n\t\t\tBIENVENIDO A FITEVER\t\t\t\n\n";
  cout << "\t\t\tEsta son las siguientes opciones\n";
  cout << "1. Muestra todos los servicios \n";
  cout << "2. Muestra todos los servicios de un tipo\n";
  cout << "3. Muestra usuarios\n";
  cout << "4. Buscar servicio por nombre\n";
  cout << "5. Buscar servicios en mi ciudad\n";
  cout << "6. Agregar nuevo gimnasio\n";
  cout << "7. Agregar nuevo entrenamiento online\n";
  cout << "8. Agregar nuevo nutriólogo\n";
  cout << "9. Agregar nuevo usuario\n";
  cout << "10. Calificar servicio\n";
  cout << "11. Añadir una reseña\n";
  cout << "12. Inscribir cliente\n";
  cout << "13. Modificar precio de un servicio\n";
  cout << "14. Modificar promoción\n";
  cout << "15. Agregar nuevo entrenador\n";
  cout << "16. Agregar nuevo horario\n";
  cout << "17. Salir\n";

}



int main(int argc, char*arg[]){
  Buscador fitever;
  //Se crean ejemplos de servicios
  fitever.crea_ejemplos();

  //Se especifican los tipos de datos al crear objetos
  int opcion=0, ntipo=0, promo, dias, clases, calif; 
  string nom, ciud, t_entre, web, agregar, entre, agregar2, hora, rsñ, nom2;
  float precio, esp;
  long tel;

  //Aquí se imprime el menú de opciones y el usuario puede elegir una
  while (opcion<17 && opcion>-1){
    opciones();

    cout << "\nElige la opción que prefieras: ";
    cin >> opcion;

    //Con este switch dependiendo de la elección del usuario se realiza una función
    switch(opcion){

      //Se muestran todos los servicios disponibles
      case 1:
        fitever.muestra_servicios();
      break;

      //Se muestran solo los servicios de cierto tipo
      case 2:
        cout << "\nTipos de servicio:\n\t 1.Gimnasio\n\t 2.Nutrición\n\t 3.Entrenamiento Online\n";
        while (ntipo<1 || ntipo>3){
          cout << "\n¿Qué tipo de servicio estás buscando?: ";
          cin >> ntipo;
          cout << "\n";

          if (ntipo==1){
            fitever.muestra_servicios("GIMNASIO");
          } else if (ntipo==2){
            fitever.muestra_servicios("NUTRICIÓN");
          } else if (ntipo==3) {
            fitever.muestra_servicios("ENTRENAMIENTO ONLINE");
          } 
        }
      break;

      //Se muestran todos los usuarios
      case 3:
        fitever.muestra_usuarios();
      break;

      //Puedes buscar un servicio por nombre, tienes que ingresar el tipo de servicio y el nombre.
      case 4:
        cout << "\n";
        cout << "\n\t 1.Gimnasio\n\t 2.Nutrición\n\t 3.Entrenamiento Online\n";
 
        while (ntipo<1 || ntipo>3){
          cout << "\nTipo de servicio: ";
          cin >> ntipo;
          cout << "Nombre: ";
          cin.ignore();
          getline(cin,nom);
          cout << "\n";
          if (ntipo==1){
            fitever.buscar_servicio("GIMNASIO",nom);
          } else if (ntipo==2){
            fitever.buscar_servicio("NUTRICIÓN",nom);
          } else if (ntipo==3) {
            fitever.buscar_servicio("ENTRENAMIENTO ONLINE",nom);
          }  
        } 
      break;

      //Muestra todos los servicios en tu ciudad
      case 5:
        cout << "Ciudad: ";
        cin >> ciud;
        fitever.buscar_serv_cerca(ciud);
      break;

      //Añade un nuevo gimnasio con los datos que proporciona el usuario y da la opción de agregar entrenadores y/o horarios
      case 6:
        cout << "\nNombre: ";
        cin.ignore();
        getline(cin,nom);
        cout << "Tipo de entrenamiento: ";
        cin >> t_entre;
        cout << "Precio: ";
        cin >> precio;
        cout << "Promoción: ";
        cin >> promo;
        cout << "Ciudad: ";
        cin >> ciud;
        cout << "Espacio (m^2): ";
        cin >> esp;
        cout << "Teléfono: ";
        cin >> tel;
        cout << "Número de días que abre: ";
        cin >> dias;
        fitever.agrega_gimnasio(nom, t_entre, precio, promo, ciud, esp, tel, dias);

        cout << "\n¿Quieres agregar entrenadores?: ";
        cin >> agregar;
        while (agregar=="si" || agregar=="SI"||agregar=="Si"){
          cout << "Nombre del entrenador:";
          cin.ignore();
          getline(cin, entre);
          fitever.agregar_entrenador(nom,entre);
          cout << "\n¿Quieres agregar otro entrenador?: " ;
          cin >> agregar;
        }

        cout << "\n¿Quieres agregar horarios?: ";
        cin >> agregar2;
        while (agregar2=="si" || agregar2=="SI"||agregar2=="Si"){
          cout << "Horario: ";
          cin >> hora;
          fitever.agregar_horario(nom,hora);
          cout << "\n¿Quieres agregar otro horario?: ";
          cin >> agregar2;
        }

      break;

      //Agrega un nuevo entrenamiento online con los datos que ingresa el usuario y como en el anterior, puedes agregar entrenadores y/o horarios
      case 7:
        cout << "\nNombre: ";
        cin.ignore();
        getline(cin,nom);
        cout << "Tipo de entrenamiento: ";
        cin >> t_entre;
        cout << "\nPrecio: ";
        cin >> precio;
        cout << "\nPromoción: ";
        cin >> promo;
        cout << "\nClases a la semana: ";
        cin >> clases;
        cout << "\nPágina web: ";
        cin >> web;
        fitever.agrega_online(nom,t_entre,precio,promo,clases,web);

        cout << "\n¿Quieres agregar entrenadores?: ";
        cin >> agregar;
        while (agregar=="si" || agregar=="SI"||agregar=="Si"){
          cout << "Nombre del entrenador:";
          cin.ignore();
          getline(cin, entre);
          fitever.agregar_entrenador(nom,entre);
          cout << "\n¿Quieres agregar otro entrenador?: " ;
          cin >> agregar;
        }
      break; 

      //Agrega un nuevo nutriólogo
      case 8:
        cout << "\nNombre: ";
        cin.ignore();
        getline(cin,nom);
        cout << "Precio: ";
        cin >> precio;
        cout << "Ciudad: ";
        cin >> ciud;
        fitever.agrega_nutriologo(nom,precio,ciud);
      break;

      //Agrega un nuevo usuario
      case 9:
        cout << "\nNombre: ";
        cin.ignore();
        getline(cin,nom);
        fitever.agrega_usuario(nom);
      break;

      //Añade una nueva calificación, recibe el nombre del servicio y la nueva calificación
      case 10:
        cout << "\nNombre: ";
        cin.ignore();
        getline(cin,nom);
        cout << "Calificación: ";
        cin >> calif;
        fitever.agrega_calificacion(nom, calif);
      break;

      //Añade una nueva reseña, recibe el nombre del servicio y la nueva reseña
      case 11:
        cout << "\nNombre: ";
        cin.ignore();
        getline(cin,nom);
        cout << "Reseña: ";
        cin.ignore();
        getline(cin,rsñ);
        fitever.agrega_resena(nom,rsñ);
      break;

      //Aqui se recibe el nombre de un servicio y de un cliente; y se inscribe al cliente en el servicio
      case 12:
        cout << "\nNombre del servicio: ";
        cin.ignore();
        getline(cin,nom);
        cout << "Nombre del cliente: ";
        cin.ignore();
        getline(cin,nom2);
        fitever.inscribe_client(nom, nom2);
      break;

      //Se modifica el precio de alguno de los servicios
      case 13:
        cout << "\nNombre del servicio: ";
        cin.ignore();
        getline(cin,nom);
        cout << "Nuevo precio: ";
        cin >> precio;
        fitever.modifica_precio(nom,precio);
      break;

      //Se modifica la promoción de alguno de los servicios
      case 14:
        cout << "\nNombre del servicio: ";
        cin.ignore();
        getline(cin,nom);
        cout << "Nuevo porcentaje de promoción: ";
        cin >> promo;
        fitever.modifica_promocion(nom,promo);
      break;

      //Agrega un nuevo entrenador, recibe el nombre del servicio y el nombre del entrenador
      case 15:
        cout << "\nNombre del gimnasio/entrenamiento online: ";
        cin.ignore();
        getline(cin,nom);
        cout << "Nombre del entrenador: ";
        cin.ignore();
        getline(cin,entre);
        fitever.agregar_entrenador(nom,entre);
      break;

      //Agrega un nuevo horario, recibe el nombre del servicio y el nombre del entrenador
      case 16:
        cout << "\nNombre del gimnasio/entrenamiento online: ";
        cin.ignore();
        getline(cin,nom);
        cout << "Nuevo horario: ";
        cin.ignore();
        getline(cin,hora);
        fitever.agregar_horario(nom,hora);
      break;
    }
  }
}