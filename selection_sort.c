#include <stdio.h>
#include <stdlib.h>

void sort(int *a)
{
   int i,j,k,temp,min;
   for(i=0;i<5;i++)
   {
      min=a[i];
      for(j=i;j<6;j++)
      {
         if(a[j]<=min)
         {
            k=j;
            min=a[j];
         }
      }
      temp=a[i];
      a[i]=a[k];
      a[k]=temp;
   }
}
int main()
{
   int arr[6]={1,6,3,5,9,8};
   sort(arr);
   int i;
   for(i=0;i<6;i++)
   {
      printf("%d ",arr[i]);
   }
   return 0;
}
