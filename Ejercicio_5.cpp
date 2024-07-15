#include <iostream>
using namespace std;

int main() {
int matriz[4][4] = {
    {1,2,3,1},
    {4,5,9,7},
	{2,7,1,2},
	{3,1,4,8}
};
int max=matriz[0][0];
int min=matriz[0][0];

for (int i=0;i<4;i++) {
	for (int j=0;j<4;j++) {
		if (matriz[i][j]>max) {
			max=matriz[i][j];
		}	
		if (matriz[i][j]<min) {
			min=matriz[i][j];
		}	
   }
}
cout<<"Programa que encuentra el valor maximo y el minimo de una matriz\n"<<endl;
cout<<"MATRIZ DE ORDEN 4:"<<endl;
for (int i=0;i<4;i++) {
	for (int j=0;j<4;j++) {
		cout<<matriz[i][j]<<" ";	
   }
   cout<<endl;
}
cout<<endl;
cout<<"El maximo valor de la matriz es: "<<max<<endl;
cout<<endl;
cout<<"Y se encuentra en las posiciones:"<<endl;
for (int i=0;i<4;i++) {
   for (int j=0;j<4;j++) {
   		if (matriz[i][j]==max) {
   			cout<<"Fila "<<i<<" , Columna "<<j<<endl;
		   }
   }
}
cout<<endl;
cout<<"El minimo valor de la matriz es: "<<min<<endl;
cout<<endl;
cout<<"Y se encuentra en las posiciones:"<<endl;
	for (int i=0;i<4;i++) {
	   for (int j=0;j<4;j++) {
	   		if (matriz[i][j]==min) {
	   			cout<<"Fila "<<i<<" , Columna "<<j<<endl;
			   }
	   }
	}
	return 0;
}
