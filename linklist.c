#include <stdio.h>
#include <stdlib.h>
int s=0;
struct node
{
    int data;
    struct node *ptr;
};
void display(struct node **t)
{
    struct node *p;
    if((*t)==NULL)
    {
        printf("list is empty");
        return;
    }
    for(p=*t;p!=NULL;p=p->ptr)
    {
        printf("%d ",p->data);
    }
    return;
}
void create_node(struct node **t)
{
    
    while(1)
    {
        printf("If you want to create node enter 1\n");
        int c;
        scanf("%d",&c);
        if(c==1)
        {
            s++;
            if(*t==NULL)
            {
                *t=(struct node *)malloc(sizeof(struct node));
                printf("Enter your data- ");
                int n;
                scanf("%d",&n);
                (*t)->data=n;
                (*t)->ptr=NULL;
            }
            else
            {
                struct node *a;
                for(a=*t;a->ptr!=NULL;a=a->ptr)
                {}
                a->ptr=(struct node *)malloc(sizeof(struct node));
                printf("Enter your data- ");
                int n;
                scanf("%d",&n);
                a->ptr->data=n;
                a->ptr->ptr=NULL;
            }
        }
        else
        {
            break;
        }
    }
    return;
}
void insert_beg(struct node **t)
{
    int n;
    printf("Enter new number at beginning- ");
    scanf("%d",&n);
    struct node *beg=(struct node *)malloc(sizeof(struct node));
    beg->data=n;
    beg->ptr=*t;
    *t=beg;return;
}
void insert_end(struct node **t)
{
    struct node *end=(struct node *)malloc(sizeof(struct node));
    if((*t)==NULL)
    {
        (*t)=end;return;
    }
    struct node *p=*t;
    while(p->ptr!=NULL)
    {
        p=p->ptr;
    }
    int n;
    printf("Enter new number at end- ");
    scanf("%d",&n);
    end->data=n;
    end->ptr=NULL;
    p->ptr=end;return;
}
void delete_beg(struct node **t)
{
    if((*t)==NULL)
    {
        printf("LIst is empty");
        return;
    }
    struct node *p=(*t);
    *t=(*t)->ptr;
    p->ptr=NULL;
    free(p);return;
}
void delete_end(struct node **t)
{
    if(*t==NULL)
    {
        printf("List is empty");
        return;
    }
    else if((*t)->ptr==NULL)
    {
        delete_beg(t);
        return;
    }
    else
    {
        struct node *p=*t;
        while(p->ptr->ptr!=NULL)
        {
            p=p->ptr;
        }
        free(p->ptr);
        p->ptr=NULL;return;
    }
}
void sort(struct node **t)
{
    struct node *p,*q,*temp1,*temp2;
    if((*t)==NULL||(*t)->ptr==NULL)
    {
    }
    else if((*t)->ptr->ptr==NULL)
    {   
        if(((*t)->data)>((*t)->ptr->data))
        {
            temp1=(*t)->ptr;
            (*t)->ptr=NULL;
            temp1->ptr=(*t);
            (*t)=temp1;
        }
    }
    else
    {
        int i;
        for(i=0;i<s-1;i++)
        {
            printf("heyy");
            for(q=*t;q->ptr->ptr!=NULL;q=q->ptr)
            {
                if(q==*t)
                {
                    if((q->data)>(q->ptr->data))
                    {
                        temp1=(*t)->ptr->ptr;temp2=(*t)->ptr;
                        (*t)->ptr->ptr=*t;
                        (*t)->ptr=temp1;
                        *t=temp2;
                    }
                }
                if((q->ptr->data)>(q->ptr->ptr->data))
                {
                    temp1=q->ptr;
                    temp2=q->ptr->ptr;
                    q->ptr->ptr=q->ptr->ptr->ptr;
                    temp2->ptr=q->ptr;
                    q->ptr=temp2;
                }
            }
        }

    }
    return;
}
void del_val(struct node **t,int val)
{
    struct node *p=*t,*s=NULL;
    if((*t)==NULL)
    return;
    else if((*t)->ptr==NULL)
    {
        if((*t)->data==val)
        {
            p=*t;
            *t=NULL;
            free(p);return;
        }
        else
        return;
    }
    else if((*t)->data==val)
    {
        p=*t;
        *t=(*t)->ptr;
        free(p);return;
    }
    else
    {
        while(p->ptr!=NULL)
        {
            if(p->ptr->data==val)
            {
                s=p;
                break;
            }
            else
            p=p->ptr;
        }
        if(s==NULL)
        {
            return;
        }
        else
        {
            s=s->ptr;
            p->ptr=p->ptr->ptr;
            s->ptr=NULL;
            free(s);
            return;
        }
    }
}
int main()
{
    struct node *head=NULL;
    int k,val,c=0;
    create_node(&head);
    do
    {
    printf("\nif you want to sort, enter 0\nif you want to insert at end, enter 1\nif you want to insert at beginning, enter 2\nif you want to delete beginning, enter 3\nif you want to delete end, enter 4\nif you want to delete a value, enter 5\nif you want to exit, enter 6\n");
    scanf("%d",&k);
    switch(k)
    {
        case 0:
            sort(&head);
            display(&head);
            break;
        case 1:
            insert_end(&head);
            display(&head);
            break;
        case 2:
            insert_beg(&head);
            display(&head);
            break;
        case 3:
            delete_beg(&head);
            display(&head);
            break;
        case 4:
            delete_end(&head);
            display(&head);
            break;
        case 5:
            printf("enter the value you want to delete- ");
            scanf("%d",&val);
            del_val(&head,val);
            display(&head);
            break;
        case 6:
            c=1;
            break;
        default:
            printf("enter valid input");
            break;
    }}while(c!=1);
    return 0;
}

    








