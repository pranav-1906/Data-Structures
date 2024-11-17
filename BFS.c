#include<stdio.h>
int a[20][20], q[20], visited[20],n, front=-1, rear=-1;

void bfs(int v)
{
    int i;
    for(i=0;i<n;i++)
    {
      if(a[v][i]!=0 && visited[i]==0)
        {
            rear=rear+1;
            q[rear]=i;
            visited[i]=1;
            printf("%d\t", i);
        }
    }
    front=front+1;
    if(front<=rear)
    {
        bfs(q[front]);
    }
}
int main() 
{
    int i,j, v;
    printf("enter the no of vertices:");
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        visited[i]=0;
    }
    printf("\nEnter graph data in matrix form:");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("\nEnter the starting vertex:");
    scanf("%d", &v);
    front=rear=0;
    q[rear]=v;
    printf("\nBFS traversal is:");
    visited[v]=1;
    printf("%d\t", v);
    bfs(v);
    if(rear!=n-1)
    {
        printf("bfs is not possible");
    }
}
