#include<iostream>
using namespace std;
//Javier Verde Marin
//ESP: Programa para buscar el minimo numero de cajas necesarias para insertar un numero de elementos de distintos tamaños usando Backtracking
//ENG: C++ program to find out the least number of boxers in order to fit several objects of various sizes using Backtracing
const int MAX = 20;
void resuelve(int C, int N, int v[], int k, int cajas[], int numParcial, int &solucion) {
	//Todos los objetos han sido posicionados correctamente (hemos recorrido todos)
	if ((numParcial < solucion || solucion == 0) && k == N) {
		solucion = numParcial;
		return;
	}

	if (k < N) {
		//Probamos con las cajas que ya teniamos para ver si caben
		for (int i = 0; i < numParcial; i++) {
			if (v[k] <= cajas[i]) {
				cajas[i] = cajas[i] - v[k];
				resuelve(C, N, v, k + 1, cajas, numParcial, solucion);
				cajas[i] += v[k];
			}
		}
		//Probamos creando otra caja ya que quiza se pueda aprovechar mas tarde con otros
		//objetos pero si crear otra no supera la posicion pasamos
		if (numParcial+1 < solucion || solucion == 0) {
			cajas[numParcial] = C - v[k];
			resuelve(C, N, v, k + 1, cajas, numParcial + 1, solucion);
		}
		
	}
}

int resuelveCaso(int C, int N, int v[]) {
	//Datos (junto a los parametros C, N y V
	int k = 0;
	//SolucionParcial
	int numParcial = 0;
	//Marcaje
    int cajas[MAX];
	//Solucion optima
	int solucion = 0;
	resuelve(C, N, v, k,cajas, numParcial, solucion);
	return solucion;
	
}

int main() {
	int C;
	int N;
	int v[MAX];

	while (true) {
		cin >> C;
		if (C == -1)break;
		cin >> N;

		for (int i = 0; i < N; i++) {
			cin >> v[i];
		}

		cout << resuelveCaso(C, N, v) << "\n";
	}

	return 0;
}
