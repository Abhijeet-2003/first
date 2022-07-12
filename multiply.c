#include <stdio.h>
#include <stdlib.h>
int p=0,q=0,r=0;

void multiply(int r1,int c1,int r2,int c2,int **m1,int **m2,int **res,int c)
{
    if(p<r1)
    {
        if(q<c2)
        {
            if(r<c1)
            {
                *(*(res+p)+q)=*(*(res+p)+q)+(*(*(m1+p)+r))*(*(*(m2+r)+q));
                r++;
                multiply(r1,c1,r2,c2,m1,m2,res,c);
            }
            r=0;
            q++;
            multiply(r1,c1,r2,c2,m1,m2,res,c);
        }
        q=0;
        p++;
        multiply(r1,c1,r2,c2,m1,m2,res,c);
    }
    return;
}


int main()
{
    FILE *f1=fopen("input1.txt","r");
    FILE *f2=fopen("input2.txt","r");
    FILE *f3=fopen("result.txt","w");

    if(f1==NULL||f2==NULL||f3==NULL)
    {
        printf("File did not open successfully");
        return 0;
    }
    int m,n,a,b,c;
    fscanf(f1,"%d %d",&m,&n);
    fscanf(f2,"%d %d",&a,&b);
    int m1[m][n];
    int m2[a][b];
    int i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            fscanf(f1,"%d",&m1[i][j]);
        }
    }
    for(i=0;i<a;i++)
    {
        for(j=0;j<b;j++)
        {
            fscanf(f2,"%d",&m2[i][j]);
        }
    }
    int res[m][b];
    for(i=0;i<m;i++)
    {
        for(j=0;j<b;j++)
        {
            res[i][j]=0;
        }
    }

    if(n!=a)
    {
        printf("matrix multiplication not possible");
        return 0;
    }
    else
    {
        multiply(m,n,a,b,m1,m2,res,c);
    }


    for(i=0;i<m;i++)
    {
        for(j=0;j<b;j++)
        {
            fprintf(f3,"%d ",res[i][j]);
        }
        fprintf(f3,"\n");
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);

    return 0;
}








