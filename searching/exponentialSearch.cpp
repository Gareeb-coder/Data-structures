#include <iostream>
#include <stdio.h>
using namespace std;


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



int expSearch(int a[], int n, int x){
	if(a[0]==x){
		return 0;
	}
	int i = 1;
	while(i<n && x>=a[i])
    {
    	i = i*2;
    }

	return binSearch(a,i/2,min(i,n),x);
}




int main(int argc, char const *argv[])
{
	int a[] = {1,2,3,4,5,6,6,7,8,10};
	int n = sizeof(a)/sizeof(a[0]);
    
	
	int x =  10;

	int index = expSearch(a,n,x);
    printf("%d",index);

	return 0;
}
