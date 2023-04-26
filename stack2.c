#include<stdio.h>
#include<stdlib.h>
struct Stackds
{
	int *stack;
	int size;
	int TOS;
}s;
void getsize(int n)
{
	s.size=n;
	s.stack=(int *)malloc(sizeof(int)*n);
	s.TOS=-1;
}
int isempty()
{
	return (s.TOS==-1);
}
int isfull()
{
	return (s.TOS==s.size-1);
}
void push(int n)
{
	if(!isfull())
	{
		s.TOS++;
		s.stack[s.TOS]=n;
	}
}
int peep()
{
	return (s.stack[s.TOS]);
}
int pop()
{
	if(!isempty())
	{
		int x=-1;
		x=s.stack[s.TOS];
		s.TOS--;
		return x;
	}
	else
	{
		return -1;
	}
}
void Display()
{
	int i=s.TOS;
	while(i>=0)
	{
		printf("%d\n",s.stack[i]);
		i--;
	}
}
int main()
{
	int n,ch,z;
	int ele;
	printf("Enter the size of stack you want to create:\n");
	scanf("%d",&n);
	getsize(n);
	while(1)
	{
		printf("Enter the operation to perform:\n 1.Push\n 2.POP \n 3.PeeP\n 4.Display\n 5.Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: if(!isfull())
					{
					printf("Enter an element into stack: \n");
					scanf("%d",&ele);
					push(ele);
					printf("%d is pushed into the stack.\n",ele);
					}
					else
					{
						printf("Stack Overflow... Stack is already Full... \n");
					}
					printf("Elements in stack are :\n");
					Display();
			break;
			case 2: z=pop();
					if(z==-1)
					{
						printf("Stack Underflow!!!!...\n");
					}
					else
						printf("%d is removed\n",z);
					printf("Elements remaining in stack are :\n");
					Display();
			break;
			case 3: printf("Top element of stack is :%d\n",peep());
			break;
			case 4: Display();		
			break;
			case 5: exit(0);
			default: printf("Enter valid option...\n");	
		}
	}
	return 0;
}