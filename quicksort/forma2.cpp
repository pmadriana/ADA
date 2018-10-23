#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <ctime>
using namespace std;

void swap(int *a, int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
void print(int *p,int *q){
	int tam=q-p+1;
	cout<<"[";
	for(int i=0;i<tam;i++){
		if(i!=tam-1)
			cout<<p[i]<<",";
		else
			cout<<p[i];
	}
	cout<<"]"<<endl;
}

int* sort(int *p,int *q,int *pivote){
	int temp;
	for(int *i=p; i<pivote;){
		if(*i > *pivote){
			int *aux=i;
			temp=*aux;
			for(;aux<pivote;aux++)
				swap(aux,aux+1);
			*(aux)=temp;
			pivote--;
		}
		else
		   i++;
	}
	for(int *i=q; i>pivote;){
		if(*pivote > *i){
			int *aux=i;
			temp=*aux;
			for(;aux>pivote;aux--)
				swap(aux,aux-1);
			*(aux)=temp;
			pivote++;
		}
		else
		   i--;
	}
	return pivote;
}

void QuickSort(int *p,int *q){
	int *pivote=p;
	pivote+=(q-p)/2;
	pivote= sort(p,q,pivote);
	if(p<pivote)
		QuickSort(p,pivote-1);
	if(q>pivote)
		QuickSort(pivote+1,q);
}

void generarArreglo(int *p, int tam){
	for(int i=0;i<tam;i++)
		p[i]=rand()%40-20;
}

int main(int argc, char *argv[]) {
	srand(time(NULL));

	int arreglo[10000];

	int *p=arreglo, *q=&arreglo[10000-1];
    generarArreglo(p,10000);
	//print(p,q);

	std::clock_t start;
    double duration;

    start = std::clock();

    QuickSort(p,q);

    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;

    std::cout<<"tiempo: "<< duration <<'\n';
   // print(p,q);
	return 0;

}
