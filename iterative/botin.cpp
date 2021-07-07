#include<iostream>
#include<algorithm>
using namespace std;
//Javier Verde Marin
const int MAX = 200000;

//Complejidad: O(n) ya que se recorre el array pasando por todos los elementos

//Pre: (0 <= N <= longitud(v)) ^ (k > 0)
int botin(int v[], int n, int k) {
	int a = 0;
	int b = 0;
	int ret = 0;
	int suma = 0;

	//Cota: n - a + b
	//I: (0 <= b <= n) ^(0 <= a <= n) ^ (suma = sum j : (0 <= j < i ) : v[i]) ^
	// ( ret =  max l, m : (0 <= l <= m < i) : suma(v, l, m) <= k)
	while (b < n &&  a < n) {
		if (suma + v[b] <= k) {
			suma += v[b];
			b++;
		}
		else {
			suma -= v[a];
			a++;
		}

		if (suma <= k) {
			ret = max(ret, suma);
		}

	}

	return ret;
}
//Pos: ret =  max i, j : (0 <= i <= j < N) : suma(v, i, j) <= k donde
//suma(v, ini, fin) = sum i : ini <= i <= fin) : v[i]

int main() {
	int k;
	int v[MAX];
	int N;

	while (true) {
		cin >> N;

		if (N == 0) {
			break;
		}

		cin >> k;

		for (int i = 0; i < N; i++) {
			cin >> v[i];
		}

		cout << botin(v, N, k)<<endl;
	}

	return 0;
}
