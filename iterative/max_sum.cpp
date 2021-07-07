#include<iostream>
#include<algorithm>
using namespace std;
//Javier Verde Marin
//Complejidad O(n) ya que se recorren todos los elementos del vector
//Cota: 2n - b - a
//Precondición: (0 <= m <= s <= longitud(v) ^ 
int sumaMaxima(int s, int m, int v[]) {
	int a = 0;
	int b = 0;
	int ret = 0;
	int suma = 0;
	int cont = 0;
	//(0 <= a <= s) ^ (0 <= b <= s) ^ (ret = max i j : (a <= i < j < b)  ^ (j - i = m): suma(v, i, j) ^ 
	//(suma = suma(v, i, j) ^ cont = # i : (a <= i <= b) : i <= m
	while (a < s  && b < s) {
		if (cont < m || a == b) {
			suma += v[b];
			cont++;
			b++;
		}
		else {
			cont--;
			suma -= v[a];
			a++;
		}

		if (cont == m) {
			ret = max(ret, suma);
		}
	}

	return ret;
}
//Pos: ret = max i j : (0 <= i < j < s)  ^ (j - i = m): suma(v, i, j)
//suma(v, ini, fin) = sum i : (ini <= i <= fin): v[i]
