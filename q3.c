#include <stdio.h>

void repeat();
int c,b,x,q;
int Largest_element(int *p,int l)
{
    int a;
    a=*(p+l-1);
    if(l==1)
    {
        return a;
    }
    int b=Largest_element(p,l-1);
    return  a>b?a:b;
}

int gcd(int n1,int n2)
{
    int a;
    if(c==1)
    {
        b=1;
    }
    else
    {
        if(n1%c==0&&n2%c==0)
        {
            b=c;
        }
    }
    if(c==n1||c==n2)
    {
        a=b;return a;
    }
    c++;
    a=gcd(n1,n2);
    return a; 
}

int power(int n1,int n2)
{
    if(x<=n2)
    {
        q=q*n1;
        x++;
        q=power(n1,n2);
    }
    return q;
}


int main()
{
    int n,l;
    c=1,x=1,q=1;
    printf("Which case do you choose-Case ");
    scanf("%d",&n);
    if(n==1)
    {
            scanf("%d",&l);
            int arr[l];
            int i;
            for(i=0;i<l;i++)
            {
                scanf("%d",&arr[i]);
            }
            int lg=Largest_element(arr,l);
            printf("The largest element is %d",lg);
            repeat();
    }
        
    else if(n==2)
    {
            int n1,n2;
            scanf("%d %d",&n1,&n2);
            int n=gcd(n1,n2);
            printf("The GCD is %d",n);
            repeat();
    }

    else if(n==3)
    {
            int n1,n2;
            scanf("%d %d",&n1,&n2);
            int p=power(n1,n2);
            printf("The answer is %d",p);
            repeat();
    }

    else
    {
        printf("Give a valid input");
        main();
    }
    return 0;  
}
void repeat()
{
    int e;
    printf("\nIf you want to run again-enter 0, if you want to quit-enter anything");
    scanf("%d",&e);
    if(e==0)
    main();
    else
    return;
}



