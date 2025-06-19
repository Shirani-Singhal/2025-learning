#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
main()
{
	struct node *head=NULL;  
	head=(struct node *)malloc(sizeof(struct node));
	head->data=10;
	head->link=NULL;
	
	struct node *n1=NULL;
	n1=(struct node *)malloc(sizeof(struct node));
	n1->data=20;
	n1->link=NULL;
	head->link=n1;
	
	struct node *n2=NULL;
	n2=(struct node *)malloc(sizeof(struct node));
	n2->data=30;
	n2->link=NULL;
	n1->link=n2;
	
	printf("data=%d",head->data);
	printf("add =%d",head->link);
	printf("\n");
	printf("data=%d",n1->data);
	printf("add =%d",n1->link);
	printf("\n");
	printf("data=%d",n2->data);
	printf("add =%d",n2->link);

	
}
