#include <iostream>
using namespace std;

int main() {
int matriz[4][4] = {
    {1,2,3,1},
    {4,5,9,7},
	{2,7,1,2},
	{3,1,4,8}
};
int matrizIntercambiada[4][4];
//copia de la matriz
for (int i=0;i<4;i++) {
	for (int j=0;j<4;j++) {
		matrizIntercambiada[i][j]=matriz[i][j];
   }
}

int aux;
int n,m;
cout<<"Programa que intercambia dos filas especificas de una matriz\n"<<endl;
cout<<"MATRIZ DE ORDEN 4:\n"<<endl;
for (int i=0;i<4;i++) {
	for (int j=0;j<4;j++) {
		cout<<matriz[i][j]<<" ";	
   }
   cout<<endl;
}
cout<<"\nIngrese las dos filas a intercambiar: "<<endl;
cin>>n>>m;
for (int j=0;j<4;j++) {
   	aux=matrizIntercambiada[n][j];
   	matrizIntercambiada[n][j]=matrizIntercambiada[m][j];
   	matrizIntercambiada[m][j]=aux;
	}
cout<<"\nMATRIZ ORIGINAL:\tMATRIZ CON FILAS INTERCAMBIADAS:"<<endl;
 for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << "\t\t\t";
        for (int j = 0; j < 4; j++) {
            cout << matrizIntercambiada[i][j] << " ";
        }        
        cout << endl;
    }
return 0;
}