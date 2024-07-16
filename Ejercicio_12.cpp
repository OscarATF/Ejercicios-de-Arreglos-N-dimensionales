#include <iostream>
#include <cstdlib> 
#include <ctime>   

using namespace std;

const int FILAS=10;
const int COLUMNAS=10;

//Generar tablero aleatoriamente
void inicializarTablero(int tablero[FILAS][COLUMNAS]) {
    srand(time(0)); 
    for (int i=0;i<FILAS;i++) {
        for (int j=0;j<COLUMNAS;j++) {
            tablero[i][j]=rand()%2; // Genera 0 o 1
        }
    }
}

void mostrarTablero(int tablero[FILAS][COLUMNAS],int nuevoTablero[FILAS][COLUMNAS]) {
	for (int i=0;i<FILAS;i++) {
        for (int j=0;j<COLUMNAS;j++) {
            cout<<tablero[i][j]<<" ";
    	}
    	cout<<"\t\t";
		for (int j=0;j<COLUMNAS;j++) {
            cout<<nuevoTablero[i][j]<<" ";
        }
        cout<<endl;
    }
}

//calcular la siguiente generación del tablero
void siguienteGeneracion(int tablero[FILAS][COLUMNAS], int nuevoTablero[FILAS][COLUMNAS]) {
    // Recorrer cada célula del tablero
    for (int i=0;i<FILAS;i++) {
        for (int j=0;j<COLUMNAS;j++) {
            // Contar vecinos vivos
            int vecinosVivos=0;
            for (int di=-1;di<=1;di++) {
                for (int dj=-1;dj<=1;dj++) {
                    if ((di == 0 && dj == 0)==false) { // Excluir la célula misma
                        int vecinoFila = i + di;
                        int vecinoColumna = j + dj;
                        // Verificar límites del tablero y contar vecino vivo
                        if (vecinoFila >= 0 && vecinoFila < FILAS &&
                            vecinoColumna >= 0 && vecinoColumna < COLUMNAS &&
                            tablero[vecinoFila][vecinoColumna] == 1) {
                            vecinosVivos++;
                        }
                    }
                }
            }

            // Aplicar las reglas del Juego de la Vida de Conway
            if (tablero[i][j] == 1) { // Célula viva
                if (vecinosVivos < 2 || vecinosVivos > 3) {
                    nuevoTablero[i][j] = 0; // Muere por subpoblación o sobrepoblación
                } else {
                    nuevoTablero[i][j] = 1; // Sigue viva
                }
            } else { // Célula muerta
                if (vecinosVivos == 3) {
                    nuevoTablero[i][j] = 1; // Reproducción
                } else {
                    nuevoTablero[i][j] = 0; // Sigue muerta
                }
            }
        }
    }
}

int main() {
    int tablero[FILAS][COLUMNAS];
    int nuevoTablero[FILAS][COLUMNAS];

    inicializarTablero(tablero);
    siguienteGeneracion(tablero, nuevoTablero);

    cout<<"Juego de la vida de Conway\n"<<endl;
    cout<<"Tablero Inicial:\t\tSegunda generacion:"<<endl;
    mostrarTablero(tablero,nuevoTablero);
    cout<<endl;

    return 0;
}
