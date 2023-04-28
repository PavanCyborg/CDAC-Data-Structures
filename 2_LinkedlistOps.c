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
void insert_at_end(int ele)
{
    struct node *temp,*current;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=ele;
    temp->next=NULL;
    if(head==NULL)
        head=temp;
    else
    {
        current=head;
        while(current->next!=NULL)
        {
            current=current->next;
        }
        current->next=temp;
    }
}
void insert_after(int selected_ele,int ele)
{
    struct node *temp,*current;
    if(head !=NULL)
    {
        current=head;
        while(current!=NULL && current->data!=selected_ele)
            current=current->next;
        if(current!=NULL)
        {
            temp=(struct node *)malloc(sizeof(struct node));
            temp->data=ele;
            temp->next=current->next;
            current->next=temp;
        }
        else
        {
            printf("Element not found\n");
        }
    }
    else
        printf("List is empty\n");
}
void insert_before(int selected_ele,int ele)
{
    struct node *temp,*current;
    if(head !=NULL)
    {
        current=head;
        if(current->data==selected_ele)   //If we want to add at 1st location after Head.
        {
            temp=(struct node *)malloc(sizeof(struct node));
            temp->data=ele;
            temp->next=current;
            current=temp;
        }
        else
        {
            while(current->next!=NULL && current->next->data!=selected_ele) //If we want to add new element at nth location
            {
                current=current->next;
            }
            if(current->next!=NULL)
            {
                temp=(struct node *)malloc(sizeof(struct node));
                temp->data=ele;
                temp->next=current->next;
                current->next=temp;
            }
            else
                printf("Element not found.\n");
        }
    }
    else
        printf("List is Empty...\n");

}
int delete_beginning()
{
    int x=-1;
    struct node *temp;
    if(head!=NULL)
    {
        temp=head;
        x=temp->data;
        head=temp->next;
    }
    free(temp);
    return x;
}
int delete_End()
{
    int x=-1;
    struct node *temp,*current;
    if(head!=NULL)
    {
        temp=head;
        x=temp->data;
        if(temp->next!=NULL)
        {
            current=head;
            while(current->next->next!=NULL)
            {
                current=current->next;
            }
            temp=current->next;
            x=temp->data;
            current->next=NULL;
        }
        free(temp);
    }
    return x;
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
                printf("Element not found.\n");
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
void traverse_reverse(struct node *current)
{
    if(current==NULL)
    {
        return;
    }
    traverse_reverse(current->next);
    printf("%d <- ",current->data);
}
void reverse()
{
    int n=0;
    struct node *prev,*nextptr,*current;
    if(head!=NULL)
    {
        nextptr=NULL;
        prev=NULL;
        current=head;
        
        while(current!=NULL)
        {
            nextptr=current->next;
            current->next=prev; //previous initailly is null. making 1st node as last node. 
            prev=current;
            current=nextptr;
        }
        head=prev;
    }
    //traverse_forward();
}
int search(int n)
{
    struct node *current;
    if(head!=NULL)
    {
        current=head;
        while(current->next!=NULL)
        {
            if(n==current->data)
                return 1;
            break;
        }
    }
    else
    {
        printf("\nList is Empty\n");
    }
}
int main()
{
    int z,ch,n,v;
    head=NULL;
    while(1)
    {
        n=0;
        z=0;   
        printf("Enter your choice of Operation:\n");
        printf("1.Insert at beginning\n 2. Insert at Ending\n"); 
        printf("3.Insert before any specified Element \n 4.Insert after any element\n");
        printf("5.Delete an Element in beginning \n 6.Delete specific Element \n7.Delete an element from Ending\n");
        printf("8.Display list in Forward Direction\n");
        printf("9.Display list in Reverse Direction\n");
        printf("10.Reverse of List \n 11.Search for an Element\n 12.Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter an element you want to Enter at the beginning:\n");
                scanf("%d",&n);
                insert_beginning(n);
                traverse_forward();
            break;
            case 2:printf("Enter an element you want to enter at the ending:\n");
                scanf("%d",&n);
                insert_at_end(n);
                traverse_forward();
            break;
            case 3:printf("Enter an element you want to enter:\n");
                scanf("%d",&n);
                v=0;
                printf("Before which no you want to enter:\n");
                traverse_forward();
                scanf("%d",&v);
                insert_before(v,n);
            break;
            case 4:printf("Enter an element you want to enter:\n");
                scanf("%d",&n);
                v=0;
                printf("After which no you want to enter:\n");
                traverse_forward();
                scanf("%d",&v);
                insert_after(v,n);
            break;
            case 5:printf("Deleting beginning element...\n");
                z=delete_beginning();
                if(z!=-1)
                    printf("List is empty.\n");
                else
                    printf("Deleted element is %d\n",z);
                traverse_forward();
            break;
            case 6:printf("Enter any number you want to delete from list\n");
                scanf("%d",&n);
                printf("%d is deleted from list\n",delete_specific(n));
                break;
            case 7:printf("Deleting Ending element...\n");
                z=delete_End();
                if(z!=-1)
                    printf("List is empty.\n");
                else
                    printf("Deleted element is %d\n",z);
                traverse_forward();
            break;
            case 8:printf("List in forward direction is :\n");
                traverse_forward();
            break;
            case 9:printf("List in reverse Direction is :\n");
                traverse_reverse(head);
            break;
            case 10:reverse();
            break;
            case 11:printf("Enter any no you want to search in list:\n");
                scanf("%d",&n);
                if(search(n)==1)
                    printf("Element is found in list\n");
                else
                    printf("Element not found in list\n");
            break;
            case 12:exit(0);
            break;
            default:printf("Enter the valid choice...\n");
        }
    }
    return 0;
}
