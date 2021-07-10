//Find the shortest path from the beginning position to the exit (both data as input) using the sequence E D A 

bool continua(char a, char b) {
	if ((a == 'E' && b == 'D') || (a == 'D' && b == 'A') || (a == 'A' && b == 'E')) return true;
	return false;
}

void resuelve(int N, int M, char lab[MAX][MAX], int i, int j, int x_fin, int y_fin, char direcciones[], char direccionSol[], int longitud,
	int &sol) {

	if (i = x_fin && j == y_fin) {
		if (longitud < sol || sol == 0) {
			sol = longitud;
			for (int k = 0; k < longitud; k++) {
				direccionSol[k] = direcciones[k];
			}
		}
	}
	
		if ( i + 1 <= N && continua(lab[i][j], lab[i + 1][j])) {
			direcciones[longitud + 1] = lab[i + 1][j];
			resuelve(N, M, lab, i + 1, j, x_fin, y_fin, direcciones, direccionSol, longitud + 1, sol);
		}

		if (j + 1 <= M && continua(lab[i][j], lab[i][j+1])) {
			direcciones[longitud + 1] = lab[i][j+1];
			resuelve(N, M, lab, i, j+1, x_fin, y_fin, direcciones, direccionSol, longitud + 1, sol);
		}
	


		if (j - 1 >= 0 && continua(lab[i][j], lab[i][j - 1])) {
			direcciones[longitud + 1] = lab[i][j - 1];
			resuelve(N, M, lab, i, j - 1, x_fin, y_fin, direcciones, direccionSol, longitud + 1, sol);
		}
	

}

void resuelveCaso(int N, int M, char lab[MAX][MAX], int x_ini, int y_ini, int x_fin, int y_fin, char direcciones[MAX]) {
	int longitudMax = 0;
	int longitudParcial = 1;
	char direccionSol[MAX];
	direcciones[0] = lab[x_ini][y_ini];
	resuelve(N, M, lab, x_ini, y_ini, x_fin, y_fin, direcciones, direccionSol, longitudParcial, longitudMax);

	for (int i = 0; i < longitudMax; i++) {
		if (i < longitudMax - 1) {
			cout << direccionSol[i] << ", ";
		}
		else {
			cout << direccionSol[i] << endl;
		}
	}
}

int main() {
	int N;
	int M;
	char lab[MAX][MAX];
	char direcciones[MAX];
	int x_ini;
	int y_ini;
	int x_fin;
	int y_fin;

	while (true) {
		cin >> N;
		cin >> M;

		if (N == 0) { break; }

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> lab[i][j];
			}
		}

		cin >> x_ini;
		cin >> y_ini;
		cin >> x_fin;
		cin >> y_fin;

		resuelveCaso(N, M, lab, x_ini, y_ini, x_fin, y_fin, direcciones);
	}
	return 0;
}
