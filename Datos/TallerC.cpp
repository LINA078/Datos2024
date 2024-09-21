#include <iostream>
using namespace std;
struct estudiante{
    string nombre;
    int codigo;
    int nota;
    estudiante *sig;
};
estudiante *cab = NULL, *aux, *aux2;
void registro(){
     aux = new estudiante;// Asignacion de memoria
     cout<<"PRIMER NOMBRE:";
     cin >> aux->nombre;
     cout << "CODIGO:";
     cin >> aux->codigo;
     cout << "NOTA:";
     cin >> aux->nota;

     aux->sig=NULL;

     if(!cab) {
        cab =aux;
            }else {
        aux2=cab;
                while (aux2->sig !=NULL){ //la condicion
        aux2 =aux2->sig;
        }
            aux2->sig=aux;
        }
             }
     void registrmultiple(){
        int cant;
        cout <<"¿ CUANTO ESTUDIANTES DESEA INGRESAR?:";
        cin >> cant;
         for (int i = 0; i < cant; i++){
         cout <<"REGISTRAR ESTUDIANTE " << i + 1 << endl;

            registro();
         }
    
     }
     
         void mostrar(){   
        aux =cab;
        while (aux !=NULL){
            cout << "NOMBRE: " << aux->nombre << ", CODIGO: " << aux->codigo << " , NOTA: " << aux->nota <<endl;
            aux = aux->sig;
            if(cab == NULL){
                cout << "NO HAY ESTUDIANTES REGISTRADOS"<<endl;
                return;
            }
        }
        }
     void OrdenarCodigo(){   
        int temporalN, temporalC;
        string temporalNombre;
        aux2 = cab;
        while (aux2->sig !=NULL){
            aux=cab;
            while(aux->sig != NULL){
            if (aux->codigo > aux->sig->codigo){
                //cambia por codigo
                temporalC = aux->codigo;
                aux->codigo = aux->sig->codigo;
                aux->sig->codigo = temporalC;
                //cambia Nombre
                temporalNombre = aux->nombre;
                aux->nombre = aux->sig->nombre;
                aux->sig->nombre = temporalNombre;
                //cambia nota
                temporalN = aux->nota;
                aux->nota = aux->sig->nota;
                aux->sig->nota = temporalN;
                        }
        aux = aux ->sig;
        }
        aux2 = aux2->sig;
               
        }
                    
     }    
     void ordenarNota(){   
        int temporalN, temporalC;
        string temporalNombre;
        aux2 = cab;
        while (aux2->sig !=NULL){
            aux = cab;
            while (aux->sig != NULL){
                if ( aux->nota < aux->sig->nota){
                   //cambia nota
                    temporalN = aux->nota;
                    aux->nota = aux->sig->nota;
                    aux->sig->nota = temporalN;
// cambiar nombre
                    temporalNombre = aux->nombre;
                    aux->nombre = aux->sig->nombre;
                    aux->sig->nombre = temporalNombre;
//cambia codigo
             temporalC = aux->codigo;
             aux->codigo = aux->sig->codigo;
             aux->sig->codigo = temporalC;

                }
                aux = aux->sig;

            }
            aux2 = aux2->sig;
        }
        }

        void promedio(){
            int suma = 0, cant= 0;
            aux = cab;
            while (aux != NULL){
                suma += aux->nota;
                cant++;
                aux = aux->sig;
            }
            if (cant > 0){
                cout << "PROMEDIO DE NOTAS:" <<(float)suma/cant << endl;
            }else{
                if(cant ==0){ //condicion

                }
                cout << "NO HAY ESTUDIANTES EN EL REGISTRO. " << endl;
                return;
            }
        }
        void NotaMayor(){
            if(cab== NULL){
                cout << "NO HAY ESTUDIANTE EN EL REGISTRO. " << endl;
                return;
                }
                aux = cab;
                estudiante *NotaMayor = aux;
                while (aux != NULL){
                    if (aux->nota > NotaMayor->nota){
                NotaMayor = aux;
                    }
                
                aux = aux->sig;
                    
                }
                cout << "NOTA MAYOR " <<NotaMayor->nota<< " ESTUDIANTE: " <<NotaMayor->nombre << "CODIGO: " << NotaMayor->codigo << ")"<<endl;

        }                
            
            
            
            void NotaMenor(){          
           
                if (cab == NULL){
                    cout << "NO HAY REGISTRO DE ESTUDIANTES." << endl;
                    return;
                }
                aux= cab;
                estudiante *NotaMenor = aux;
                while (aux != NULL){
                    if (aux->nota < NotaMenor->nota){
                        NotaMenor = aux;
                    }
                    aux = aux->sig;
                }
                cout << " NOTA MENOR: " << NotaMenor->nota << " ESTUDIANTE:"<< NotaMenor->nombre << ", CODIGO: "<< NotaMenor->codigo <<endl;
                                    
                  
                    } 
                    int main(){
                        int opcion;
                        do{
                        
                            cout << "MENU" << endl;
                            cout << "1. INGRESAR ESTUDIANTE" << endl;
                            cout << "2. INSERTAR VARIOS ESTUDIANTES" << endl;
                            cout << "3. ORDENAR Y MOSTRAR ESTUDIANTES" <<endl;
                            cout << "4. MOSTRAR LA NOTA (MAYOR, MENOR)" << endl;
                            cout << "5. SALIR" <<endl;
                            cout << " ESCOGE UNA OPCION: ";
                            cin >> opcion;

                            switch (opcion){
                                case 1:
                                registro();
                                break;
                                case 2:
                                registrmultiple();
                                break;
                          
                            case 3: {
                                int Orden;
                                cout << "ELIGE COMO ORDENAR:" << endl;
                                cout << " 1. POR CODIGO (MENOR A MAYOR)"<<endl;
                                cout << "2. POR NOTA (MAYOR A MENOR)"<< endl;
                                cin >> Orden;
                                
                                if (Orden == 1){
                                    OrdenarCodigo();
                                    cout << " LOS ESTUDIANTES ORDENADOS POR CODIGO:"<<endl;

                                }else if (Orden == 2){
                                    ordenarNota();
                                    cout << "LOS ESTUDIANTES ORDENADOS POR NOTA:" <<endl;
                                } else {
                                    cout << "OPCION INVALIDA"<<endl;
                                }
                                mostrar();
                                break;

                            }
                            case 4:
                            NotaMenor();
                            NotaMayor();
                            promedio();
                                break;
                                case 5:
                                cout << "FIN DEL PROGRAMA" << endl;
                                break;
                            
                            default:
                                cout << "OPCION INCORRECTA" << endl;
                            }

                        } while  (opcion != 5);
                        return 0;
                    }
                    
            
