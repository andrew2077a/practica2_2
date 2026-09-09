#include <iostream>
#include "librerias.h"
using namespace std;

int main(){
    int x;
    while(true){
        cout<<"Ingrese un numero para elegir un problema, si quiere salir ingrese 19: "<<endl;
        cin>>x;
        cin.ignore();
        switch(x){
        case 2:
            problem_2();
            break;
        case 4:
            problem_4();
            break;
        case 6:
            problem_6();
            break;
        case 8:
            problem_8();
            break;
        case 10:
            problem_10();
            break;
        case 12:
            problem_12();
            break;
        case 14:
            problem_14();
            break;
        case 16:
            problem_16();
            break;
        case 19:
            return 0;
        default:
            cout<<"Ingrese otro numero"<<endl;

        }
    }
}
