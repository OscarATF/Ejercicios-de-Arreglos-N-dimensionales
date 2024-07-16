#include <iostream>
#include <cstdlib>
#include <ctime> 
using namespace std;

const int FILAS=10;
const int COLUMNAS=10;

void inicializarTablero(int tablero[FILAS][COLUMNAS]) {
    srand(time(0));

    for (int i=0;i<FILAS;i++) {
        for (int j=0;j<COLUMNAS;j++) {
            tablero[i][j]=rand()%2; // Para valores 0 o 1
        }
    }
}

int contarMinasAdyacentes(int tablero[FILAS][COLUMNAS],int fila,int columna) {
    int contador=0;
    
    //Direcciones de los vecinos adyacentes
    int direcciones[8][2]={
        {-1,-1},{-1,0},{-1,1},
        {0,-1},        {0,1},
        {1,-1},{1,0},{1,1}
    };
    //Contar minas en los vecinos
    for (int d=0;d<8;d++) {
        int vecinoFila=fila+direcciones[d][0];
        int vecinoColumna=columna+direcciones[d][1];
        
        // Verificar límites del tablero y contar mina si existe
        if (vecinoFila>=0 && vecinoFila<FILAS &&
            vecinoColumna>=0 && vecinoColumna<COLUMNAS &&
            tablero[vecinoFila][vecinoColumna]==1) {
            contador++;
        }
    }
    return contador;
}

void mostrarTablero(int tablero[FILAS][COLUMNAS]) {
    int tableroNumeros[FILAS][COLUMNAS];
	for (int i=0;i<FILAS;i++) {
    	for (int j=0;j<COLUMNAS;j++) {
    		tableroNumeros[i][j]=tablero[i][j];
		}
	}
	for (int i=0;i<FILAS;i++) {
        for (int j=0;j<COLUMNAS;j++) {
            cout<<tablero[i][j]<<" ";
    	}
    	cout<<"\t\t";
		for (int j=0;j<COLUMNAS;j++) {
            int minasAdyacentes=contarMinasAdyacentes(tableroNumeros,i,j);
            cout<<minasAdyacentes<<" ";
        }
        cout<<endl;
    }
}

int main() {
    int tablero[FILAS][COLUMNAS];

    inicializarTablero(tablero);

    cout<<"Programa generador de tablero de buscaminas\n"<<endl;
    cout<<"Tablero original:\t\tTablero con numero de minas:" << endl;
    mostrarTablero(tablero);
	
    return 0;
}

