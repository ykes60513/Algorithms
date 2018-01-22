#include <iostream>
#include <cmath>
using namespace std;

template<typename T>
int location(T x, T S[], int low, int high)
{
	int mid;
	if(low > high)
		return 0;
	else
	{
		mid = floor(static_cast<double>(low+high)/2);
		if( x == S[mid])
			return mid;
		else if( x < S[mid])
			return location(x, S, low, mid-1);
		else
			return location(x, S, mid+1, high);
	}
}

template<typename T>
int binarySearch(int n, const T S[], T x)
{
	int low = 0, high = n-1, mid;
	while(low <= high)
	{
		mid = floor(static_cast<double>(low + high)/2);
		if( x == S[mid])
			return mid;
		else if( x < S[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}
