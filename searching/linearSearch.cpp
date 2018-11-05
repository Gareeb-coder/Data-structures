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

int linearSearch(int a[], int n,int e){
	for(int i =0; i<n; i++){
		if(a[i]==e){
			return i;
		}
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	// int a[] = {1,2,3,4,5,6,7,8,10,6};
	int a[] = {99,98,54,6,2,55,76,103,43,1};
	int n = sizeof(a)/sizeof(a[0]);
    int e = 2;
    int index = linearSearch(a,n,e);
    if(index==-1){
    	printf("Not found\n");
    }else{
    	printf("Found at %d",index);
    }

	// show(a,n);
	return 0;
}