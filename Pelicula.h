// Pelicula.h
#include <iostream>
#include <iomanip>

class Pelicula
{
public:
    Pelicula(); //defalt
    bool meteActor(Actor actor);
    void setnumPeli(int numPeli)  {this->numPeli = numPeli;};
    void setanio(int anio)  {this->anio = anio;};
    void setduracion(int duracion)  {this->duracion = duracion;};
    void settitulo(std::string titulo)  {this->titulo = titulo;};
    void setgenero(std::string genero)  {this->genero = genero;};
    void setcantActores(int cantActores) {this->cantActores = cantActores;};
    std::string getgenero()  {return genero;};
    std::string gettitulo()  {return titulo;};
	int getnumPeli()  {return numPeli;};
	int getanio()  {return anio;};
    int getcantActores() {return cantActores;};
    int getduracion()  {return duracion;};
    Actor getActor(int ide ) {return listaActores[ide] ;};
private:
	int numPeli , anio , cantActores , duracion ;
    std::string titulo , genero ;
    Actor listaActores[10];
};

Pelicula::Pelicula(){
  /*numPeli = NULL;
  anio = NULL;
  cantActores = NULL;
  duracion = NULL;
  titulo;
  genero; */
}

bool Pelicula::meteActor(Actor actor){
    for(int x = 0; x < 10 ; x++ ){

        if(listaActores[x].getId() < 1){
           listaActores[x] = actor;
           return true;
        }
    }

    return false;

}

