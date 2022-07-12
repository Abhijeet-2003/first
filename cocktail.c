#include <stdio.h>
#include <stdlib.h>

void multiply(int m,int n,int (*arr1)[n],int a,int b,int (*arr2)[b],int (*ans)[b])
{
    int i=0,j=0,k=0;
    while(i<m)
    {
        j=0;
        while(j<b)
        {
            k=0;(*(*(ans+i)+j))=0;
            while(k<n)
            {
                (*(*(ans+i)+j))=(*(*(ans+i)+j))+(*(*(arr1+i)+k))*(*(*(arr2+k)+j));k++;
            }
            j++;
        }
        i++;
    }
    return;
    
}
int main()
{
    FILE *f1=fopen("input.txt","r");
    FILE *f2=fopen("input2.txt","r");
    FILE *f3=fopen("answer.txt","w");
    if(f1==NULL||f2==NULL||f3==NULL)
    {
        printf("FILE not opened properly");
        return 0;
    }
    int m,n,a,b;
    fscanf(f1,"%d %d",&m,&n);
    fscanf(f2,"%d %d",&a,&b);
    if(n!=a)
    {
        printf("Matrix multiplication not possible");
        return 0;
    }
    int arr1[m][n];
    int arr2[a][b];
    int ans[m][b];

    int i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            fscanf(f1,"%d",(*(arr1+i)+j));
        }
    }
    for(i=0;i<a;i++)
    {
        for(j=0;j<b;j++)
        {
            fscanf(f2,"%d",(*(arr2+i)+j));
        }
    }
    
    multiply(m,n,arr1,a,b,arr2,ans);

    for(i=0;i<m;i++)
    {
        for(j=0;j<b;j++)
        {
            fprintf(f3,"%d ",*(*(ans+i)+j));
        }
        fprintf(f3,"\n");
    }

    fclose(f1);
    fclose(f2);
    fclose(f3);
    return 0;
}