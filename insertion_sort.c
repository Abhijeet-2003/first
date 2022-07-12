#include <stdio.h>


void sort(int *a)
{
    int i,j,temp;
    for(i=0;i<5;i++)
    {
        if(a[i]>a[i+1])
        {
            temp=a[i];
            a[i]=a[i+1];
            a[i+1]=temp;
            int c=i;
            while(c>0)
            {
                if(a[c]<a[c-1])
                {
                    temp=a[c];
                    a[c]=a[c-1];
                    a[c-1]=temp;c--;
                }
                else
                break;
            }
        }
    }
}
int main()
{
   int arr[6]={4,9,3,7,8,7};
   sort(arr);
   int i;
   for(i=0;i<6;i++)
   {
      printf("%d ",arr[i]);
   }
   return 0;
}