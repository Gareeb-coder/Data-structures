#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;


void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void show(int a[],int n){
	for(int i=0; i<n; i++){
		printf("%d ",a[i]);
	} printf("\n");
}


void countSort(int a[],int n){
	int Aux[1000]={0};
	for(int i=0; i<n; i++)
	{
		Aux[a[i]]++;
	}

	int k=0;
	for(int i=0; i<1000; i++)
	{
		while(Aux[i]!=0)
		{
			a[k] = i;
			Aux[i]--;
			k++;
		}
	}

}



int main(int argc, char const *argv[])
{
	int a[] = {4,1,6,3,1,7,5,1,1,2};
	int n = sizeof(a)/sizeof(a[0]);
    countSort(a,n);

	show(a,n);
	
	return 0;
}
