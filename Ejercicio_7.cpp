#include <iostream>
using namespace std;

void matrizRotada(int matriz[][4],int matrizR[][4],int filas,int columnas) {
	int aux;
	//transponer matriz
	for (int i=0;i<4;i++) {
		for (int j=0;j<4;j++) {
			matrizR[j][i]=matriz[i][j];
		}
	}
	//reflejar matriz
	for (int i=0;i<4;i++) {
		for (int j=0;j<2;j++) {
			aux=matrizR[i][j];
			matrizR[i][j]=matrizR[i][3-j];
			matrizR[i][3-j]=aux;
		}
	}
}

int main() {
int matriz[4][4] = {
    {1,2,3,5},
    {4,5,9,7},
	{2,7,1,2},
	{3,1,4,8}
};

int matrizR[4][4];
matrizRotada(matriz,matrizR,4,4);
cout<<"Programa que rota una matriz 90 grados\n"<<endl;
cout<<"MATRIZ:\t\t\tMATRIZ ROTADA 90 GRADOS HORARIO:"<<endl;
 for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << "\t\t\t";
        for (int j = 0; j < 4; j++) {
            cout << matrizR[i][j] << " ";
        }        
        cout << endl;
    }
}