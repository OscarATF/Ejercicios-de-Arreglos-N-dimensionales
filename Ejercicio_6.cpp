#include <iostream>
using namespace std;

void matrizReflejada(int matriz[][6],int matrizR[][6],int filas,int columnas) {
	int aux;
	//copia de la matriz
	for (int i=0;i<6;i++) {
		for (int j=0;j<6;j++) {
			matrizR[i][j]=matriz[i][j];
		}
	}
	//reflejar matriz
	for (int i=0;i<6;i++) {
		for (int j=0;j<3;j++) {
        	aux=matrizR[i][j];
        	matrizR[i][j]=matrizR[i][5-j];
        	matrizR[i][5-j]=aux;
    	}
	}
}

int main() {
int matriz[6][6] = {
    {1,2,3,1,5,7},
    {4,5,9,7,3,1},
	{2,7,1,2,9,3},
	{3,1,0,8,0,1},
	{6,2,9,0,2,4},
	{8,2,6,1,2,6}
};
int matrizR[6][6];
matrizReflejada(matriz,matrizR,6,6);
cout<<"Programa que refleja la imagen de una matriz\n"<<endl;
cout<<"  MATRIZ:\t\tMATRIZ REFLEJADA HORIZONTALMENTE:"<<endl;
 for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << "\t\t\t";
        for (int j = 0; j < 6; j++) {
            cout << matrizR[i][j] << " ";
        }        
        cout << endl;
    }
}