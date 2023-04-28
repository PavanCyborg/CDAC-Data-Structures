/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *next;
}*head1=NULL,*head2=NULL;
void insertbeginningL1(int ele)
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->next=head1;
    head1=temp;
    temp->data=ele;
}
void insertbeginningL2(int ele)
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->next=head2;
    head2=temp;
    temp->data=ele;
}
void displayL1()
{
    if(head1!=NULL)
    {
        struct node *current;
        current=head1;
        while(current->next!=NULL)
        {
            printf("%d -> ",current->data);
            current=current->next;
        }
        printf("%d",current->data);
        printf("\n");
    }
    else
    {
        printf("List is empty...\n");
    }
}
void displayL2()
{
    if(head2!=NULL)
    {
        struct node *current;
        current=head2;
        while(current->next!=NULL)
        {
            printf("%d -> ",current->data);
            current=current->next;
        }
        printf("%d",current->data);
        printf("\n");
    }
    else
    {
        printf("List is empty...\n");
    }
}
void merge(struct node *head1,struct node *head2)
{
    struct node *current;
    if(head1!=NULL && head2 !=NULL)
    {
        current=head1;
        while(current->next!=NULL)
            current=current->next;
        current->next=head2;
        head2=NULL;
        displayL1();
    }
    else if(head2==NULL)
        displayL1();
    else if(head1==NULL)
        displayL2();
}
int main()
{
    int ch,ele;
    while(1)
    {
        ele=0;
        printf("Enter your choice:\n 1. Insert into list1\n 2. Insert into list2\n 3.display\n 4. Merge \n5. exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter the element you want to Insert:\n");
                    scanf("%d",&ele);
                    insertbeginningL1(ele);
            break;
            case 2: printf("Enter the element you want to insert into List2:\n");
                    scanf("%d",&ele);
                    insertbeginningL2(ele);
            break;
            case 3: printf("List 1 elements are:\n");
                    displayL1();
                    printf("List 2 elements are:\n");
                    displayL2();
            break;
            case 4:
                    printf("List after merging is:\n");
                    merge(head1,head2);
            break;
            
            case 5: exit(0);
            break;
            default: printf("Enter valid options...\n");
        }
    }
    return 0;
}
