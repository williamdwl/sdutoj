#include <iostream>
#include <cstdio>
#include<cstdlib>
using namespace std;

char ch[10010];
int l=0;
struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
};

void CreateTree(struct node* &root)//注意加&，若不加则：就是复制指针，但左右孩子指针赋值后传不到原来的root
{
    char h=ch[l++];
    if(h==',')
        root=NULL;
    else
    {
        root=(struct node*)malloc(sizeof(struct node));
        root->data=h;
        CreateTree(root->lchild);
        CreateTree(root->rchild);
    }
}

void LevelTraverse(struct node* root)
{
    if(root==NULL)
        return ;
    int i=0;
    int n=0;
    struct node*a[10010];
    a[n++]=root;
    while(i<n)
    {
        if(a[i])
        {
            if(a[i]->lchild ==NULL && a[i]->rchild==NULL)
                printf("%c",a[i]->data);
            if(a[i]->lchild!=NULL)
                a[n++]=a[i]->lchild;
            if(a[i]->rchild!=NULL)
                a[n++]=a[i]->rchild;
        }
        i++;
    }


}
int main()
{
    struct node * root;
    while(~scanf("%s",ch))
    {
        l=0;
        CreateTree(root);
        LevelTraverse(root);
        printf("\n");
    }
    return 0;
}

