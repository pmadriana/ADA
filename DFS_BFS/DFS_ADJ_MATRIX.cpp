////DFS Y BFS CON MATRIZ DE ADYACENCIA
#include <iostream>
#include <vector>
#include <queue>
#include <memory>
#include <string>
#include <stack>
using namespace std;
class graph {
	int n;
	vector< vector<int> > matrix;
public:
	graph(int n) {
		this->n = n;
		matrix = vector<vector<int> >(n, vector<int>(n));
	}
	void addEdge(int a, int b);
	void printGraph();
	void BFS(int i);
	void DFS(int i);
};
void graph::addEdge(int a, int b) {
	matrix[a][b] = 1;
	matrix[b][a] = 1;
}
void graph::printGraph() {
	string str = "";
	cout << "    ";
	for (int i = 0; i<n; i++) {
		cout << i << " ";
		str += "-";
	}
	str += str;
	cout << "\n    " << str << "\n";
	for (int i = 0; i<n; i++) {
		cout << i << " : ";
		for (int j = 0; j<n; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}
}
void graph::BFS(int i) {
	cout << "BFS : ";
	queue<int> q;
	q.push(i);
	vector<int> visited(n, 0);
	visited[i] = 1;
	while (!q.empty()) {
		int p = q.front();
		for (int j = 0; j<n; j++) {
			if (matrix[p][j] == 1 && visited[j] != 1) {
				q.push(j);
				visited[j] = 1;
			}
		}
		cout << q.front() << " ";
		q.pop();
	}
}
void graph::DFS(int k) {
	cout << "DFS : ";
	stack<int> s;
	vector<int> visited(n, 0);
	s.push(k);
	visited[k] = 1;
	while (!s.empty()) {
		int p = s.top();
		cout << p << " ";
		s.pop();
		for (int j = 0; j<n; j++) {
			if (matrix[p][j] == 1 && visited[j] != 1) {
				visited[j] = 1;
				s.push(j);
			}
		}
	}
}
int main() {
	int n;
	cout << "Ingresa numero de nodos: ";
	cin >> n;
	graph gh(n);
	int start, opcion = 1, eleccion, i, j;
	while (opcion) {
		cout << "\n 1.Ins Arista \n 2.Imprimir matriz de adyacencia \n 3.BFS \n 4.DFS \n 5.Exit\n";
		cin >> eleccion;
		switch (eleccion) {
		case 1:
			cout << "INGRESA 2 NODOS : ";
			cin >> i >> j;
			gh.addEdge(i, j);
			break;
		case 2:
			gh.printGraph();
			break;
		case 3:
			cout << "ELIGE UN NODO PARA COMENZAR ";
			cin >> i;
			gh.BFS(i);
			break;
		case 4:
			cout << "ELIGE UN NODO PARA COMENZAR";
			cin >> start;
			gh.DFS(start);
			break;
		case 5:
			eleccion= 0;
			break;
		default:
			cout << "entra una op valida\n";
			break;
		}
	}
	return 0;
}
