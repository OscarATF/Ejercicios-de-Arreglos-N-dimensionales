#include <iostream>
using namespace std;

int main() {
    int matriz[5][5]={
        {1,2,3,4,5},
        {6,7,8,9,10},
        {11,12,13,14,15},
        {16,17,18,19,20},
        {21,22,23,24,25}
    };

    int filaInicio=0;
	int filaFin=4;
	int columnaInicio=0;
	int columnaFin=4;
	cout<<"Programa que recorre los elementos de una matriz en orden espiral\n"<<endl;
    cout<<"MATRIZ DE ORDEN 5:"<<endl;
	for (int i=0;i<5;i++) {
		for (int j=0;j<5;j++) {
		cout<<matriz[i][j]<<" ";	
   		}
   	cout<<endl;
	}
	cout<<endl;
	cout<<"Recorrido en espiral:\n"<<endl;
    while (filaInicio<=filaFin && columnaInicio<=columnaFin) {
        //fila superior
        for (int j=columnaInicio;j<=columnaFin;j++) {
            cout<<matriz[filaInicio][j]<<" ";
        }
        filaInicio++;

        //columna derecha
        for (int i=filaInicio;i<=filaFin;i++) {
            cout<<matriz[i][columnaFin]<<" ";
        }
        columnaFin--;

        //fila inferior
        if (filaInicio<=filaFin) {
            for (int j=columnaFin;j>=columnaInicio;j--) {
                cout<<matriz[filaFin][j]<<" ";
            }
            filaFin--;
        }

        //columna izquierda
        if (columnaInicio<=columnaFin) {
            for (int i=filaFin;i>=filaInicio;i--) {
                cout<<matriz[i][columnaInicio]<<" ";
            }
            columnaInicio++;
        }
    }
	cout<<endl;
    return 0;
}
