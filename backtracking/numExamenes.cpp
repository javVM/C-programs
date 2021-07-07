#include<iostream>
//Javier Verde Marin
using namespace std;

const int MAX = 100;

typedef struct {
	float tiempo;
	float prim;
	float sec;
}tTema;

void resuelve(int n, int tiempo, tTema tema[], int pos, float notaPrim, float notaSec, float maxC1, float maxC2, float tiempoParcial, float &maxSol) {
	if (((notaPrim + notaSec) / 2) > maxSol) {
		maxSol = (notaPrim + notaSec) / 2;
	
	}

	if (pos < n) {

		if ((tiempoParcial + tema[pos].tiempo) <= tiempo) {
			resuelve(n, tiempo, tema, pos + 1, notaPrim + tema[pos].prim, notaSec + tema[pos].sec, maxC1 - tema[pos].prim, 
				maxC2 - tema[pos].sec, tiempoParcial + tema[pos].tiempo, maxSol);
		}

	    
		if ((notaPrim + maxC1) - tema[pos].prim >= 5) {
			if ((notaSec + maxC2) - tema[pos].sec >= 5) {
				if ((((notaPrim + maxC1) - tema[pos].prim) + ((notaSec + maxC2) - tema[pos].sec)) / 2 > maxSol) {
					resuelve(n, tiempo, tema, pos + 1, notaPrim, notaSec, maxC1 - tema[pos].prim, maxC2 - tema[pos].sec, tiempoParcial, maxSol);
				}
			}
		}
		
	}
}

int resuelveCaso(int N, int tiempo, tTema tema[]) {
	int pos = 0;
	float notaPrim = 0;
	float notaSec = 0;
	float tiempoParcial = 0;

	float maxc1 = 0;
	float maxc2 = 0;
	for (int i = 0; i < N; i++) {
		maxc1 += tema[i].prim;
		maxc2 += tema[i].sec;

	}

	float maxSol = -1;
	if (maxc1 >= 5 && maxc2 >= 5) {
		resuelve(N, tiempo, tema, pos, notaPrim, notaSec, maxc1, maxc2, tiempoParcial, maxSol);
	}
	return maxSol;
}
int main() {
	int N;
	int tiempo;
	tTema temas[MAX];
	while (cin >> N && cin >> tiempo) {
		for (int i = 0; i < N; i++) {
			tTema aux;
			cin >> aux.tiempo;
			cin >> aux.prim;
			cin >> aux.sec;
			temas[i] = aux;
		}

		cout << resuelveCaso(N, tiempo, temas) << '\n';
	}
	return 0;
}
