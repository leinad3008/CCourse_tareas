#include <iostream>

#include "Camara.hpp"

using namespace Object;

void Camara::TomarFoto(){
    this->disparos_=disparos_+1;
}
unsigned int Camara::GetLimit(){
    return this->limite_disparos_;
}

unsigned int Camara::GetDisparos(){
    return this->disparos_;
}

void VerificarDiparos(std::shared_ptr<Camara> &camara){
    unsigned int num_disp = camara->GetDisparos();
    unsigned int limite_disp = camara->GetLimit();
    std::cout<<"El número de disparos actual es: "<<num_disp<<std::endl;
    std::cout<<"El limite de disparos es: "<<limite_disp<<std::endl;
    if (num_disp >= limite_disp){
        camara.reset();
        std::cout<<"La camara llego al limite de disparos"<<std::endl;
    }
    else{
        std::cout<<"La camara sigue sin llegar a su limite de disparos"<<std::endl;
    }
}
