#include <algorithm>
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

int jumpSearch(int a[], int n, int x){
	int step = sqrt(n);
	int loc =0;
	while(a[loc]<x){
		loc+=step;		
	}
	for(int i = loc; i>=loc-step; i--){
		if(a[i]==x)
			return i;
	}
	return -1;
}

int jumpSearch2(int a[],int n,int x){
	int step = sqrt(n);
	int prev = 0;
	while(a[min(step,n)-1]<x)
	{
		prev = step;
		step+=sqrt(n);
		if(prev>=n)
			return -1;
	}
	while(a[prev] <x){
		prev +=1; 
	}
	if(a[int(prev)]==x)
		return prev;

	return -1;
}

int main(int argc, char const *argv[])
{
	int a[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610};
    int x = 21;
	int n = sizeof(a)/sizeof(a[0]);
	// int index = jumpSearch(a,n,x);
	int index = jumpSearch2(a,n,x);
	printf("%d\n",index );
	
	return 0;
}