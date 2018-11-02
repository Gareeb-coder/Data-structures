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
	int freq[1000]={0};
	for(int i=0; i<n; i++)
	{
		freq[a[i]]++;
	}

	for(int i=1; i<1000; i++){
		freq[i]+=freq[i-1];
	}
    
    int out[n];
	for(int i = n-1; i>=0; i--){
		out[freq[a[i]]-1] = a[i];
		freq[a[i]]--;
	}

	for(int i=0; i<n; i++){
		a[i]=out[i];
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
