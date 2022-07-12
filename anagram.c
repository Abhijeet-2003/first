#include <stdio.h>

void sort(char ch[])
{
    int i,j;
    for(i=0;ch[i+1]!='\0';i++)
    {
        for(j=0;ch[j+1]!='\0';j++)
        {
            if(ch[j]>ch[j+1])
            {
                char temp;
                temp=ch[j];
                ch[j]=ch[j+1];
                ch[j+1]=temp;
            }
        }
    }
    return;
}
int comp(char s1[],char s2[])
{
    int i=0;
    while(1)
    {
        if(s1[i]=='\0'&&s2[i]=='\0')
        break;
        if((s1[i]=='\0'&&s2[i]!='\0')||(s2[i]=='\0'&&s1[i]!='\0'))
        return 1;
        if(s1[i]!=s2[i])
        return 1;
        i++;
    }
    return 0;
}
int main()
{
    int n;
    scanf("%d",&n);
    char ch[n][100];
    char w[100];
    int i;
    scanf("%s",w);
    for(i=0;i<n;i++)
    {
        scanf("%s",ch[i]);
    }
    for(i=0;i<n;i++)
    {
        sort(ch[i]);
    }
    sort(w);

    for(i=0;i<n;i++)
    {
        if(comp(ch[i],w)==0)
        {
            printf("Yes");
            return 0;
        }
    }
    printf("No");
    return 0;
}