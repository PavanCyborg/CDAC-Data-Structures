#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50
struct stackds
{
    char *stack;
    int size;
    int TOS;
}s;
void getsize(int n)
{
    s.size=n;
    s.stack=(char *)malloc(n*sizeof(int));
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
void push(int ele)
{
    if(!isfull())
    {
        s.TOS++;
        s.stack[s.TOS]=ele;
    }
}
char peep()
{
    char x='\0';
    if(!isempty())
    {
        x=s.stack[s.TOS];
    }
    else
    {
        printf("\n Stack is empty\n");
        return x;
    }
}
int pop()
{
    int x=-1;
    if(!isempty())
    {
        x=s.stack[s.TOS];
        s.TOS--;
    }
    else
    {
        printf("\n stack is empty\n");
        return x;
    }
}
void Display()
{
    int i=0;
    if(!isempty())
    {
        puts("Contents of stack are:\n");
        for(i=0;i<s.TOS;i++)
        {
            printf("\n%c",s.stack[i]);
        }
    }
    else
    {
        printf("\n stack is empty\n");
    }
}
int main()
{
    unsigned short size,len,flag=0,i;
    char ch,pch,pop_char;
    printf("\n Enter the size of stack \n");
    scanf("%hd",&size);
    getsize(size);
    char in_str[MAX];
    printf("\nEnter the arithmetic Expression : \n");
    scanf("%s",in_str);
    len=strlen(in_str);
    for(i=0;i<len;i++)
    {
        ch=in_str[i];
        switch(ch)
        {
            case '{':
            case '(':
            case '[':
                        push(ch);
                        break;
            case ')':
            case '}':
            case ']':
                        pch=peep();
                        if((pch=='('&& ch==')')|| (pch=='{' && ch=='}')||(pch=='[' && ch==']'))
                            pop_char=pop();
                        else
                        {
                            flag=1;
                            break;
                        }
        }
    }
    if(flag==1)
        printf("\n not balanced.\n");
    else
    {
        if(isempty() && i==len)
            printf("\n Expression balanced\n");
        else
            printf("\n Expression not balanced \n");
    }
return 0;
}