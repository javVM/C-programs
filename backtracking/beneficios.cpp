#include<iostream>
#include<algorithm>
using namespace std;

void maxBeneficios(int n, int m, int v[], int pos, int beneficios, int &sol, int num) {
	if (num == n && beneficios > sol) {
		sol = beneficios;
	}
	
	if (pos < m) {
		if (num < n && (beneficios + v[pos]) > sol) {
			maxBeneficios(n, m, v, pos + 1, beneficios + v[pos], sol, num + 1);
		}
		maxBeneficios(n, m, v, pos + 1, beneficios, sol, num);
	}
}

int resuelveCaso(int n, int m, int v[]) {
	int pos = 0;
	int beneficios = 0;
	int sol = 0;
	int num = 0;

	maxBeneficios(n, m, v, pos, beneficios, sol, num);
	return sol;
}

int main() {
	int n;
	int m;
	int v[200];

	while (true) {
		cin >> m;
		cin >> n;
		if (m == 0) break;

		for (int i = 0; i < m; i++) {
			cin >> v[i];
		}

		cout << resuelveCaso(n, m, v) << "\n";

	}

	return 0;
}
