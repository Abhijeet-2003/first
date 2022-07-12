#include <stdio.h>
#include <string.h>

int comp(char s1[],char s2[])
{
    int i=0;
    while(s1[i]!='\0')
    {
        if(s2[i]=='\0')
        return s1[i]-s2[i];
        else if(s1[i]!=s2[i])
        return s1[i]-s2[i];
        i++;
    }
    return 0;
}
void swap(char s1[],char s2[])
{
    char temp[100];
    int i=0;
    while(s1[i]!='\0')
    {
        temp[i]=s1[i];i++;
    }
    temp[i]='\0';
    i=0;
    while(s2[i]!='\0')
    {
        s1[i]=s2[i];i++;
    }
    s1[i]='\0';
    i=0;
    while(temp[i]!='\0')
    {
        s2[i]=temp[i];i++;
    }
    s2[i]='\0';
    return;
}
int main()
{
    int n;
    scanf("%d",&n);
    char ch[n][100];
    int i,j;
    for(i=0;i<n;i++)
    {
        scanf("%s",ch[i]);
    }
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1;j++)
        {
            int k=comp(ch[j],ch[j+1]);
            if(k>0)
            {
                char s[100];
                swap(ch[j],ch[j+1]);
            }
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%s ",ch[i]);
    }
    return 0;
}
