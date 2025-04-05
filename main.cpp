/**
 * @file main.cpp
 * @brief Programa para gestionar cuentas bancarias.
 * 
 * Este programa permite crear cuentas bancarias, realizar depósitos, retiros,
 * bloquear cuentas y generar un archivo con los datos finales de las cuentas.
 * 
 * @author Lenin Enrique García Caraballo y David Orlando Riaño Morales
 * @date 2025-04-04
 */

#include <iostream>
#include <vector>
#include <fstream>
#include "CuentaBancaria.h"
using namespace std;

/**
 * @brief Función principal del programa.
 * 
 * Solicita al usuario ingresar cuentas bancarias, realiza operaciones de prueba
 * como depósitos, retiros y bloqueos, y genera un archivo con los datos finales.
 * 
 * @return int Código de salida del programa.
 */

int main(){
    // Hay que crear un vector para almacenar las cuentas
    vector<CuentaBancaria> cuentas;
    string prueba;
    int cant_cuentas;

    cout << "Ingrese el número de cuentas a almacenar(mínimo 3 cuentas para probar los casos): ";
    cin >> cant_cuentas;
    cout << "¿Quiere hacer casos de Prueba? (y/n): ";
    cin >> prueba;
    cout << endl;

    string num_cuenta;
    float saldo_inicial;

    // Se le pide al usuario recurrentemente los datos de cada cuenta hasta alcanzar la cantidad deseada

    for(int i=0; i < cant_cuentas; i++){
        cout << "Ingrese número de cuenta " << i + 1 << ": ";
        cin >> num_cuenta;
        cout << "Ingrese Saldo Inicial de cuenta " << i + 1 << ": ";
        cin >> saldo_inicial;
        cout << endl;
        cuentas.push_back(CuentaBancaria(num_cuenta, saldo_inicial));
    }

    
    for(int j= 0; j < cant_cuentas; j++){
        cout << "Cuenta " << j+1 << ": " << "Número de Cuenta " << cuentas[j].GetNumeroCuenta() << ", Saldo: " << cuentas[j].GetSaldo() << endl;
    }


    if (cuentas.size() >= 3 && (prueba == "y" || prueba == "Y")){ // Se verifica si el usuario ingreso minimo 3 cuentas
        // Casos de prueba:
        cout << endl;
        cout << "CASOS DE PRUEBA" << endl;

        // Caso 1: Depósito en la primera cuenta
        cout << "En la cuenta 1 se depositan 5000" << endl;
        cuentas[0].depositar(5000);
        cuentas[0].obtenerSaldo();

        // Caso 2: Retiro exitoso de la segunda cuenta
        cout << "\nCaso 2: Retiro de 2000 en la segunda cuenta.\n";
        cuentas[1].retirar(2000);
        cuentas[1].obtenerSaldo();

        // Caso 3: Intento de retiro con fondos insuficientes
        cout << "\nCaso 3: Intento de retirar 10000 en la tercera cuenta.\n";
        cuentas[2].retirar(10000);
        cuentas[2].obtenerSaldo();

        // Caso 4: Bloqueo de la primera cuenta
        cout << "\nCaso 4: Bloqueo de la primera cuenta.\n";
        cuentas[0].bloquearRetiros();
        cuentas[0].obtenerSaldo();

        // Caso 5: Intento de retiro en una cuenta bloqueada
        cout << "\nCaso 5: Intento de retirar 1000 en la primera cuenta bloqueada.\n";
        cuentas[0].retirar(1000);
        cuentas[0].obtenerSaldo();
    
        // Caso 6: Depósito en una cuenta bloqueada (debería funcionar)
        cout << "\nCaso 6: Depósito de 5000 en la primera cuenta bloqueada.\n";
        cuentas[0].depositar(5000);
        cuentas[0].obtenerSaldo();

    }
    else {
        cout << "Programa Terminado" << endl;
    }
    // Creación del archivo.txt, EL CUAL SE GENERA EN LA CARPETA BUILD

    ofstream file("DatosCuenta.txt");
        if(!file){
            cerr << "Error al abrir el archivo para la escritura";
            return 1;
        }

        for(int k = 0; k < cant_cuentas; k++) { // Se escribe cada cuenta con su respectivo saldo por linea
            file << "Cuenta " << k+1 << "--> Numero de Cuenta: " << cuentas[k].GetNumeroCuenta() << ", Saldo Final: " << cuentas[k].GetSaldo() << endl;
        }  
        
        file.close();

    return 0;
}

