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

void selSort(int a[], int n){
	for(int i=0; i<n; i++){
		int min = i;
		for(int j = i+1; j<n; j++){
			if(a[j]<a[i]){
				min = j;
				cout<<i<<":::"<<j<<":::";
                show(a,n);
                cout<<"\n";

			}
		}swap(&a[min],&a[i]);
	}
}

void stableSelSort(int a[], int n){
	for(int i = 0; i<n; i++){
		int min = i;
		for(int j =0; j<n; j++){
			if(a[min]>a[j]){
				min = j;
			}
			cout<<"::j::"<<j<<"\n";
			int key = a[min];
			while(min>i){
				a[min] = a[min-1];
				min--;
			}a[i]=key;
		}
	}
}


int main(){
	int a[] = {99,98,56,90,98,5,6,98};
	int n = sizeof(a)/sizeof(a[0]);
	selSort(a,n);
	show(a,n);
	return 0;
}

