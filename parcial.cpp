#include <iostream>
#include <cstdlib>
using namespace std;

struct nodo{

int documento;
string nombre;
int destino;
 nodo*sig;

};
struct nodo *cab = NULL, *aux = NULL, *fin = NULL;


int registrar(){
    aux = (struct nodo*)malloc(sizeof(struct nodo));

    cout <<"CUAL ES EL NUMERO DE DOCUMENTO DEL PASAJERO"<<endl;
    cin >>aux->documento;
    cout <<"INGRESE EL NOMBRE DEL PASAJERO"<<endl;
    cin >>aux->nombre;
    cout <<"CUAL ES EL DESTINO DEL PASAJERO (1: LA BOCANA, 2:PIANGUITA, 3:LADRILLEROS)"<<endl;
    cin >> aux->destino;
    aux->sig = NULL;

    if(!cab){
        cab = fin = aux;
        

        }else{
            fin->sig=aux;
            fin=aux;
        }
        aux=NULL;     
        return 0;
}
       
       int mostrar(){
        aux = cab;
       
        while(aux !=NULL) {

       
            cout <<"DOCUMENTO" <<aux->documento<<endl;
            cout<<"NOMBRE"<<aux->nombre<<endl;
            cout <<"DESTINO";
            switch (aux->destino){
                case 1: cout<<"LA BOCANA";
                break;
                       
             case 2:cout<<"PIANGUITA" << endl;
                 break;
                 case 3: cout<< "LADRILLEROS" << endl;
                 break;
            
            default: cout<<"NO EXISTE" << endl ;
                
            }
            aux = aux->sig;
        }

return 0;
       
       }
int ordenarPasajeros(){
if (cab == NULL){

    cout << "NO HAY PASAJEROS REGISTRADOS" << endl;
    return -1;
}
bool intercambiar;
nodo *actualPasajero1;
nodo *actualPasajero = NULL;
int interdoc, interdest;
string internomb;

do{
    intercambiar = false;
    actualPasajero1 = cab;

    while (actualPasajero1->sig != actualPasajero){

        if (actualPasajero1->destino >actualPasajero1->sig->destino ||
        (actualPasajero1->destino == actualPasajero1->sig->destino && actualPasajero1->documento > actualPasajero1->sig->documento)) {
// INTERCAMBIOS
// INTERCAMBIO DE DOC
       interdoc = actualPasajero1->documento;
         actualPasajero1->documento = actualPasajero1->sig->documento;
         actualPasajero1->sig->documento = interdoc;

        internomb=actualPasajero1->nombre;
        actualPasajero1->nombre = actualPasajero1->sig->nombre; 
        actualPasajero1->sig->nombre = internomb;


        interdest = actualPasajero1->destino; 
        actualPasajero1->destino= actualPasajero1->sig->destino;
        actualPasajero1->sig->destino = interdest;

        intercambiar = true;
                
        }
        actualPasajero1 = actualPasajero1->sig;
    }
    actualPasajero = actualPasajero1;
}while (intercambiar);
return 0;
}

  
         int main() {
                        int opcion;
                        do{
                            cout <<"MENU"<<endl;
                              cout << "1. REGISTRAR PASAJEROS" <<endl; 
                               cout << "2. MOSTRAR PASAJEROS" <<endl;                        
                                cout << "3. ORDENAR PASAJEROS" <<endl;  
                                 cout << "4. SALIR" <<endl;                                                                     
                               cout << " ESCOGE UNA OPCION: ";
                            cin >> opcion;

                            switch (opcion){
                                case 1:
                                registrar();
                                break;
                                case 2:
                                mostrar();
                                break;
                                case 3:
                               ordenarPasajeros();
                                cout << "PASAJEROS ORDENADOS" <<endl;
                                break;
                                case 4:
                                cout<<"SALIENDO DEL PROGRAMA";
                                break;
                                default:
                                cout << "OPCION INVALIDA" << endl;

                            }
                          
                        }while (opcion !=4);
                        
                            return 0;
                        
         }                        

