#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
char inputstr[30],Outputstr[30],a,b;
int n,size,ch,len,i,z;
struct stackds
{
    int size;
    char *stack;
    int TOS;
}s;
void getsize(int n)
{
    s.TOS=-1;
    s.size=n;
    s.stack=(char *)malloc(sizeof(int)*n);
}
bool isempty()
{
    return (s.TOS==-1);
}
bool isfull()
{
    return (s.TOS==s.size-1);
}
void Push(char ele)
{
    if(!isfull())
    {
        s.TOS++;
        s.stack[s.TOS]=ele;
    }
    else
        puts("stack Overflow");
}
int pop()
{
    int x=-1;
    if(!isempty())
    {
        x=s.stack[s.TOS];
        s.TOS--;
        return x;
    }
    else
        return -1;
}
char peep()
{
    if(!isempty())
    {
        return s.stack[s.TOS];
    }
    else 
        return '\0';
}
void Display()
{
    int i=0;
    if(!isempty())
    {
        puts("Elements of array are: \n");
        for(i=0;i<s.TOS;i++)
            printf("%c",s.stack[i]);
    }
    else
        puts("Stack is already empty. \n");
}
int OpPrecedence(char ch)
{
    switch(ch)
    {
        case '*':
        case '/':return 2;
        case '+':
        case '-':return 1;
        case '(':
        case '{':
        case '[':return 0;
        default: return -1;
    }
}
void infixtoPostfix()
{
    char ch1;
    int j=0;
    printf("Enter the Input of Infix String : \n");
    scanf("%s",inputstr);
    len=strlen(inputstr);
    for(i=0;i<len;i++)
    {   
        ch=inputstr[i];
        switch(ch)
        {
            case '(':
            case '[':
            case '{':
                        Push(ch);
                        break;
            case '+':
            case '-':
            case '*':
            case '/':   while(!isempty() && OpPrecedence(ch)<=OpPrecedence(peep()))
                        {
                            Outputstr[j++]=pop();
                        }
                        Push(ch);
                        break;
            case ')':
            case ']':
            case '}':   while(peep()!='(' || peep()!='[' || peep()!='{')
                        {
                            Outputstr[j++]=pop();
                        }
                        ch1=pop();
                        break;
            default: Outputstr[j++]=ch;
                        
        }
    }
    while(!isempty())
    {
        Outputstr[j]=pop();
        j++;
    }
    Outputstr[i]='\0';
    puts(Outputstr);
}
void balancingExp()
{
    printf("Balancing Expressions\n");
    printf("Enter an Expression to balance:\n");
    scanf("%s",inputstr);
    len=strlen(inputstr);
    for(i=0;i<len;i++)
    {
        switch(a)
        {
            case '(':
            case '{':
            case '[':   Push(a);
                        break;
            case ')':
            case '}':
            case ']':   b=peep();
                        if((b=='{' && a=='}') || (b=='(' && a==')') || (b=='[' && a==']'))
                        {
                            z=pop();
                            if(z!=-1)
                                printf("%d is popped \n",z);
                            else
                                printf("stack is empty \n");
                        }
                        else
                        {
                            n=1;
                            break;
                        }
        }

    }
    if(n==1)
    {
        printf("Not Balanced Expression.\n");
    }
    else
    {
        if(isempty() && i==len)
            printf("Balanced Expression.\n");
        else
            printf("Unbalanced Expression.\n");
    }
}
int main()
{
    //int n,size,ch,len,i,z;
    puts("Enter the size of stack:\n");
    scanf("%d",&size);
    getsize(size);
    while(1)
    {
        printf("Enter your choice: \n 1.Balancing Expressions \n 2.Infix to Post-fix Conversion\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: balancingExp();
            break;
            case 2: infixtoPostfix();
            break;
            case 3: exit(0);
            break;
        }

    }
    return 0;
}
