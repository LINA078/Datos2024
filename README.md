#include <iostream>

using namespace std;

struct nodo {
    int value;
    nodo*sig;
};
struct nodo *top, *aux;

int registrar(){
    aux = ((struct nodo *) malloc (sizeof(struct nodo)));
    cout << "REGSTRE EL VALOR DEL NODO:";
    cin>>aux->value;
    if (!top){
        top = aux;
        top->sig = NULL;
    }else {
        aux->sig = top;
        top = aux;

    }
    aux = NULL;
    free(aux)
}
    int mostrar(){
      cout<<top->value<<endl;

       if (top2==NULL){
        top2 = top;
        top = top ->sig;
        top2->sig=NULL;

        
       }else{
        aux = top;
        top=top->sig;
        aux->sig=top2;
        top2=aux;
        aux=NULL;
       }
       }
       
       while (top2!=NULL){
        if(top==NULL){
            top = top2;
            top2 = top2->sig;
            top->sig=NULL;

              }
              else{ 
                aux= top2;
                top2=top2->sig;
                aux->sig=top;
                top=aux;
                aux=NULL;
                }

      
int main (){

int opc;
do
{
   cout<<"PILAS" <<endl <<"1. REGISTRAR"<<endl<<"2. MOSTRAR"<<endl<< "5. SALIR" <<endl;
   cin>>opc;
  switch(opc){     
   case 1: registrar()
    break;
    case 2: mostrar()
    break;
    
   }
} while (opc!=5);

  


  };
    
