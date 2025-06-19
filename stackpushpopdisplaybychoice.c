#include<stdio.h>
#define size 5
int stack[size];
int top=-1;
void push(int value)
{
	if(top == size-1)
	{
		printf("stack overflow");
	}
	else
	{
		printf("pushed into stack : %d \n",value);
		stack[top]=value;
		top++;
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
	if(top ==-1)
	{
		printf("stack underflow");
	}
	else
	printf("%dpopped from stack" ,stack[top]);
}
 int main(){
            int choice,num;
                     printf("1 push \n");
                     printf("2 pop \n");
                      printf("3 display \n");
                     printf("4 exit \n");
                     while(1)
                     {
                     	printf(" Enter your choice:");
                     scanf("%d",&choice);
           
                     switch (choice)
					 {
                            case 1:
                            printf("Enter number:");
                            scanf("%d",&num);
                            push(num);
                            break;
                            case 2:
                            pop();
                            break;
                            case 3:
                            display();
                            break;
                            case 4:
                            printf("exit program");
                            return 0;
                            default:
                            	{
                            		printf("invalid choice");
								}
                    }}
                            }
