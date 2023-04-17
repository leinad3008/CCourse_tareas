#include <iostream>
#include <cstring>

struct Cliente {
    int cedula;
    int telefono;
    char *nombre;
    char *empresa;
};


Cliente *clientes = new Cliente[5];

void DeleteAll(Cliente *client){
    delete (*client).nombre;
    delete (*client).empresa;
    client++;
    delete (*client).nombre;
    delete (*client).empresa;
    client++;
    delete (*client).nombre;
    delete (*client).empresa;
    client++;
    delete (*client).nombre;
    delete (*client).empresa;
    client++;
    delete (*client).nombre;
    delete (*client).empresa;
}

void CreateCliente(int clientnum,  char nombre[], char empresa[], int telefono, int cedula){
    
    int nombre_len = strlen(nombre);
    int empresa_len = strlen(empresa);
    clientes[clientnum].nombre = new char[nombre_len];
    clientes[clientnum].empresa = new char[empresa_len];
    clientes[clientnum].cedula = cedula;
    clientes[clientnum].telefono = telefono;
    strcpy(clientes[clientnum].nombre, nombre);
    strcpy(clientes[clientnum].empresa, empresa);
}

void Display(Cliente *client){
    std::cout << "Cliente 1:" <<std::endl;

    std::cout << "i)     Cliente: " << (*client).nombre <<std::endl;
    std::cout << "ii)    Empresa: " << (*client).empresa <<std::endl;
    std::cout << "iii)   Cédula: " << (*client).cedula <<std::endl;
    std::cout << "iv)    Teléfono: " << (*client).telefono <<std::endl;
    client++;

    std::cout << "Cliente 2:" <<std::endl;


    std::cout << "i)     Cliente: " << (*client).nombre <<std::endl;
    std::cout << "ii)    Empresa: " << (*client).empresa <<std::endl;
    std::cout << "iii)   Cédula: " << (*client).cedula <<std::endl;
    std::cout << "iv)    Teléfono: " << (*client).telefono <<std::endl;
    client++;

    std::cout << "Cliente 3:" <<std::endl;

    std::cout << "i)     Cliente: " << (*client).nombre <<std::endl;
    std::cout << "ii)    Empresa: " << (*client).empresa <<std::endl;
    std::cout << "iii)   Cédula: " << (*client).cedula <<std::endl;
    std::cout << "iv)    Teléfono: " << (*client).telefono <<std::endl;
    client++;

    std::cout << "Cliente 4:" <<std::endl;
    
    std::cout << "i)     Cliente: " << (*client).nombre <<std::endl;
    std::cout << "ii)    Empresa: " << (*client).empresa <<std::endl;
    std::cout << "iii)   Cédula: " << (*client).cedula <<std::endl;
    std::cout << "iv)    Teléfono: " << (*client).telefono <<std::endl;
    client++;

    std::cout << "Cliente 5:" <<std::endl;

    std::cout << "i)     Cliente: " << (*client).nombre <<std::endl;
    std::cout << "ii)    Empresa: " << (*client).empresa <<std::endl;
    std::cout << "iii)   Cédula: " << (*client).cedula <<std::endl;
    std::cout << "iv)    Teléfono: " << (*client).telefono <<std::endl;


}

Cliente * buscar_cliente(Cliente *client, int cedula){
    if ((*client).cedula == cedula){
        return client;
    }
    client++;
    if ((*client).cedula == cedula){
        return client;
    }
    client++;
    if ((*client).cedula == cedula){
        return client;
    }
    client++;
    if ((*client).cedula == cedula){
        return client;
    }
    client++;
    if ((*client).cedula == cedula){
        return client;
    }
    return nullptr;

}

int Asing(int numclient){
    
    char nombre[32];
    char empresa[32];
    int cedula_ingresada;
    char yn;
    int telefono_ingresado = 0;
    
    std::cout << "Ingrese el nombre del cliente numero " << numclient+1 << std::endl;
    std::cin.getline(nombre, 32);

    if (nombre=="\n"){
        std::cout << "[Error] Debe ingresar el dato del cliente " << numclient+1 << " : Nombre"<<std::endl;
        return 0;
    }
    std::cout << "Desea ingresar una empresa para el cliente numero " << numclient+1 << "?[Y/N] " << std::endl;
    std::cin >> yn;
    if ( toupper(yn) == 'Y'){
        std::cout << "Ingrese el nombre de la empresa del cliente numero " << numclient+1 << std::endl;
        std::cin.ignore();
        std::cin.getline(empresa, 32);
    }
    std::cout << "Ingrese la cedula del cliente numero " << numclient+1 << std::endl;
    std::cin >> cedula_ingresada;

    std::cout << "Ingrese el numero de telefono del cliente numero " << numclient+1 << std::endl;
    std::cin >> telefono_ingresado;
    CreateCliente(numclient, nombre, empresa, telefono_ingresado, cedula_ingresada);

    return 0;
}

int main(){
    int cedula;
    Cliente *Daniel;
    Asing(0);
    std::cin.ignore();
    Asing(1);
    std::cin.ignore();
    Asing(2);
    std::cin.ignore();
    Asing(3);
    std::cin.ignore();
    Asing(4);
    Display(clientes);

    std::cout << "Ingrese número de cedula a buscar: "<< std::endl;
    std::cin>> cedula;
    Daniel = buscar_cliente(clientes, cedula);
    std::cout << "Puntero encontrado (si es 0, no se encontró): "<< Daniel << std::endl;
    DeleteAll(clientes);
    delete[] clientes;

}