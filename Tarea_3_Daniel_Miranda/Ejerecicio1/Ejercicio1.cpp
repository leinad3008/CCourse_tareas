#include <iostream>
#include <memory>

#include "Camara.cpp"

int main(){

    std::weak_ptr<Object::Camara> weak_camara;
    unsigned int anho= 1999;
    std::string marca = "Sony";
    unsigned int limite = 100;
    unsigned int disparos;
    auto camara = std::make_shared<Object::Camara>(anho, marca, limite);
    weak_camara = camara;
    
    while (true) {
        camara->TomarFoto();
        VerificarDiparos(camara);
        if (weak_camara.use_count() == 0){
            std::cout<< "Saliendo del ciclo"<<std::endl;
            break;
            
        }
    }

    return 0;
}