#include<stdio.h>
	struct pair
{
	int key;
	int value;
};
void display(struct pair ht[],int n)
{
	int i;
	printf("\n key \t value \n");
	for(i=0;i<n;i++)
	{
		printf("%d \t %d \n",ht[i].key,ht[i].value);
	}
}
int main()
{
	int i;
	int n=10;
	int num;
	struct pair ht[n];
	int arr[10]={11,22,33,44,55,66,77,88,99,100};
	for(i=0;i<n;i++)
	{
		ht[arr[i]%10].key=arr[i]%10;
		ht[arr[i]%10].value=arr[i];
	}
	display(ht,n);
	return 0;
}
