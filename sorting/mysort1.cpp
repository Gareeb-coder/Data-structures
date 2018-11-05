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

void mySort(int a[], int n){
		for(int i=0; i<n; i++){
		int min = i;
		for(int j=i+1; j<n; j++){
			if(a[j]<a[min]){
				min = j;
			}
		}
		swap(&a[i],&a[min]);
	}

}

int main(int argc, char const *argv[])
{
	int a[] = {99,98,54,6,2,55,76,103,43,1};
	int n = sizeof(a)/sizeof(a[0]);

	mySort(a,n);
	show(a,n);
	
	return 0;
}