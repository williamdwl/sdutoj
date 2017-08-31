#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node* l;//node *l
    struct node* r;

}Tree;
int count=0;

Tree *create(Tree *p)
{
    char c;
    if((c=getchar())==',')
        p=NULL;
    else
    {
        p = (Tree*)malloc(sizeof(Tree));
        p->data=c;
        p->l=create(p->l);
        p->r=create(p->r);
    }
    return p;
}
void pretravel(Tree *p)
{
    if(p!=NULL)
    {
        printf("%c",p->data);
        pretravel(p->l);
        pretravel(p->r);
    }
}
void intravel(Tree *p)
{
    if(p!=NULL)
    {
        intravel(p->l);
        printf("%c",p->data);
        intravel(p->r);
    }
}
void lasttravel(Tree *p)
{
    if(p!=NULL)
    {
        lasttravel(p->l);
        lasttravel(p->r);
        printf("%c",p->data);
    }
}
void leaves(Tree *p)
{
    if(p!=NULL)
    {
        if(p->l==NULL && p->r==NULL)
        {
            count++;
        }
        leaves(p->l);
        leaves(p->r);
    }
}

int treedeep(Tree *p)
{

    int ld,rd;
    if(!p)
        return 0;
    else
    {
        ld=treedeep(p->l);
        rd=treedeep(p->r);
        if(ld>rd)
            return ld+1;
        else
            return rd+1;
    }
}
int main()
{
    Tree *p;
    int n;
    p=create(p);
    intravel(p);
    printf("\n");
    lasttravel(p);
    printf("\n");
    leaves(p);
    printf("%d\n",count);
    n=treedeep(p);
    printf("%d\n",n);
    return 0;
}
