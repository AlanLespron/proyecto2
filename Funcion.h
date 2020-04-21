#include "Hora.h"
class Funcion
{
public:
Funcion(); //defalt
Funcion(Hora hora,int numPeli , int sala , std::string cveFuncion);
void setNumPeli(int numPeli)  {numPeli = numPeli;};
void setSala(int sala)  {sala = sala;};
void setcveFuncion(std::string cveFuncion)  {cveFuncion = cveFuncion;};
std::string getcveFuncion() {return cveFuncion;};
int getNumPeli() {return numPeli;};
int getSala() {return sala;};
Hora getHora() {return hora;};
void Muestra();
private:
int numPeli , sala;
std::string cveFuncion;
Hora hora;
};

Funcion::Funcion(){
  cveFuncion = "Prueba";
  numPeli = 0;
  sala = 0;
  hora.setH(0);
  hora.setMin(0);
}
Funcion::Funcion(Hora hora,int numPeli , int sala , std::string cveFuncion){
this->hora.setH(hora.getH());
this->hora.setMin(hora.getMin());
this->numPeli = numPeli;
this->sala = sala;
this->cveFuncion = cveFuncion;

}
void Funcion::Muestra(){
  cout << "cve " << cveFuncion << " NumeroP " << numPeli << " Sala " << sala << " ";
  hora.Muestra();
}
