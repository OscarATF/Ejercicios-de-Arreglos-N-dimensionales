#include <iostream>
using namespace std;

void CuadradoLatino(int N) {
    int matriz[N][N];

    //primera fila N números naturales
    for (int j=0;j<N;j++) {
        matriz[0][j]=j+1;
    }
    //rotar a la derecha las filas siguientes
    for (int i=1;i<N;i++) {
        for (int j=0;j<N;j++) {
            matriz[i][j]=matriz[i-1][(j+N-1)%N];
        }
    }

    cout<<"CUADRADO LATINO DE ORDEN "<<N<<":"<<endl;
    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            cout<<matriz[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main() {
    int N;
    cout<<"Programa que imprime un cuadrado latino\n"<<endl;
    cout<<"Introduce el orden del cuadrado latino (N): ";
    cin>>N;
	cout<<endl;
    if (N>0) {
        CuadradoLatino(N);
    } else {
        cout<<"Numero de orden invalido"<<endl;
    }

    return 0;
}
