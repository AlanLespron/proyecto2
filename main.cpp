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

void agregarActor(Actor ob)
{
    for (int i = 0; i <= 20; i++)
    {
        if (matrizActores[i].getId()==0)
        {
            matrizActores[i] = ob;
            return;
        }
    }
}

void cargarArchivos()
{
    ifstream archivoActores;
    ifstream archivoPelicula;
    int idPelicula, anio, duracion, cantActores, idActor,index = 0;
    string NombreActor, infoActores, genero, nombrepeli, line;
    archivoActores.open("actores.txt");
    archivoPelicula.open("peliculas.txt");

    while (getline(archivoActores, line))
    {
        idActor = stoi(line);
        line.erase(0, to_string(idActor).length() + 1 );
        Actor actor(idActor, line);
        agregarActor(actor);
    }
    string shelper;

    while(getline(archivoPelicula, line))
    {
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
        for(int e = 0; e < cantActores; e++)
        {

            shelper = line.substr(0, line.find(' '));

            idActor = stoi(shelper);
            for(int u = 0; u < 20; u++)
            {

                if( idActor == matrizActores[u].getId() )
                {
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
void consultarActores()
{
    for(int x = 0; x < 20; x++ )
    {
        cout << "Id y Nombre del Actor:  " << to_string(matrizActores[x].getId()) <<" " << matrizActores[x].getNombre() << endl;
    }
}
void consultarPeliculas()
{
    for(int x = 0; x < 20; x++ )
    {
        if(matrizPelicula[x].getnumPeli()!= 0)
        {
            cout << "Nombre de la pelicula: "<<matrizPelicula[x].gettitulo() << endl;
            cout << " Año: " << matrizPelicula[x].getanio() << endl;
            cout <<" Duracion: "<<matrizPelicula[x].getduracion() << endl;
            cout << " Genereo: " << matrizPelicula[x].getgenero() << endl;

            for(int i = 0; i < matrizPelicula[x].getcantActores() ; i++)
            {
                cout <<"Nombre del actor: " << matrizPelicula[x].getActor(i).getNombre() << endl;
            }
        }

    }
}
Pelicula buscarPelicula(int id)
{
    for(int x = 0; x < 21 ; x++)
    {
        if( id == matrizPelicula[x].getnumPeli())
        {
            return matrizPelicula[x];
        }
    }
    return Pelicula();
}
void dibujarMenu()
{
    cout << "                   Menu " << endl;
    cout << " [1] Consulta de todos los actores que están en la lista " << endl;
    cout << " [2] Consulta de todas las películas que están en la lista " << endl ;
    cout << " [3] Consulta de todas las funciones disponibles " << endl ;
    cout << " [4] Consulta de funciones por hora " << endl ;
    cout << " [5] Consulta por clave de función "<< endl;
    cout << " [6] Consulta de películas en las que participa un actor "<< endl;
    cout << " [0] Terminar " << endl ;
}
void agregarFunciones()
{
    bool check = 1;
    while(check == 1)
    {
        int numeroFuncion,numeroPelicula, hora, minutos, numeroSala;
        string claveFuncion ;
        cout<<"Cuantas funciones quieres agregar? (Maximo 20)"<<endl;
        cin>>numeroFuncion;
        if (numeroFuncion< 21 && numeroFuncion > 0)
        {
            for (int x = 0; x < numeroFuncion; x++)
            {
                cout << "Ingrese la clave de la Funcion: " << endl;
                cin >> claveFuncion;
                cout << "Ingrese el número de película: " << endl;
                cin >> numeroPelicula;

                cout << "Ingrese la hora de la funcion (Hora luego Minutos): " << endl;
                cin >> hora;
                cin >> minutos;
                if(hora > 0 && hora < 24 && minutos >= 0 && minutos <= 59 )
                {
                    cout << "Ingrese el número de sala: " << endl;
                    cin >> numeroSala;
                    Hora horaFuncion(hora, minutos);
                    Funcion funcion(horaFuncion, numeroPelicula,numeroSala,claveFuncion);
                    matrizFuncion[x] = funcion;
                }
                else
                {
                    cout << "Rango de hora incorrecto" << endl;
                }
            }
            check = 0;
        }
        else
        {
            cout << "Ese número de funciones no es valido." << endl;
            check = 0;
        }
    }
}

void consultarFunciones()
{
    for(int x = 0; x < 20 ; x++)
    {

        if(matrizFuncion[x].getcveFuncion().empty() )
        {
            continue;
        }
        Funcion func = matrizFuncion[x];
        Pelicula peli =  buscarPelicula(func.getNumPeli());
        if(peli.getnumPeli() == 0  )
        {
            continue;
        }

        cout <<"Codigo de Funcion : " << func.getcveFuncion() <<endl;
        cout << "Nombre de la pelicula: " <<peli.gettitulo()<<endl;
        cout<< " Numero de sala: " <<to_string( func.getSala()) <<endl;
        cout << "Hora " << to_string(func.getHora().getH()) <<":" << to_string(func.getHora().getMin()) << endl;
    }
}
void Consultafuncionesporhora()
{
    bool condicion = true;
    int hora, minutos, iHora, iminutos;
    do
    {

        cout << "Ingrese la hora de la funcion (Hora luego Minutos): " << endl;
        cin >> hora;
        cin >> minutos;
        if(hora > 24 || hora < 0 || minutos >= 59 || minutos <=0 )
        {
            condicion = false;
            cout << "Rango de hora incorrecto" << endl;
        }
    }
    while (condicion == false);
    condicion = false;
    for(int x = 0; x < 20 ; x++)
    {
        Hora horafuncion = matrizFuncion[x].getHora();
        iHora = horafuncion.getH();
        iminutos = horafuncion.getMin();

        if(iHora == hora && iminutos == minutos)
        {
            condicion = true;
            cout << "Nombre de la pelicula: "<< matrizPelicula[x].gettitulo() <<" Sala: "<<  to_string( matrizFuncion[x].getSala())<< endl;
        }
    }
    if (condicion == false)
    {
        cout << " No existe este horario" << endl;
    }
}
void consultaPorClavedeFuncion()
{
    bool condicion = false;

    string  ClaveF;
    do
    {
        cout << "Ingresa el codigo de la funcion"<< endl;
        cin >> ClaveF;
        for(int i = 0 ; i < 20 ; i++)
        {
            if(matrizFuncion[i].getcveFuncion() == ClaveF)
            {
                condicion = true;
                cout << "Info Funcion: " << to_string( matrizFuncion[i].getSala() )<< " Hora:" <<to_string(matrizFuncion[i].getHora().getH()) <<":" << to_string(matrizFuncion[i].getHora().getMin()) << " "<< endl ;
                int idPelicula = matrizFuncion[i].getNumPeli();
                for (int j = 0 ; j < 20 ; j++)
                {
                    if(matrizPelicula[j].getnumPeli() == idPelicula )
                    {
                        cout <<"Nombre de la Pelicula:  " << matrizPelicula[j].gettitulo() << " Duracion: "<< matrizPelicula[j].getduracion() <<  endl;
                        for(int k = 0; k < matrizPelicula[j].getcantActores() ; k++)
                        {
                            cout <<"Nombre del Actor: " << matrizPelicula[j].getActor(k).getNombre() << endl;
                        }
                    }
                }
            }
        }
    }
    while (condicion == false );
}

void consultaPorID()
{
    bool condicion = false;

    int iD;
    do
    {
        cout << "Ingresa el ID del actor "<< endl;
        cin >> iD;
        for(int i = 0 ; i < 20 ; i++)
        {
            if (iD == matrizActores[i].getId() )
            {
                condicion = true;
                for(int x = 0 ; x < 20 ; x++)
                {
                    for(int k = 0; k < matrizPelicula[x].getcantActores() ; k++)
                    {
                        if(matrizPelicula[x].getActor(k).getId() == iD)
                        {
                            cout <<"Nombre de la pelicula: " << matrizPelicula[x].gettitulo() << " Año: " << matrizPelicula[x].getanio() << endl;
                        }
                    }
                }
            }
        }
    }
    while (condicion == false );

}

int main()
{

    cargarArchivos();
    agregarFunciones();
    int opc;
    bool finish = true;
    while(finish)
    {

        dibujarMenu();

        cin >> opc;

        switch(opc)
        {
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
            Consultafuncionesporhora();
            break;
        case 5:
            consultaPorClavedeFuncion();
            break;
        case 6:
            consultaPorID();
            break;
        case 0:
            exit(0);
            break;
        default:
            cout << "No existe" <<endl;
            break;
        }
    }
}

//asi nomas  pariente
