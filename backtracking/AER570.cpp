#include<iostream>
#include<string>
using namespace std;

long long int LettertoNum(char letra) {
	switch (letra) {
	  case 'T': return 0;
	  case 'R': return 1;
	  case 'W': return 2;
	  case 'A': return 3;
	  case 'G': return 4;
	  case 'M': return 5;
	  case 'Y': return 6;
	  case 'F': return 7;
	  case 'P': return 8;
	  case 'D': return 9;
	  case 'X': return 10;
	  case 'B': return 11;
	  case 'N': return 12;
	  case 'J': return 13;
	  case 'Z': return 14;
	  case 'S': return 15;
	  case 'Q': return 16;
	  case 'V': return 17;
	  case 'H': return 18;
	  case 'L': return 19;
	  case 'C': return 20;
	  case 'K': return 21;
	  case 'E': return 22;
	}
}

void resuelve(char digitos[], long long int &numSoluciones, int numeroLetra, long long int acum, int pos) {
	
	if (pos == 8 && (acum % 23 == numeroLetra)) {
		numSoluciones++;
		return;
	 }
	
	if (pos == 8) {
		return;
	}

	if (pos < 8) {
		if (digitos[pos] != '?') {
			acum *= 10;
			acum += (digitos[pos] - 48);
			resuelve(digitos, numSoluciones, numeroLetra, acum , pos + 1);
		}
		else {
			for (int i = 0; i < 10; i++) {
				resuelve(digitos, numSoluciones, numeroLetra, (acum * 10) + i, pos + 1);
			}
		}


	}
}

long long int resuelveCaso(char dni[], char letra) {
	long long int numSoluciones = 0;
    int acum = 0;
	int pos = 0;
	resuelve(dni, numSoluciones, LettertoNum(letra), acum, pos);
	return numSoluciones;
}

int main() {
	int numCasos;
	char dni[8];
	char letra;
	cin >> numCasos;
	while (numCasos > 0) {
		for (int i = 0; i < 8; i++) cin >> dni[i];
		cin >> letra;
		cout << resuelveCaso(dni, letra) << "\n";
		numCasos--;
	}
}
