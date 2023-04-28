#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next; //structure Pointer pointing to itself.
}*head;
void insert_beginning(int ele)//push
{
    struct node *temp; //create a "Temp" Variable to access Linked list.
    temp=(struct node *)malloc(sizeof(struct node));
    temp->next=head;
    head=temp;
    temp->data=ele;
}
int delete_beginning()//pop
{
    int x=-1;
    struct node *temp;
    if(head!=NULL)
    {
        temp=head;
        x=temp->data;
        head=temp->next;
        return x;
    }
    else 
    {
        return -1;
    }
    free(temp);
}
int peep()
{   
    struct node *temp;
    if(head !=NULL)
    {
        temp=head;
        return temp->data;
    }
    else
        return -1;
}
void traverse_forward() //Display Funcion
{
    if(head !=NULL)
    {
        struct node * current;
        current=head;
        while(current->next!=NULL)
        {
            printf("%d -> ",current->data);
            current=current->next;
        }
        printf("%d",current->data);
    }
    else
    {
        printf("There are no elements in list.\n");
    }
}
int main()
{
    int n,ch,i=1,size;
    printf("Enter the stack size:\n");
    scanf("%d",&size);
    while(1)
    {   
        n=0;
        printf("Enter the choice of Operations:\n");
        printf("1.Push | 2.pop | 3.peep | 4.Display | 5.Exit \n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: if(i<=size)
                    {
                        printf("Enter an element to enter into stack:\n");
                        scanf("%d",&n);
                        insert_beginning(n);
                        i++;
                    }
                    else 
                        printf("Stack overflow!!!");
                    break;
            case 2: n=delete_beginning();
                    printf("%d is deleted\n",n);
                    i--;
                    if(n==-1)
                    {
                        i=0;
                        printf("Stack underflow!...");
                    }
                    break;
            case 3: n=peep();
                    if(n==-1)
                    {
                        printf("stack is Empty");
                        i=0;
                    }
                    else
                        printf("Top Element of stack is %d",n);
                    break;
            case 4: traverse_forward();
                    break;
            case 5: exit(0);
                    break;
            default:printf("Enter valid Options\n");
        }
    }
    return 0;
}