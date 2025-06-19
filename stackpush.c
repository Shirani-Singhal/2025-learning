#include<stdio.h>
int stack[20];
int top=-1;
int size=20;
void push(int value)
{
	if(top == size-1)
	{
		printf('stack overflow');
	}
	else
	{
		top++;
		stack[top]=value;
		printf("%d pushed into stack\n");
	}
}
void display()
{
	
	if(top==-1)
	{
		printf("stack empty");
	}
	else
	{
		int i;
		printf("stack elements:\n");
		for( i=top;i>=0;i--)
		{
			printf("%d\n",stack[i]);
		}
	}
}
void pop()
{
	if(top==-1)
	{
		printf("stack empty");
	}
	else
	{
		
		int i;
		printf("stack elements:\n");
		for( i=top;i>=0;i--)
		{
			printf("%d\n",stack[i]);
		}
	}
}
int main()
{
	push(10);
		push(20);
			push(30);
			display();
				push(40);
				push(50);
				display();
				push(90);
				push(100);
				display();
}
