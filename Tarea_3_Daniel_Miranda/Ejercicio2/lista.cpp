#include <iostream>

#include "lista.hpp"

using namespace Estructura;


void Lista::InsertarNodo(std::shared_ptr<Recordatorio> &recordatorio) {
    std::cout << std::endl;
    if (this->inicio_ == nullptr) {
        auto nuevo_nodo= std::make_shared<Nodo>();
        nuevo_nodo->nota = recordatorio;
        this->inicio_=nuevo_nodo;
        this->tamanho_=1;
        std::cout << "Se añadio el recordatorio " << std::endl;
        return;
    }

    std::shared_ptr<Nodo> nodo_temp = this->inicio_;
    std::shared_ptr<Nodo> nodo_temp2 = this->inicio_;

    while (nodo_temp->nodo_next != nullptr) {
        nodo_temp = nodo_temp->nodo_next;
        nodo_temp->nodo_prev = nodo_temp2;
        nodo_temp2 = nodo_temp;

        std::cout << "Buscando elemento" << std::endl;
    }

    nodo_temp->nodo_next = std::make_shared<Nodo>();
    nodo_temp->nodo_next->nota = recordatorio;
    this->tamanho_= this->tamanho_+1;
    this->final_= nodo_temp->nodo_next;
    std::cout << "Se añadio el recordatorio " << std::endl;
}


int Lista::BuscarDato(std::string ID){
    std::cout << std::endl;
    if (this->inicio_ == nullptr){
        std::cout << "La lista esta vacia" << std::endl;
        return 0;
    }

    
    std::shared_ptr<Nodo> nodo_temp = this->inicio_;

    while (nodo_temp != nullptr){
        if (nodo_temp->nota->identificador == ID){
            std::cout << "El recordatorio con el identificador " << nodo_temp->nota->identificador << " es: "<< nodo_temp->nota->nota << std::endl;
            return 0;    
        }
        nodo_temp = nodo_temp->nodo_next;
        
    }
    return 0;

}

int Lista::CalcularTamanho(){
    std::cout << std::endl;
    if (this->inicio_ == nullptr){
        std::cout << "La lista esta vacia" << std::endl;
        return 0;
    }
    std::cout << "Cantidad de datos en la lista por variable interna " << this->tamanho_ << std::endl;
    return 0;

}

bool Lista::EliminarNodo(std::string ID){
    std::cout << std::endl;
    if (this->inicio_ == nullptr){
        std::cout << "[Error] La lista esta vacia" << std::endl;
        return false;
    }
    std::shared_ptr<Nodo> anterior = this->inicio_;
    std::shared_ptr<Nodo> actual = nullptr;
    
    if (anterior->nodo_next != nullptr){
        actual = anterior->nodo_next;
        
    }
    std::shared_ptr<Nodo> siguiente = nullptr;
    if (anterior->nota->identificador == ID){
        if (actual != nullptr){
            actual->nodo_prev =nullptr;
        }
        this->inicio_ = actual;
        std::cout << "El recordatorio fue borrado " <<  std::endl;
        this->tamanho_ = this->tamanho_ -1;
        return true;
    }
    while (actual != nullptr) {
        if (actual->nota->identificador == ID) {
            if (actual->nodo_next != nullptr){
                siguiente = actual->nodo_next;
                siguiente->nodo_prev = anterior;
            }
            
            anterior->nodo_next = siguiente;
            actual.reset();
            this->tamanho_ = this->tamanho_ -1;
            std::cout << "El recordatorio fue borrado " <<  std::endl;
            return true;
        }
        anterior = actual;
        actual = actual->nodo_next;
    }
    std::cout << "no se encontro el ID " <<  std::endl;
    return false;

}

void Lista::MostrarDatos(int dir = 0) {
    std::cout << std::endl;
    if (dir == 0){
        std::shared_ptr<Nodo> actual = this->inicio_;
        int indice = 1;
        while (actual != nullptr) {
            std::cout << "Recordatorio con el identificador "<< actual->nota->identificador <<": " << actual->nota->nota << std::endl;
            actual = actual->nodo_next;
            indice++;
        }
  }
    else if (dir == 1){
        std::shared_ptr<Nodo> actual = this->final_;
        int indice = this->tamanho_;
        while (actual != nullptr) {
            std::cout << "Dato en posición " << indice << ": " << actual->nota->nota << std::endl;
            actual = actual->nodo_prev;
            indice--;
        }
  }
}