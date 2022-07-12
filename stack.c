#include <stdio.h>
#include <stdlib.h>
#define n 7
struct stack
{
    int arr[n];
    int top;
}s;

int push(int a)
{
    if(s.top==n-1)
    {
        printf("stack overflow");
        return 0;
    }
    else
    {
        (s.top)++;
        s.arr[s.top]=a;
        return 1;
    }
}
void sort()
{
    int i,j,temp;
    for(i=1;i<=s.top;i++)
    {
        for(j=0;j<s.top;j++)
        {
            if(s.arr[j]<s.arr[j+1])
            {
                temp=s.arr[j];
                s.arr[j]=s.arr[j+1];
                s.arr[j+1]=temp;
            }
        }
    }
}
int main()
{
    s.top=-1;
    while(1)
    {
        printf("Enter the element to be pushed...if no element is to be pushed enter 0\n");
        int c;
        scanf("%d",&c);
        if(c==0)
        break;
        int a;
        scanf("%d",&a);
        int o=push(a);
        if(o==0)
        break;
    }
    sort();
    int i;
    for(i=0;i<=s.top;i++)
    {
        printf("%d ",s.arr[i]);
    }
    return 0;
}



