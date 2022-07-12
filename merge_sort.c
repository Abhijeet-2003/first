#include <stdio.h>

void merge(int *a,int b,int mid,int e)
{
    int ptr1=b,ptr2=mid+1,temp[6],i=0;
    while(ptr1<=mid||ptr2<=e)
    {
        if(ptr1<=mid&&ptr2<=e)
        {
            if(a[ptr1]<=a[ptr2])
            {
                temp[i]=a[ptr1];
                i++;ptr1++;
            }
            else if(a[ptr1]>=a[ptr2])
            {
                temp[i]=a[ptr2];
                ptr2++;i++;
            }
        }
        else if(ptr1>mid&&ptr2<=e)
        {
            temp[i]=a[ptr2];
            ptr2++;i++;
        }
        else if(ptr1<=mid&&ptr2>e)
        {
            temp[i]=a[ptr1];
            ptr1++;i++;
        }
    }
    int j;
    for(j=b;j<=e;j++)
    {
        a[j]=temp[j-b];
    }
}
void sort(int *a,int b,int e)
{
    if(b==e)
    return;
    else
    {
        int mid=(b+e)/2;
        sort(a,mid+1,e);
        sort(a,b,mid);
        merge(a,b,mid,e);
    }
}
int main()
{
   int arr[6]={1,3,3,8,5,1};
   sort(arr,0,5);
   int i;
   for(i=0;i<6;i++)
   {
      printf("%d ",arr[i]);
   }
   return 0;
}




