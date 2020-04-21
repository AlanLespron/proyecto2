
class Actor
{
public:
Actor(); //defalt
Actor(int id ,std::string nombre);
void setId(int id);
void setNombre(std::string nombre);
std::string getNombre() {return nombre;};
int getId() {return id;};
void Muestra();
private:
int id;
std::string nombre;
};

Actor::Actor(){
  nombre = " ";
  id = 0;
}
Actor::Actor(int id ,std::string nombre ){
  this->id = id;
  this->nombre = nombre;

}
void Actor::Muestra(){
  cout <<"id " << id << " Nombre " << nombre;
}
