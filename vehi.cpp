#include <iostream>
#include <string>

using namespace std;

struct nodo {
    int tipoVehiculo;  // 1 para moto, 2 para carro
    string placa;
    int movimientos;
    nodo *sig;
};

struct nodo *cab = NULL, *aux = NULL, *aux2 = NULL;
int dineroobte = 0;

int registrador() {
    aux = (struct nodo *)malloc(sizeof(struct nodo));
    int tipo;
    string placa;

    cout << "REGISTRE EL TIPO DE VEHÍCULO (1 PARA MOTO, 2 PARA CARRO): ";
    cin >> tipo;
    cout << "INGRESE EL NÚMERO DE PLACA: ";
    cin >> placa;

    aux->tipoVehiculo = tipo;
    aux->placa = placa;
    aux->movimientos = 0;

    if (!cab) {
        cab = aux;
        cab->sig = NULL;
    } else {
        aux->sig = cab;
        cab = aux;
    }

    aux = NULL;
    return 0;
}

int sacar() {
    if (!cab) {
        cout << "NO HAY VEHÍCULOS" << endl;
        return 0;
    }

    string placaABuscar;
    cout << "INGRESE EL NÚMERO DE PLACA DEL VEHÍCULO A SACAR: ";
    cin >> placaABuscar;

    aux = cab;
    aux2 = NULL;
    int costoSalida = 0;

    while (aux != NULL) {
        if (aux->placa == placaABuscar) {
            // Calcular el costo de salida
            if (aux->tipoVehiculo == 1) {  // Moto
                costoSalida = 1000 + (aux->movimientos * 100);
            } else if (aux->tipoVehiculo == 2) {  // Carro
                costoSalida = 2000 + (aux->movimientos * 100);
            }

            // Actualizar el dinero generado
            dineroobte += costoSalida;
            cout << "VEHICULO CON PLACA " << aux->placa << " HA SALIDO, COSTO TOTAL: $" << costoSalida << endl;

            // Eliminar el nodo de la pila
            if (aux2 == NULL) {
                cab = aux->sig;
            } else {
                aux2->sig = aux->sig;
            }

            free(aux);
            return 0;
        }
        aux2 = aux;
        aux = aux->sig;
    }

    cout << "NO SE ENCONTRO VEHICULO CON LA PLACA INGRESADA." << endl;
    return 0;
}

int mostrar() {
    if (!cab) {
        cout << "NO HAY VEHÍCULOS REGISTRADOS." << endl;
    } else {
        cout << "VEHÍCULOS REGISTRADOS: " << endl;
        aux = cab;
        while (aux != NULL) {
            string tipoVehiculo = (aux->tipoVehiculo == 1) ? "MOTO" : "CARRO";
            cout << tipoVehiculo << " CON PLACA " << aux->placa << " Y " << aux->movimientos << " MOVIMIENTOS ACUMULADOS." << endl;
            aux = aux->sig;
        }
    }
    return 0;
}

int mostrarDinero() {
    cout << "DINERO GENERADO EN EL MOMENTO: $" << dineroobte << endl;
    return 0;
}

int main() {
    int opc;
    do {
        cout << "MENÚ" << endl;
        cout << "1. REGISTRAR VEHÍCULO" << endl;
        cout << "2. MOSTRAR VEHÍCULOS" << endl;
        cout << "3. SACAR VEHÍCULO" << endl;
        cout << "4. MOSTRAR DINERO GENERADO" << endl;
        cout << "5. SALIR" << endl;
        cout << "INGRESE UNA OPCION: ";
        cin >> opc;

        switch (opc) {
            case 1: registrador(); break;
            case 2: mostrar(); break;
            case 3: sacar(); break;
            case 4: mostrarDinero(); break;
            case 5: cout << "SALIENDO DEL PROGRAMA." << endl; break;
            default: cout << "OPCION INVALIDA." << endl; break;
        }
    } while (opc != 5);

    return 0;
}