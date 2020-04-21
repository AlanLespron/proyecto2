#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "Actor.h"
#include "Pelicula.h"
#include "Funcion.h"
  Actor matrizActores[20];
  Pelicula matrizPelicula[20];
  Funcion matrizFuncion[20];

void agregarActor(Actor ob) {
  for (int i = 0; i <= 20; i++) {
    if (matrizActores[i].getId()==0){
      matrizActores[i] = ob;
      return;
    }
  }
}

void cargarArchivos() {
  ifstream archivoActores;
  ifstream archivoPelicula;
  int idPelicula , anio , duracion , cantActores, idActor,index = 0;
  string NombreActor, infoActores , genero , nombrepeli, line;
  archivoActores.open("actores.txt");
  archivoPelicula.open("peliculas.txt");

  while (getline(archivoActores, line)) {
    idActor = stoi(line);
    line.erase(0, to_string(idActor).length() + 1 );
    Actor actor(idActor, line);
    agregarActor(actor);
  }
    string shelper;

  while(getline(archivoPelicula, line)){
    shelper = line.substr(0, line.find(' '));
    line = line.erase(0, line.find(' ')+1);

    stringstream geek(shelper);
    geek >> idPelicula;
    matrizPelicula[index].setnumPeli(idPelicula);
    shelper = line.substr(0, line.find(' '));
    line = line.erase(0, line.find(' ')+1);

    stringstream geek2(shelper);
    geek2 >> anio;
    matrizPelicula[index].setanio(anio);
    shelper = line.substr(0, line.find(' '));
    line = line.erase(0, line.find(' ')+1);

    stringstream geek3(shelper);
    geek3 >> duracion;
    matrizPelicula[index].setduracion(duracion);
    genero = line.substr(0, line.find(' '));
    line = line.erase(0, line.find(' ')+1);
    matrizPelicula[index].setgenero(genero);
    shelper = line.substr(0, line.find(' '));
    line = line.erase(0, line.find(' ')+1);

    stringstream geek4(shelper);
    geek4 >> cantActores;
    matrizPelicula[index].setcantActores(cantActores);
    for(int e = 0;e < cantActores; e++){

        shelper = line.substr(0, line.find(' '));

        idActor = stoi(shelper);
        for(int u = 0; u < 20; u++){

            if( idActor == matrizActores[u].getId() ){
              matrizPelicula[index].meteActor(matrizActores[u]);
            }
        }
      line = line.erase(0, line.find(' ')+1);
    }
    nombrepeli = line.substr();
    matrizPelicula[index].settitulo(nombrepeli);
    index++;
  }
}
void consultarActores(){
  for(int x = 0; x < 20; x++ ){
    cout << to_string(matrizActores[x].getId()) << " " << matrizActores[x].getNombre() << endl;
  }
}
void consultarPeliculas(){
  for(int x = 0; x < 20; x++ ){
        if(matrizPelicula[x].getnumPeli()!= 0){
            cout << matrizPelicula[x].gettitulo() << " " << matrizPelicula[x].getanio()<<" "<<matrizPelicula[x].getduracion() << " " << matrizPelicula[x].getgenero() <<endl;

            for(int i = 0; i < matrizPelicula[x].getcantActores() ; i++){
                cout << matrizPelicula[x].getActor(i).getNombre() << endl;
            }
        }

  }
}
void ingresarHorario(){

}
Pelicula buscarPelicula(int id){
    for(int x = 0; x < 21 ;x++){
       if( id == matrizPelicula[x].getnumPeli()){
        return matrizPelicula[x];
       }
    }
    return Pelicula();
}
void dibujarMenu(){
  cout << "                   Menu " << endl;
  cout << " [1] Consulta de todos los actores que están en la lista " << endl;
  cout << " [2] Consulta de todas las películas que están en la lista " << endl ;
  cout << " [3] Consulta de todas las funciones disponibles " << endl ;
  cout << " [4] Consulta de funciones por hora " << endl ;
  cout << " [5] Consulta por clave de función "<< endl;
  cout << " [6] Consulta de películas en las que participa un actor "<< endl;
  cout << " [0] Terminar " << endl ;
}
void agregarFunciones(){
    bool check = 1;
    while(check == 1) {
        int numeroFuncion , claveFuncion , numeroPelicula , hora , minutos , numeroSala;
        cout<<"Cuantas funciones quieres agregar? (Maximo 20)"<<endl;
        cin>>numeroFuncion;
        if (numeroFuncion< 21 && numeroFuncion > 0) {
            for (int x = 0; x < numeroFuncion; x++) {
                cout << "Ingrese la clave de la Funcion: " << endl;
                cin >> claveFuncion;
                cout << "Ingrese el número de película: " << endl;
                cin >> numeroPelicula;
                cout << "Ingrese la hora de la funcion (Hora luego Minutos): " << endl;
                cin >> hora;
                cin >> minutos;
                cout << "Ingrese el número de sala: " << endl;
                cin >> numeroSala;

                Hora horaFuncion(hora, minutos);
                Funcion funcion(horaFuncion , numeroPelicula ,numeroSala ,to_string(claveFuncion));
                matrizFuncion[x] = funcion;


            }
            check = 0;
        }
        else {
            cout << "Ese número de funciones no es valido." << endl;
            check = 0;
        }
    }
}

void consultarFunciones(){
    for(int x = 0; x < 20 ;x++){

        if(matrizFuncion[x].getcveFuncion().empty() ){
            continue;
        }
        Funcion func = matrizFuncion[x];
        Pelicula peli =  buscarPelicula(func.getNumPeli());
        if(peli.getnumPeli() == 0  ){
            continue;
        }

        cout << func.getcveFuncion() << " " << peli.gettitulo()<< " " <<to_string( func.getSala()) << " " << to_string(func.getHora().getH()) <<":" << to_string(func.getHora().getMin()) << endl;
    }
}
int main() {

  cargarArchivos();
  int opc;
  bool finish = true;
  while(finish){

      dibujarMenu();

      cin >> opc;

        switch(opc){
            case 1:
              consultarActores();
            break;
            case 2:
              consultarPeliculas();
            break;
            case 3:
                consultarFunciones();
            break;
            case 4:

            break;
            case 5:

            break;
            case 6:

            break;
            case 7:
                agregarFunciones();
            break;
            case 0:
                exit(0);
            break;
            default: cout << "No existe" <<endl;
            break;
        }
    }
}

//asi nomas  pariente
