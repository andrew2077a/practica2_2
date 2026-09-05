#include <iostream>
#include "librerias.h"
#include <cstdlib> // Contiene rand() y srand()
#include <ctime>   // Contiene time()
using namespace std;

void problem_2(){
    char arch[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    char arch200[200],init;
    int aleatorio,cont=0;
    srand(time(0));
    cout<<"Se le mostrara un arreglo de letras aleatorio y se le dira cuantas letras de cada tipo hay: "<<endl;
    for (int i=0;i<200;i++){
        aleatorio = rand() % 26;
        init=arch[aleatorio];
        arch200[i]=init;
        cout<<init;
    }
    cout<<endl;
    char *punt=arch200;
    for (int i=0;i<26;i++){
        for (int u=0;u<200;u++){
            if (arch[i]==*punt){
                cont++;
            }
            punt++;
        }
        cout<<arch[i]<<":"<<cont<<endl;
        cont=0;
        punt = arch200;
    }
}

void problem_4(){
    char e[50];
    char *pr=e;
    int numero=0;
    cout<<"Ingrese una cadena de caracteres numericos para pasarlos a entero"<<endl;
    cin >>e;
    while(*pr!='\0'){
        numero = (numero * 10) + (*pr - '0');
        pr++;
    }
    cout<<"El numero a entero es: "<< numero<<" comprobacion: "<<numero+1<<endl;

}

void problem_6(){
    char e[50],u[50];
    char *pr=e;
    int i=0;
    cout<<"Ingrese una cadena de caracteres para cambiar las letras a mayusculas"<<endl;
    cin.getline(e, 50);
    while(*pr!='\0'){
        if(*pr>=97&& *pr<=122){
            u[i]=*pr-32;
        }
        else{
            u[i]=*pr;
        }
        pr++;
        i ++;
    }
    u[i] = '\0';
    cout<<"original: "<<e<<endl;
    cout<<"En mayusculas:"<<u<<endl;

}
void separar(const char ori[],char tex[],char num[]){
    const char *pos=ori;
    char *pr=tex;
    char *ptr=num;
    while (*pos!='\0'){
        if (*pos>=48&&*pos<=57){
            *ptr=*pos;
            ptr++;
        }
        else{
            *pr=*pos;
            pr++;

        }
        pos++;
    }
    *pr = '\0';
    *ptr = '\0';

}
void problem_8(){
    char num[50],tex[50],ori[50];
    cout<<"Ingrese una cadena de caracteres para separar los numeros del resto de los caracteres: "<<endl;
    cin.getline(ori, 50);
    separar(ori,tex,num);
    cout<<"Original: "<<ori<< " Texto: "<<tex<<" Numero: "<<num<<endl;


}
