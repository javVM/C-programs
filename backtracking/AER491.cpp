#include<iostream>
using namespace std;
//Javier Verde Marin
const int MAX = 24;

void resuelve(int v[], int n, int peso, int pesoTotal, int numUvas, int &sol, int pos) {
	
	//Si es solucion: añadimos 1 al contador de soluciones 
	/* Condiciones: 
	   1. Obviamente no pasarse de la n
	   2. No pasarnos del peso máximo
	   3. No pasarse de las 12 uvas que se toma uno en nochebuena
	*/
	if (pos <= n && (pesoTotal <= peso) && numUvas == 12){
		sol++;
	}

	//La sol es nuestra solucion parcial hasta que acaba el programa
	// Solucion prometedora
	/*Condiciones 
	    1. No nos pasamos de la n
		2. La uvas actuales y la siguiente no se pasa de las 12
		3. El peso de las anteriores más el de la uva que tenemos ahora no se pasa del maximo
	*/
	if (pos < n && numUvas < 12 && pesoTotal < peso) {
		resuelve(v, n, peso, pesoTotal, numUvas, sol, pos + 1);

		//Si es prometedora, continuamos con esa solucion
		if ( pos < n && (numUvas + 1) <= 12 && (pesoTotal + v[pos]) <= peso) {
			resuelve(v, n, peso, pesoTotal + v[pos], numUvas + 1, sol, pos+1);
		}

	}
}
	

int resuelveCaso(int v[], int n, int peso) {
	int pesoTotal = 0;
	int numUvas = 0;
	int pos = 0;
	int sol = 0;
	resuelve(v, n, peso, pesoTotal, numUvas, sol, pos);
	return sol;
}

int main() {
	int peso;
	int n;
	int v[MAX];

	while (true) {
		cin >> peso;
		cin >> n;

		if (n == 0 && peso == 0) break;

		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}

		cout << resuelveCaso(v, n, peso) << "\n";
	}

	return 0;
}
