#pragma once

#include <memory>

namespace Object
{


    class Camara
    {
    public:
        /**
         * @brief Shoot a picture
         */
        void TomarFoto();

        /**
         * @brief gets number of token pictures
         */
        unsigned int GetDisparos(); 

        /**
         * @brief gets limit of pictures
         */
        unsigned int GetLimit(); 

        /**
         * Constructor
        */
        Camara(unsigned int anho, std::string marca, unsigned int limite = 100) {
            this->disparos_ = 0;
            this->anho_fabricacion_ = anho;
            this->limite_disparos_ = limite;
        }

        /**
         * Destructor
        */
        ~Camara() {}

    private:
        unsigned int disparos_;
        std::string marca_;
        unsigned int anho_fabricacion_;
        unsigned int limite_disparos_;
    };
}