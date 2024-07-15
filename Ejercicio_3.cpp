#include <iostream>
using namespace std;

int main() {
int matriz[4][4] = {
    {1,2,3,1},
    {4,5,9,7},
	{2,7,1,2},
	{3,1,4,8}
};
int j=3;
int sumaDiagonales=0;
for (int i=0;i<4;i++) {
   	for (int j=0;j<4;j++) {
   		if (i==j) {
   			sumaDiagonales+=matriz[i][j];
		}
	}
	sumaDiagonales+=matriz[i][j];
	j--;
}
cout<<"Programa que suma las diagonales de una matriz\n"<<endl;
cout<<"MATRIZ DE ORDEN 4:\n"<<endl;
for (int i=0;i<4;i++) {
	for (int j=0;j<4;j++) {
		cout<<matriz[i][j]<<" ";	
   }
   cout<<endl;
}
cout<<"\nLa suma de la diagonal principal y secundaria es: ";
cout<<sumaDiagonales;
cout<<endl;
}