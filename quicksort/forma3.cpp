#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <ctime>

using namespace std;
#define SIZE 10000
int a[SIZE],b[SIZE];
int count=0;

void generarArreglo()
{
	for(int i=0;i<SIZE;i++)
		a[i]=rand()%40-20;
}

void print()
{
	cout<<"[";
	for(int i=0;i<SIZE;i++){
		if(i!=SIZE-1)
			cout<<a[i]<<",";
		else
			cout<<a[i];
	}
	cout<<"]"<<endl;
}

 void swap(int *a,int *b)
{
	*a=*a+*b;
	*b=*a-*b;
	*a=*a-*b;
}

 int median(int x,int y,int z)
{
	if((x>y && x<z) || (x>z && x<y)) return 1;
	else if((y>x && y<z) || (y<x && y>z)) return 2;
	else return 3;
}
 void qsort(int l,int r)
{
	if(l>=r)
	return;

	count+=(r-l);

	int pvt,i,j,temp;
	temp=median(a[l],a[(r+l)/2],a[r]);
 	switch(temp)
	{
	case 1:break;
	case 2:swap(&a[l],&a[(r+l)/2]); break;
	case 3:swap(&a[l],&a[r]);
	}
	pvt=a[l];
 	for(i=l+1,j=l+1;j<=r;j++)
	if(a[j]<pvt)
	{
	    temp=a[j];
	    a[j]=a[i];
	    a[i]=temp;
	    i++;
    }
	temp=a[l];
	a[l]=a[i-1];
	a[i-1]=temp;
 	qsort(l,i-2);
	qsort(i,r);
}
 int main()
{
	int i;
	generarArreglo();


	std::clock_t start;
    double duration;

    start = std::clock();

 	qsort(0,SIZE-1);
 	//print();

    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;

    std::cout<<"tiempo: "<< duration <<'\n';
    print();

	return 0;
}
