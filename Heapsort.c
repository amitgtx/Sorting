#include <stdio.h>


int c=0;

/* Function to swap two numbers in an array */
void swap(int arr[], int i, int j)
{
	c++;
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp; 
} 


/* Function to swap largest element in heap */        
void maxheap(int arr[], int i,int N)
{ 
	int left = 2*i+1 ;
	int right = 2*i + 2;
	int max = i;
	if (left <= N && arr[left] > arr[i])
		max = left;
	if (right <= N && arr[right] > arr[max])        
		max = right;

	if (max != i)
	{
		swap(arr, i, max);
		maxheap(arr, max,N);
	}
} 


/* Function to build a heap */   
void heapify(int arr[],int N)
{
	int i;
	for (i = N/2; i >= 0; i--)
		maxheap(arr, i,N);        
}

/* Sort Function */
void sort(int arr[],int N)
{       
	heapify(arr,N);
	int i;        
	for (i = N; i > 0; i--)
	{
		swap(arr,0, i);
		N = N-1;
		maxheap(arr, 0,N);
	}
}     









main()
{
	int n;
	scanf("%d",&n);
	int A[n];

	int j=n,i;
	
	for(i=0;i<n;i++)
		scanf("%d",&A[i]);


	sort(A,n);


	for(i=0;i<n;i++)
		printf("%d\t",A[i]);

	printf("\n");
}

