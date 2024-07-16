#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int FILAS=10;
const int COLUMNAS=10;

void mostrarBosque(int bosque[FILAS][COLUMNAS],int bosqueNuevo[FILAS][COLUMNAS]) {
    for (int i=0;i<FILAS;i++) {
        for (int j=0;j<COLUMNAS;j++) {
            cout<<bosque[i][j]<<" ";
        }
        cout<<"\t\t\t";
        for (int j=0;j<COLUMNAS;j++) {
            cout<<bosqueNuevo[i][j]<<" ";
        }
        cout<<endl;
    }
}

void propagarFuego(int bosque[FILAS][COLUMNAS],int bosqueNuevo[FILAS][COLUMNAS]) {
    // Copia del bosque
    for (int i=0;i<FILAS;i++) {
        for (int j=0;j<COLUMNAS;j++) {
            bosqueNuevo[i][j]=bosque[i][j];
        }
    }

    // Reglas de propagacion del fuego
    for (int i=0;i<FILAS;i++) {
        for (int j=0;j<COLUMNAS;j++) {
            if (bosque[i][j]==0) { // Arbol vivo
                // Verificar vecinos para ver si alguno esta quemandose
                bool vecinoQuemandose=false;
                // Direcciones de los vecinos adyacentes
                int direcciones[8][2]={
                    {-1, -1}, {-1, 0}, {-1, 1},
                    {0, -1},          {0, 1},
                    {1, -1}, {1, 0}, {1, 1}
                };
                for (int d=0;d<8;d++) {
                    int vecinoFila=i+direcciones[d][0];
                    int vecinoColumna=j+direcciones[d][1];
                    // Verificar limites del tablero
                    if (vecinoFila>=0 && vecinoFila<FILAS &&
                        vecinoColumna>=0 && vecinoColumna<COLUMNAS &&
                        bosque[vecinoFila][vecinoColumna]==1) { // Vecino quemandose
                        vecinoQuemandose=true;
                        break;
                    }
                }
                if (vecinoQuemandose) {
                    bosqueNuevo[i][j]=1;
                }
            } else if (bosque[i][j]==1) { //quemandose
                bosqueNuevo[i][j]=2; //quemado
            }
            // arbol quemado, permanece quemado
        }
    }
}

void inicializarBosque(int bosque[FILAS][COLUMNAS]) {
    srand(time(0));
    for (int i=0;i<FILAS;i++) {
        for (int j=0;j<COLUMNAS;j++) {
            bosque[i][j]=rand()%3; // Generar un número aleatorio entre 0 y 2
        }
    }
}

int main() {
    int bosque[FILAS][COLUMNAS];
    int bosqueNuevo[FILAS][COLUMNAS];
    inicializarBosque(bosque);
    cout<<"Programa que simula la propagacion del fuego\n"<<endl;
    cout<<"Bosque inicial:\t\t\tBosque despues de la propagacion del fuego:"<<endl;
    propagarFuego(bosque, bosqueNuevo);
    mostrarBosque(bosque, bosqueNuevo);

    return 0;
}
