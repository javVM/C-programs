#include<iostream>
#include<string>
using namespace std;

void resuelve(int numv, int numc, int total, string solParcial, string &sol) {

	if (solParcial.size() == total) {
		solParcial += " ";
		sol += solParcial;
	}

	if (solParcial.size() < total) {
		if (numc > 0) {
			string solaux = solParcial;
			solaux += "C";
			resuelve(numv, numc-1, total, solaux, sol);
		}

		if (numv > 0) {
			string solaux = solParcial;
			solaux += "V";
			resuelve(numv-1, numc, total, solaux, sol);
		}
	}
}

void resuelveCaso(int numv, int numc) {
	int total = numv + numc;
	string solParcial;
	string sol = "";
	resuelve(numv, numc, total, solParcial, sol);
	sol.pop_back();
	cout << sol;

	
}

int main() {

	int numCasos;
	int numV;
	int numC;

	cin >> numCasos;

	while (numCasos > 0) {
		cin >> numC;
		cin >> numV;
		resuelveCaso(numV, numC);
		cout << '\n';
		numCasos--;
	}

	return 0;
}
