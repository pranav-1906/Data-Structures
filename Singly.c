#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *head=NULL,*temp=NULL,*new,*curr;
int n;
void display();
void insert();
void delete();
void search();
void main()
{
    int n,i=0;
    printf("Enter no of nodes:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        new=(struct node*)malloc(sizeof(struct node));
        printf("Enter data %d:",i+1);
        scanf("%d",&new->data);
        if(head==NULL)
        {
            new->next=NULL;
            head=new;
            temp=head;
        }
        else
        {
            temp->next=new;
            new->next=NULL;
            temp=new;
        }
    }
    display();
    insert();
    delete();
    search();
    }
void display()
{
    temp=head;
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
void insert()
{
    int pos,i,n;
    new=(struct node*)malloc(sizeof(struct node));
    printf("Enter data to insert:");
    scanf("%d",&new->data);
    printf("Enter position to insert:");
    scanf("%d",&pos);
    temp=head;
    if(pos==1)
    {
        new->next=head;
        head=new;
    }
    else if(pos>1 && pos<=n+1)
    {
        for(i=1;i<pos-1;i++)
        {
            temp=temp->next;
        }
        new->next=temp->next;
        temp->next=new;
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=new;
        new->next=NULL;
    }
    display();
}
void delete()
{
    if(head==NULL)
    {
        printf("List is empty");
    }
    else
    {
        int pos;
        printf("Enter position to delete:");
        scanf("%d",&pos);
        temp=head;
        if(pos==1)
        {
            head=temp->next;
        }
        else
        {
            for(int i=1;i<pos-1;i++)
            {
                temp=temp->next;
            }
            struct node *prev=temp;
            temp=temp->next;
            prev->next=temp->next;
        }
        display();
    }
}

void search()
{
    int val,flag=0;
    printf("Enter element to be searched:");
    scanf("%d",&val);
    struct node *temp=head;
    while(temp!=NULL)
    {
        if(temp->data==val)
        {
            flag=1;
            break;
        }
        temp=temp->next;
    }
    if(flag==1)
    {
        printf("%d is found",val);
    }
    else
    {
        printf("%d is not found",val);
    }
}