#include <iostream>
#include <stdio.h>
using namespace std;


int interpolSearch(int a[], int n, int x ){
	int lo = 0;
	int hi = n-1;
	while(lo<=hi && x>=a[lo] && x<=a[hi])
	{
		// int pos = lo+((x-a[lo])*(hi-lo) / (a[hi]- a[lo]));
		int pos = lo + (((double)(hi-lo) /
              (a[hi]-a[lo]))*(x - a[lo]));

		if(x == a[pos])
		{
			return pos;
		}

		if(x>a[pos])
		{
			lo = pos+1;
		}

		else
		    hi = pos-1;

	}
	return -1;
}

int main(int argc, char const *argv[])
{
	int a[] = {1,2,3,4,5,6,6,7,8,10};
	int n = sizeof(a)/sizeof(a[0]);
    
	
	int x = 10;

	int index = interpolSearch(a,n,x);
    printf("%d",index);

	return 0;
}