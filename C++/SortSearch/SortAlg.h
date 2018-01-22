#include <iostream>
#include <cmath>
using namespace std;


	template<typename T>
void exchangesort(int n, T S[])
{
	for(int i = 0; i<n; i++)
	{
		for(int j = 0; j<n; j++)
		{
			if(S[j]>S[i])
			{
				T temp = S[j];
				S[j] = S[i];
				S[i] = temp;
			}
		}
	}
}

	template<typename T>
void display(int n, T S[])
{
	for(int i = 0;i<n;i++)
		cout<<S[i]<<" ";
	cout<<"\n";
}

	template<typename T>
void merge(int h, int m, const T U[],const T V[],T S[])
{
	int i= 0, j = 0, k = 0;
	while(i<h && j<m){
		if(U[i] < V[j]){
			S[k] = U[i];
			i++;
		}
		else {
			S[k] = V[j];
			j++;
		}
		k++;
	}
	if(i>=h){
		for(int x = 0; x<m-j; x++)
			S[k+x] = V[j+x];
	}
	else{
		for (int x = 0; x < h-i;x++)
			S[k+x] = U[i+x];
	}
}
	template<typename T>
void mergesort(int n, T S[])
{
	if(n > 1)
	{
		const int h = floor(static_cast<double>(n)/2), m = n-h;
		T U[h];
		T V[m];
		for(int i = 0; i<h;i++)
		{
			U[i] = S[i];
		}
		for(int i = 0; i<m;i++)
		{
			V[i] = S[i+h];
		}
		mergesort(h,U);
		mergesort(m,V);
		merge(h,m,U,V,S);
	}
}

	template<typename T>
int partition(int low, int high, T S[])
{
	T pivotitem = S[low];
	int j = low;
	for(int i = low + 1; i <= high; i++){
		if(S[i] < pivotitem){
			j++;
			T temp = S[i];
			S[i] = S[j];
			S[j] = temp;
		}
	}
	T temp = S[low];
	S[low] = S[j];
	S[j] = temp;
	return j;
}

	template<typename T>
void quicksort(int low, int high, T S[])
{
	if(high > low){
		int pivotpoint = partition(low,high,S);
		quicksort(low,pivotpoint-1,S);
		quicksort(pivotpoint+1,high,S);
	}
}

	template<typename T>
void insertionsort(int n, T S[])
{
	int i,j;
	T x;
	for(i = 1;i < n;i++){
		x = S[i];
		j = i - 1;
		while (j >= 0 && S[j] > x)
		{
			S[j+1] = S[j];
			j--;
		}
		S[j+1] = x;
	}
}

	template<typename T>
void selectionsort(int n, T S[])
{
	int i, j, smallest;
	for ( i = 0; i < n-1; i++)
	{
		smallest = i;
		for ( j = i+1; j < n; j++)
			if( S[j] < S[smallest])
				smallest = j;
		T temp = S[i];
		S[i] = S[smallest];
		S[smallest] = temp;
	}
}
