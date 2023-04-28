#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next; //structure Pointer pointing to itself.
}*head;
void insert_beginning(int ele)
{
    struct node *temp; //create a "Temp" Veriable to access Linked list.
    temp=(struct node *)malloc(sizeof(struct node));
    temp->next=head;
    head=temp;
    temp->data=ele;
}
int delete_specific(int ele)
{
    struct node *current,*temp;
    if(head!=NULL)
    {
        current=head;
        if(current->data==ele)
        {
            current=current->next;
            free(current);
        }
        else
        {
            while(current->next!=NULL && current->next->data!=ele)
            {
                current=current->next;
            }
            if(current->next!=NULL)
            {
                temp=current->next;
                current->next=temp->next;
                free(temp);
            }
            else
            {
                printf("Element not found.\n");
                return 1;
            }
        }
    }
    else
        printf("List is empty...\n");
    return ele;
}
void traverse_forward()
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
    int ch,n,x;
    while(1)
    {
        printf("1.Enter into list\n");
        printf("2.Delete from list\n");
        printf("3.Display\n 4.Exit\n");
        printf("Enter the operation you wanted to perform:\n");
        scanf("%d",&ch);
        
        switch(ch)
        {
            case 1: printf("Enter the value you want to insert:\n");
                    scanf("%d",&n);
                    insert_beginning(n);
                    break;
            case 2: printf("Enter which no you want to remove from list:\n");
                    scanf("%d",&n);
                    x=delete_specific(n);
                    if(x!=1)
                        insert_beginning(x);
                    break;
            case 3: printf("The elements of list are:\n");
                    traverse_forward();
                    break;
            case 4: exit(0);
                    break;
            default: printf("Invalid choice\n");        
        }
    }
    return 0;
}
