#pragma once

#include <memory>

namespace Estructura
{
    /**
     * @brief This is 1 note
     */
    struct Recordatorio
    {
        std::string identificador;
        std::string nota;
        std::string fecha;
        std::string hora;

    };


    struct Nodo;

    /**
     * @brief A simple list node 
     */
    struct Nodo
    {
        std::shared_ptr<Nodo> nodo_next = nullptr;
        std::shared_ptr<Nodo> nodo_prev = nullptr;
        std::shared_ptr<Recordatorio> nota = nullptr;
    };

    class Lista
    {
    public:
        /**
         * @brief Add new node 
         *
         * @param recordatorio node to add
         */
        void InsertarNodo(std::shared_ptr<Recordatorio> &recordatorio);

        /**
         * @brief Search note
         *
         * @param ID ID to search
         *
         * @return Returns the note in the node
         */
        int BuscarDato(std::string ID);

        /**
         * @brief Method to get the lenght
         *
         *
         * @return Returns length
         */
        int CalcularTamanho();

        /**
         * @brief Deletes a node
         *
         * @param ID to delete
         *
         * @return Returns true if node was deleted
         */
        bool EliminarNodo(std::string ID);

        /** @brief shows data
         *
         * @param dir select the direction in which the list is shown
         */

        void MostrarDatos(int dir);
        /**
         * Constructor
        */
        Lista() {
            this->inicio_ = nullptr;
            this->final_ = nullptr;
        }

        /**
         * Destructor
        */
        ~Lista() {}

    private:
        std::shared_ptr<Nodo> inicio_;
        std::shared_ptr<Nodo> final_;
        unsigned int tamanho_;
    };
}