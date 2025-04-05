#ifndef CUENTA_BANCARIA_H
#define CUENTA_BANCARIA_H

#include <iostream>
#include <string>
using namespace std;

class CuentaBancaria{
    private:
        string numeroCuenta;
        float saldo;
        bool retirosBloqueados;
    
    public:

        /**
         *@brief constructor de la clase CuentaBancaria
         *@param numeroCuenta numero de cuenta bancaria
         *@param saldo saldo inicial 
         */
        CuentaBancaria(string numC, float s): numeroCuenta(numC), saldo(s), retirosBloqueados(false) {}
        /**
         * @brief Getter para el número de cuenta
         */
        string GetNumeroCuenta(){
            return numeroCuenta;
        }
        /**
         * @brief Getter para el saldo
         */
        float GetSaldo(){
            return saldo;
        }
        /**
         * @brief depositar dinero
         * @param cantidad cantidad depositada
         */ 
        void depositar(float cantidad){
            if (cantidad > 0 && retirosBloqueados==false){
                saldo = saldo + cantidad;
                cout << "Nuevo Saldo: " << saldo << endl;
            }
            else if(cantidad < 0) {
                cout << "Valor No Válido" << endl;
            }
            else if (retirosBloqueados == true){
                cout << "La cuenta está Bloqueada" << endl;
            }
        }
        /**
         * @brief Retira dinero de la cuenta si hay saldo suficiente y no está bloqueada
         * @param cantidad cantidad a retirar
         */
        void retirar(float cantidad){
            if(retirosBloqueados){
                cout << "Retiros Bloqueados" << endl;
            }
            else if (cantidad > 0 && cantidad <= saldo){
                saldo = saldo - cantidad;
                cout << "Retiro Exitoso, Saldo Nuevo: " << saldo << endl;
            }
            else {
                cout << "Fondos Insuficientes" << endl;
            }
        }
        /**
         *@brief Bloquea Retiros
         */
        void bloquearRetiros(){
            retirosBloqueados = true;
            cout << "Cuenta Bloqueada" << endl;
        }
        /**
         * @brief obtiene el saldo actual
         * @return saldo disponible
         */

         float obtenerSaldo(){
            return saldo;
         }
        /**
         * @brief Muestra el número de cuenta y el saldo inicial
         */
        void mostrarCuenta(){
            cout << numeroCuenta << ", " << saldo << endl;
        }
};


#endif