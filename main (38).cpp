#include <iostream>
#include <ctime>
using namespace std;

int main(){
    srand(time(0));
    int jugador,computadora,opcion;
    do{
        cout<<"=== PIEDRA PAPEL O TIJERA ==="<<endl;
        cout<<"1. Piedra"<<endl;
        cout<<"2. Papel"<<endl;
        cout<<"3. Tijera"<<endl;
        cout<<"ingrese su opcion: ";
        cin>>jugador;
        computadora=(rand()%3)+1;
        if(computadora==1) cout<<"la computadora eligio: Piedra"<<endl;
        if(computadora==2) cout<<"la computadora eligio: Papel"<<endl;
        if(computadora==3) cout<<"la computadora eligio: Tijera"<<endl;
        if(jugador==computadora){
            cout<<"es un empate!"<<endl;
        }else if(jugador==1 && computadora==3){
            cout<<"ganaste!"<<endl;
        }else if(jugador==2 && computadora==1){
            cout<<"ganaste!"<<endl;
        }else if(jugador==3 && computadora==2){
            cout<<"ganaste!"<<endl;
        }else{
            cout<<"perdiste!"<<endl;
        }
        cout<<"desea jugar de nuevo? (1=si / 0=no): ";
        cin>>opcion;
    }while(opcion==1);
    cout<<"gracias por jugar!"<<endl;
    return 0;
}