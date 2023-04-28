#include <iostream>
#include <memory>

#include "lista.hpp"




int main() {
    auto lista = std::make_shared<Estructura::Lista>();
    std::cout<<"Bienvenido a ToDo App!"<<std::endl;
    std::string opcion = "0";
    do{
        std::cout<<std::endl;
        std::cout<<"Introduzca el numero de la opcion deseada: "<<std::endl;
        std::cout<<"(1) Crear nuevo recordatorio "<<std::endl;
        std::cout<<"(2) Mostrar los recordatorios existentes "<<std::endl;
        std::cout<<"(3) Buscar un recordatorio por el identificador "<<std::endl;
        std::cout<<"(4) Eliminar un recordatorio por el identificador "<<std::endl;
        std::cout<<"(5) Salir de la aplicacion "<<std::endl;
        std::cin>>opcion;

        if (opcion == "1"){
            std::cout << std::endl;
            auto nodo = std::make_shared<Estructura::Recordatorio>();
            std::string identifier;
            std::string note;
            std::string date;
            std::string hour;
            std::cin.ignore();
            std::cout<<"Por favor ingrese un identificador para la nota: "<<std::endl;
            std::getline(std::cin, identifier);
            nodo->identificador=identifier;
            std::cout<<"Por favor ingrese la nota que desea agregar:  "<<std::endl;
            std::getline(std::cin, note);
            nodo->nota= note;
            std::cout<<"Por favor ingrese la fecha: "<<std::endl;
            std::getline(std::cin, date);
            nodo->fecha = date;
            std::cout<<"Por favor ingrese la hora "<<std::endl;
            std::getline(std::cin, hour);
            nodo->hora = hour;
            lista->InsertarNodo(nodo);
        }
        else if (opcion == "2"){
            std::cout << std::endl;
            std::cout<<"La lista contiene los siguientes recordatorios:"<<std::endl;
            lista->MostrarDatos(0);
        }
        else if (opcion == "3"){
            std::cout << std::endl;
            std::string ID;
            std::cout<<"Por favor indique el identificador de la nota que desea buscar:"<<std::endl;
            std::cin>>ID;
            lista->BuscarDato(ID);

        }
        else if (opcion == "4"){
            std::cout << std::endl;
            std::string ID;
            std::cout<<"Por favor indique el identificador de la nota que desea eliminar:"<<std::endl;
            std::cin>>ID;
            lista->EliminarNodo(ID);

        }
        else if (opcion == "5"){
            std::cout << std::endl;
            std::cout<<"Hasta luego!!!!"<<std::endl;

        }
        else{
            std::cout << std::endl;
            std::cout<<"La opcion seleccionada es invalida"<<std::endl<<std::endl<<std::endl;
            

        }

    }while(opcion != "5");
    return 0;
}