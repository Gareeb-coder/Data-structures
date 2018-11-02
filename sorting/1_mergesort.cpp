#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;


void show(int a[],int n){
	for(int i=0; i<n; i++){
		printf("%d ",a[i]);
	} printf("\n");
}

void merge(int A[],int p,int q,int r)
{
	int n1 = q-p+1;
	int n2 = r-q;
	int L[n1];
	int R[n2];
	for (int i = 0; i < n1; i++)
	{
		L[i] = A[p+i];
	}
	for (int j = 0; j < n2; j++)
	{
		R[j] = A[q+j+1];
	}
	int i = 0;
	int j = 0;
	int k = p;
	while(i<n1 && j<n2)
	{
		if(L[i] <= R[j])
		{
			A[k] = L[i];
			i++;
		}
		else
		{
			A[k] = R[j];
			j++;
		}
		k++;
	}

	while(i<n1)
	{
		A[k] = L[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		A[k] = R[j];
		j++;
		k++;
	}
}


void mergeSort(int A[],int p, int r)
{
	if(p<r)
	{
		int q = p+(r-p)/2;
		mergeSort(A,p,q);
		mergeSort(A,q+1,r);
		merge(A,p,q,r);
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