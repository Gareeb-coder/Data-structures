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


int binSearch(int a[], int l, int r, int x)
{
	if(r>=l){
		int mid = l+(r-l)/2;

		if(x==a[mid])
		{
			return mid;
		}

		if(x<a[mid]){
			return binSearch(a,l,mid-1,x);
		}
		else
		{return binSearch(a,mid+1,r,x);}
	}
	return -1;
}

int binSearch2(int a[], int l, int r, int x){
	int m;
	while(l<=r){
		m = l+(r-l)/2;
		if(a[m]==x)
		{
			return m;
		}
		else if(x<a[m]){
			r = m-1;
		}
		else
		{
			l = m+1;
		}
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	int a[] = {2,8,4,6,7,1,9,99};
	int n = sizeof(a)/sizeof(a[0]);
    int x = 9;
    sort(a,a+n);
    show(a,n);
    int index = binSearch2(a,0,n-1,x);
    printf("%d",index);

	return 0;
}