#include <iostream>
using namespace std;

void mult(int m1[][3],int m2[][3],int mr[][3],int columnas,int filas) {
	    for (int i=0;i<filas;i++) { //Filas matriz1
        	for (int j=0;j<columnas;j++) { //Columnas matriz2
        		mr[i][j]=0;
        		for (int k=0;k<columnas;k++) { //Columnas matriz1
        			mr[i][j]+=m1[i][k]*m2[k][j];
        	}
        }
    }
}
int main() {
int matriz1[3][3] = {
    {1,2,3},
    {4,5,6},
	{7,8,9}
};
int matriz2[3][3] = {
    {9,8,7},
    {6,5,4},
    {3,2,1}
};
int multiplicacion[3][3];    
    cout<<"Matriz resultante de la multiplicacion:\n"<<endl;
    mult(matriz1,matriz2,multiplicacion,3,3);
	for (int i=0;i<3;i++) {
        for (int j=0;j<3;j++) {
            cout<<matriz1[i][j]<<" ";
        }

        if (i==1) {
            cout<<"X ";
        } else {
            cout<<"\t";
        }
        
        for (int j=0;j<3;j++) {
            cout<<matriz2[i][j]<< " ";
        }
        
        if (i==1) {
            cout<<"= ";
        } else {
            cout<<"\t";
        }
        
        for (int j=0;j<3;j++) {
            cout<<multiplicacion[i][j]<<" ";
        }
        
        cout<<endl;
    }
    return 0;
}