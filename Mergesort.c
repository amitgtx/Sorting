#include <stdio.h>

void merge(int*,int ,int ,int ,int);

void sort(int A[],int lo,int hi)
{
	if(hi>lo)
	{
		int mid=(lo+hi)/2;
		sort(A,lo,mid);
		sort(A,mid+1,hi);
		merge(A,lo,mid,mid+1,hi);
	}
}


void merge(int A[],int l1,int r1,int l2,int r2)
{
	int B[r2-l1+1],i=0,x=l1,y=l2;

	while(x<=r1&&y<=r2)
	{
		if(A[x]<A[y])B[i++]=A[x++];
		else
			B[i++]=A[y++];
	}

	while(x<=r1)B[i++]=A[x++];

	while(y<=r2)B[i++]=A[y++];

	for(i=l1;i<=r2;i++)
		A[i]=B[i-l1];

}


int main()
{
	int n,i;
	printf("Enter no. of elements\n");
	scanf("%d",&n);
	int A[n];

	for(i=0;i<n;i++)
		scanf("%d",(A+i));	


	sort(A,0,n-1);

	for(i=0;i<n;i++)
		printf("%d  ",A[i]);

	printf("\n");
}

