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
    cout <<"CUAL ES EL DESTINO DEL PASAJERO"<<endl;
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
       int mostrar();
       {
        for(aux=cab;
        aux!=NULL;
        aux=aux->sig);
        {
            cout <<"nodo" <<aux->documento<<endl;
            cout<<"nodo"<<aux->nombre<<endl;
            cout<<"nodo"<<aux->destino<<endl;
        }


        }
               }
 



