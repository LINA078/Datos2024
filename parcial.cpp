#include <iostream>
using namespace std;
struct nodo{

int documento;
string nombre;
string destino;
 nodo*sig;

};
struct nodo *cab = NULL, *aux=NULL, *fin=NULL;


int registrar(){
    aux=((struct nodo*)malloc(sizeof(struct nodo)));

    cout <<"CUAL ES EL NUMERO DE DOCUMENTO DEL PASAJERO"<<endl;
    cin >>aux->documento;
    cout <<"INGRESE EL NOMBRE DEL PASAJERO"<<endl;
    cin >>aux->nombre;
    cout <<"CUAL ES EL DESTINO DEL PASAJERO (1: LA BOCANA, 2:PIANGUITA, 3:LADRILLEROS)"<<endl;
    cin >>aux->destino;
    aux->sig=NULL;

    if(!cab){
        cab = fin = aux;
        

        }else{
            fin->sig=aux;
            fin=aux;
        }
        aux=NULL;     

       free(aux);
       {

       }
       int mostrar() {
       nodo* sig = cab;
       
        while(aux !=NULL) {

       
            cout <<"DOCUMENTO" <<aux->documento<<endl;
            cout<<"NOMBRE"<<aux->nombre<<endl;
            cout <<"DESTINO";
            switch (aux->destino){
                case1: cout<<"LA BOCANA";
                break;
                       
             case2:cout<<"PIANGUITA";
                 break;
                 case3: cout<< "LADRILLEROS";
                 break;
            
            default: cout<<"NO EXISTE";
                
            }
            aux=aux->sig;
        }


       }
         int main() {
                        int opcion;
                        do{
                            cout <<"MENU. 1 REGISTRAR PASAJEROS, 2. MOSTRAR PASAJEROS, 3. SALIR"<<endl;
                                                      
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
                                cout<<"SALIENDO DEL PROGRAMA";
                                break;
                            }
                          
                        }while (opcion !=3);
                        {
                            return 0;
                        
                        
               }
 
}

}

