#include<stdio.h>
#define max 10
int a[max];
int top=-1;
void push(int data)
{
    if(top==max-1)
    {
        printf("The Stack overflows...");
    }
    else
    {
        top=top+1;
        a[top]=data;
    }
}
void pop()
{
    if(top==-1)
    {
        printf("The stack underflows...");
    }
    else
    {
        top-=1;
    }
}
void display()
{
    for(int i=top;i>=0;i--)
    {
        printf("%d\t",a[i]);
    }printf("\n");
}
void main()
{
    int data;
    int ch,e;
    while(e!=4)
    {
        printf("1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter the data:");
                scanf("%d",&data);
                push(data);
                break;
            case 2:
                printf("The data is popped...\n");
                pop();
                break;
            case 3:
                printf("Display\n");
                display();
                break;
            case 4:
                printf("Exiting....\n");
                e=4;
                break;
            default:
            printf("Invalid choice...\n");
        }
    }
}