
#include<stdio.h>
#include<stdlib.h>
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>

void printArray(int arr[], int n)
{
   int i;
   for (i=0; i < n; i++)
       printf("%d ", arr[i]);
   printf("\n");
}

void insertionSort(int arr[],int n){
	int key,j,i;
	for(i=1;i<n;i++){
		int key = arr[i];
		j=i-1;
		while(j>=0 && key<arr[j])
		{
			arr[j+1]=arr[j];
			j=j-1;
		}
		arr[j+1] = key;
	}
}

void merge(int arr[],int l,int m, int r){
	int n1 = m-l+1;
	int n2 = r-m;
	int L[n1], R[n2];
	for(int i = 0;i<n1;i++){
		L[i]= arr[l+i];
	}
	for(int i = 0;i<n2;i++){
		R[i]= arr[m+i+1];
	}
	int i =0,j=0,k=l;
	while(i<n1 && j<n2){
		if(L[i]<R[j]){
			arr[k] = L[i];
			i++;
		}
		else{
			arr[k]=R[j];
			j++;
		}
		k++;
	}
	while(i<n1){
		arr[k]=L[i];
		i++;
		k++;
	}
	while(j<n2){
		arr[k]=R[j];
		j++;
		k++;
	}

}
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
void mergeSort(int arr[],int l,int r){
	if(r>l)
	{
		int mid = l+(r-l)/2;
		mergeSort(arr,l,mid);
		mergeSort(arr,mid+1,r);
		merge(arr,l,mid,r);
	}
}

int partition(int arr[], int l, int h){
	int pivot = arr[h];
	int i = l-1;
	std::cout<<"hello\n";
	for(int j=l;j<h;j++){

		if(arr[j]<=pivot){
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[i+1],&arr[h]);

	return i+1;

}

void quicksort(int arr[],int l, int h){
	if(l<h)
	{
		int index  = partition(arr,l,h);
		quicksort(arr,l,index-1);
		quicksort(arr,index+1,h);
	}
}
/* Driver program to test above functions*/
int main()
{

	    int arr[] = {12, 11, 13, 5, 6};
	    int n = sizeof(arr)/sizeof(arr[0]);

	    //insertionSort(arr, n);
	    //mergeSort(arr,0,n-1);
	    quicksort(arr,0,n-1);
	    printArray(arr, n);

	    return 0;

}
