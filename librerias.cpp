#include <iostream>
#include "librerias.h"
#include <cstdlib> // Contiene rand() y srand()
#include <ctime>   // Contiene time()
#include <iomanip>
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
void arabigo(const char roman[],int &cont){
    const char *pr=roman;
    int mien=1001;
    while(*pr!='\0'){
        switch (*pr) {
        case 'M':
        case 'm':
            if(mien<1000){
                cont += 1000 - 2*mien;
            }
            else{
                cont+=1000;
            }
            mien=1000;
            break;
        case 'D':
        case 'd':
            if(mien<500){
                cont += 500 - 2*mien;
            }
            else{
                cont+=500;
            }
            mien=500;
            break;
        case 'C':
        case 'c':
            if(mien<100){
                cont += 100 - 2*mien;
            }
            else{
                cont+=100;
            }
            mien=100;
            break;
        case 'L':
        case 'l':
            if(mien<50){
                cont += 50 - 2*mien;
            }
            else{
                cont+=50;
            }
            mien=50;
            break;
        case 'X':
        case 'x':
            if(mien<10){
                cont += 10 - 2*mien;
            }
            else{
                cont+=10;
            }
            mien=10;
            break;
        case 'V':
        case 'v':
            if(mien<5){
                cont += 5 - 2*mien;
            }
            else{
                cont+=5;
            }
            mien=5;
            break;
        case 'I':
        case 'i':
            if(mien<1){
                cont += 1 - 2*mien;
            }
            else{
                cont+=1;
            }
            mien=1;
            break;
        default:
            cout<<*pr<<": Letra no identificaada"<<endl;
            return ;
        }
        pr++;
    }
}
void problem_10(){
    char roman[50];
    int cont=0;
    cout<<"Ingrese un numero del sistema romano para pasarlo a arabigo: "<<endl;
    cin.getline(roman,50);
    arabigo(roman,cont);
    cout<<"El numero ingresado fue: "<<roman<<endl;
    cout<<"Que corressponde a: "<<cont<<endl;
}
// COMPROBACIÓN DEL CUADRADO MÁGICO (NUEVO)
bool cuadrado_magico(int filas, int columnas, int** matriznume) { // Se cambió a int** para recibir la matriz procesada
    if (filas != columnas) return false; // Un cuadrado mágico debe ser una matriz cuadrada

    int suma_magica = 0;

    // Calcular la suma de la primera fila como referencia
    for (int j = 0; j < columnas; j++) {
        suma_magica += matriznume[0][j];
    }

    // Comprobar filas
    for (int i = 1; i < filas; i++) {
        int suma_fila = 0;
        for (int j = 0; j < columnas; j++) {
            suma_fila += matriznume[i][j];
        }
        if (suma_fila != suma_magica){
            return false;
        }
    }

    // Comprobar columnas
    for (int j = 0; j < columnas; j++) {
        int suma_col = 0;
        for (int i = 0; i < filas; i++) {
            suma_col += matriznume[i][j];
        }
        if (suma_col != suma_magica) {
            return false;
        }
    }

    // Comprobar diagonal principal
    int suma_diag1 = 0;
    for (int i = 0; i < filas; i++) {
        suma_diag1 += matriznume[i][i];
    }
    if (suma_diag1 != suma_magica) {
        return false;
    }

    // Comprobar diagonal secundaria
    int suma_diag2 = 0;
    for (int i = 0; i < filas; i++) {
        suma_diag2 += matriznume[i][filas - 1 - i];
    }
    if (suma_diag2 != suma_magica) {
        return false;
    }

    return true;
}

void crear_matriz(int filas, int columnas ,char matriz[], int** matriznume) {
    char *pr = matriz;
    int i = 0, e = 0, numero = 0;
    while (*pr != '\0') {
        if (i >= filas || e >= columnas) break;
        if (*pr != ' ' && *pr != ',') {
            numero = (numero * 10) + (*pr - '0');
        }
        if (*pr == ' ') {
            matriznume[i][e] = numero;
            i++;
            e = 0;
            numero = 0;
        }

        if (*(pr + 1) == '\0') {
            matriznume[i][e] = numero;
        }

        if (*pr == ',') {
            matriznume[i][e] = numero;
            e++;
            numero = 0;
        }
        pr++;
    }
    for (int i = 0; i < filas; i++) {
        cout << endl;
        for (int j = 0; j < columnas; j++) {
            cout << matriznume[i][j] << " ";
        }
    }
}

void problem_12(){
    int filas, columnas;
    char matriz[50];

    cout << "Ingrese cuantas filas" << endl;
    cin >> filas;
    cout << "Ingrese cuantas columnas" << endl;
    cin >> columnas;
    int **matriznume = new int *[filas];
    for (int i = 0; i < filas; i++) {
        matriznume[i] = new int [columnas];
    }
    cout << "para una fila separe los numeros por comas y para las columnas separelas por espacios" << endl;
    cin.ignore();
    cin.getline(matriz, 50);
    crear_matriz(filas,columnas, matriz, matriznume);

    // LLAMADA A LA COMPROBACIÓN Y SALIDA (NUEVO)
    if (cuadrado_magico(filas, columnas, matriznume)) {
        cout << "Es un cuadrado magico" << endl;
    } else {
        cout << "No es un cuadrado magico" << endl;
    }
    // LIBERACIÓN DE MEMORIA DINÁMICA (NUEVO)
    for (int i = 0; i < filas; i++) {
        delete[] matriznume[i];
    }
    delete[] matriznume;
}
void hacer_matri(int matriz[5][5]){
    int cont=1;
    for(int i=0;i<5;i++){
        for (int e = 0; e <5; ++e) {
            matriz[i][e]=cont;
            cont++;
        }
    }
    cout<<"MATRIZ ORIGINAL"<<endl;
    cout<<"-------------------------------------"<<endl;
    for(int i=0;i<5;i++){
        for (int j = 0; j <5; ++j) {
            cout<<"|";
            cout<<setw(3)<<matriz[i][j];
        }
        cout<<"|";
        cout<<endl;
    }


}
// 90°: Cambias la 'i' por 'j' en los ciclos y lees 'i' al revés
void imprimir_90(int matriz[5][5]) {
    cout<<"MATRIZ 90"<<endl;
    cout<<"-------------------------------------"<<endl;
    for (int j = 0; j < 5; j++) {
        for (int i = 5- 1; i >= 0; i--) {
            cout<<"|";
            cout<<setw(3)<<matriz[i][j];
        }
        cout<<"|";
        cout << endl;
    }
}

// 180°: Mantienes i y j en su sitio, pero lees ambos al revés
void imprimir_180(int matriz[5][5]) {
    cout<<"MATRIZ 180"<<endl;
    cout<<"-------------------------------------"<<endl;
    for (int i = 5 - 1; i >= 0; i--) {
        for (int j = 5 - 1; j >= 0; j--) {
            cout<<"|";
            cout<<setw(3)<<matriz[i][j];
        }
        cout<<"|";
        cout << endl;
    }
}

// 270°: Cambias 'i' por 'j' en los ciclos y lees 'j' al revés
void imprimir_270(int matriz[5][5]) {
    cout<<"MATRIZ 270"<<endl;
    cout<<"-------------------------------------"<<endl;
    for (int j = 5 - 1; j >= 0; j--) {
        for (int i = 0; i < 5; i++) {
            cout<<"|";
            cout<<setw(3)<<matriz[i][j];
        }
        cout<<"|";
        cout << endl;
    }
}

void problem_14(){
    int matriz[5][5];
    hacer_matri(matriz);
    imprimir_90(matriz);
    imprimir_180(matriz);
    imprimir_270(matriz);

}

void problem_16(){
    int n;
    long long caminos = 1;
    cout<<"Ingrese un numero n para saber cuantos caminos serian para llegar al final en un cuadrado nxn"<<endl;
    cin>>n;

    // Se calcula (2n)! / (n! * n!) acumulando la multiplicación y división paso a paso.
    // Esto evita generar números gigantes intermedios que rompan el tipo de dato.
    for (int i = 1; i <= n; i++) {
        caminos = caminos * (n + i) / i; // Agregado: acumula la fracción multiplicando (n+i) y dividiendo entre i en cada vuelta
    }

    cout<<"El numero de caminos es: "<<caminos<<endl;
}
