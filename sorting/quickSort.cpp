#include <iostream>
#include <stdio.h>
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

// l =low , h = high
int partition(int arr[],int l, int h){
	int piv = arr[h];
	int i = l-1;

	for(int j =l; j<h; j++){
		if(arr[j] <= piv){
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[i+1],&arr[h]);
	return(i+1);
}

 

void quickSort(int arr[], int l, int h){
	if(l<h){
		int pi = partition(arr,l,h);

		quickSort(arr,l,pi-1);
		quickSort(arr,pi+1,h);
	}
}



int main()
{   
	int a[] = {99,98,54,6,2,55,76,103,43,1};
	int n = sizeof(a)/sizeof(a[0]);
	quickSort(a,0,n-1);
	show(a,n);
	return 0;
}