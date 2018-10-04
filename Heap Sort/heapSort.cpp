#include<iostream>
#include<string>
#include<stdlib.h>

using namespace std;

//declaramos el rango del array, el numero de datos y el numero de posiciones
int arr[100];
int nT = 100;
int n = 101;

/* Se encargar de ordenas todos los montinculos, partiendo desde el ultimo padre, hasta el primero esto hace que el
mayor elemento quede en la primera posicion, y todos los 'monticulos' queden ordenados */
void heapify(int a) {

	if (a != -1) {

		int ultimoPadre = a;
		int hijoIzq = a * 2 + 1;
		int hijoDerecho = a * 2 + 2;

		if (hijoIzq <= n - 1) {
			if (arr[hijoIzq] > arr[ultimoPadre]) {
				int aux = arr[ultimoPadre];
				arr[ultimoPadre] = arr[hijoIzq];
				arr[hijoIzq] = aux;
			}
		}

		if (hijoDerecho <= n - 1) {
			if (arr[hijoDerecho] > arr[ultimoPadre]) {
				int aux = arr[ultimoPadre];
				arr[ultimoPadre] = arr[hijoDerecho];
				arr[hijoDerecho] = aux;
			}
		}
		heapify(a - 1);
	}
}


void swap() {
	int aux = arr[n - 1];
	arr[n - 1] = arr[0];
	arr[0] = aux;
	n--;
}
// Genera todo el ordenamiendo, se repite dependiendo el numero de posiciones del arreglo, se ordenan los monticulos y se cambia
void heap_sort() {

	for (int i = 0; i<nT; i++) {
		heapify((n - 1) / 2);
		swap();
	}
	

}

void generar_array() {
	
	for (int i = 0; i <= nT; i++) {
		arr[i] = rand() % nT;
	}
}

void mostrar_array() {
	int i;
	for (i = 0; i <= nT; i++) {
		cout << arr[i] << " , ";
	}
}
int main()
{
	cout << "******ARRAY:********" << endl;
	generar_array();
	mostrar_array();
	cout << endl;
	cout << "******ORDENADO********" << endl;
	heap_sort();
	mostrar_array();
	
	/*La operación de heapify toma O (log(n)) tiempo. 
	Cuando intercambias el max con otro desde el fondo de tu heap, deberás empujar hacia abajo. 
	Debido a que hay n elementos y la altura del heap es igual a log (n), se hace log (n) swaps a medida de que se atraviesa el heap.
	Si se repite esto n veces, el tiempo será O (nlog (n)).
	O(n) + ∑i de 0 a n = O(log i)
*/

}
