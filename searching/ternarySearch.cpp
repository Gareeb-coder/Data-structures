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

int ternSearch(int a[],int l,int r,int x){
	int mid1 = l + (r-l)/3;
	int mid2 = r - (r-l)/3;
	if (x==a[mid1])
	{
		return mid1;
	}

	if (x==a[mid2])
	{
		return mid2;
	}

	if (x<a[mid1])
	{
		return ternSearch(a,l,mid1-1,x);
	}

	else if (x>a[mid2])
	{
		return ternSearch(a,mid2+1,r,x);
	}

	else {
		return ternSearch(a,mid1+1,mid2-1,x);
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
    int index = ternSearch(a,0,n-1,x);
    printf("%d",index);

	return 0;
	return 0;
}