#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
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

void merge(int arr[], int l, int m,int r){
	int i,j,k;
	int n1 = m-l+1;
	int n2 = r-m;

	int L[n1+1], R[n2+1];

	for(i = 0; i<n1; i++){
		L[i] = arr[l+i];
	}
	for(j = 0; j<n2; j++){
		R[j] = arr[m+1+j];
	}
	L[n1+1] = INT_MAX;
	R[n2+1] = INT_MAX;
	i = 0;
	j = 0;
	for(int k = l; k<r; k++)
	{
		if(L[i]<=R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
	}
	// i,j,k =0;
	//  while (i < n1 && j < n2) 
 //    { 
 //        if (L[i] <= R[j]) 
 //        { 
 //            arr[k] = L[i]; 
 //            i++; 
 //        } 
 //        else
 //        { 
 //            arr[k] = R[j]; 
 //            j++; 
 //        } 
 //        k++; 
 //    } 
 //    while (i < n1) 
 //    { 
 //        arr[k] = L[i]; 
 //        i++; 
 //        k++; 
 //    } 

 //     while (j < n2) 
 //    { 
 //        arr[k] = R[j]; 
 //        j++; 
 //        k++; 
 //    } 
}

void mergeSort(int arr[], int l, int r)
{
	if(l<r)
	{
		int m = l+(r-l)/2;
		mergeSort(arr, l ,m);
		mergeSort(arr, m+1, r);

		merge(arr,l,m,r);
	}
}



int main(int argc, char const *argv[])
{
	int a[] = {99,98,54,6,2,55,76,103,43,1};
	int n = sizeof(a)/sizeof(a[0]);

	show(a,n);
	mergeSort(a,0,n-1);
	show(a,n);

	return 0;
}