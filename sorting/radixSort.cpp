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


void countSort(int a[],int n, int place){
	int range = 10;
	int freq[range] = {0};

	for(int i=0; i<n; i++)
	{
		freq[(a[i]/place)%range]++;
	}

// cumulative frequency acts as index
	for(int i=1; i<range; i++)
	{
		freq[i]+=freq[i-1];
	}
    
    int out[n];
	for(int i=n-1; i>=0; i--)
	{
		out[freq[(a[i]/place)%range]-1] = a[i];
		freq[(a[i]/place)%range]--;
	}

	for(int i=0; i<n; i++){
		a[i]=out[i];
	}
}



void radixSort(int a[], int n, int maxx){
	int place = 1;
	while(maxx)
	{
		countSort(a,n,place);
		place*=10;
		maxx/=10;
	}
}

int main(int argc, char const *argv[])
{
	int a[] = {4,1,6,3,1,7,5,1,1,2};
	int n = sizeof(a)/sizeof(a[0]);
    int max = a[0];

    for(int i=1; i<n; i++){
    	if(a[i]>max)
    	{
    		max == a[i];
    	}
    }

    radixSort(a,n,max);

	show(a,n);
	
	return 0;
}
