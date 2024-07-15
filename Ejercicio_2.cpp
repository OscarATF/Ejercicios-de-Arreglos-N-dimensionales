#include <iostream>
using namespace std;

int main() {
int matriz[3][3] = {
    {1,2,3},
    {4,2,6},
	{7,2,9}
};
int n;
int aux=0;
cout<<"Programa para buscar un valor especifico en una matriz"<<endl;
cout<<"\nMATRIZ"<<endl;
for (int i=0;i<3;i++) {
   for (int j=0;j<3;j++) {
   		cout<<matriz[i][j]<<" ";
   }
   cout<<endl;
}
cout<<"\nIngrese el valor a buscar: ";
cin>>n;
cout<<endl;
for (int i=0;i<3;i++) {
   for (int j=0;j<3;j++) {
   		if (matriz[i][j]==n) {
   			cout<<"Fila "<<i<<" , Columna "<<j<<endl;
   			aux++;
		}
   }
}
if (aux==0) {
	cout<<"No se encontro el valor indicado";
}
}