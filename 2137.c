#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node
{
    char data;
    struct node *l,*r;
}Tree;

Tree *create(int n,char*pretravel,char*intravel)
{
    Tree *root;
    char *p;
    if(n==0)
        return NULL;
    root=(Tree*)malloc(sizeof(Tree));
    root->data=pretravel[0];
    for(p=intravel;p!='\0';p++)
    {
        if(*p==pretravel[0])//在中序遍历中找到根节点，从而分为左右两个部分
            break;
    }
    int t=p-intravel;//左子树节点的个数
    root->l=create(t,pretravel+1,intravel);
    root->r=create(n-t-1,pretravel+t+1,p+1);
    return root;
}

void lasttravel(Tree *root)
{
    if(root)
    {
        lasttravel(root->l);
        lasttravel(root->r);
        printf("%c",root->data);
    }
}
void leveltravel(Tree *root)
{
    int cnt=0;
    int child=1;
    Tree *q[60];
    q[0]=root;
    while(cnt<child)
    {
        if(q[cnt])
        {
            printf("%c",q[cnt]->data);
            q[child++]=q[cnt]->l;
            q[child++]=q[cnt]->r;
        }
        cnt++;
    }
}
int main()
{
    int n;
    char pretravel[60],intravel[60];
    Tree *root;
    root=(Tree*)malloc(sizeof(Tree));
    scanf("%d",&n);
    getchar();
    while(n--)
    {
        scanf("%s %s",pretravel,intravel);
        int n=strlen(pretravel);
        root=create(n,pretravel,intravel);
        lasttravel(root);
        printf("\n");
        leveltravel(root);
        printf("\n");
    }
    return 0;
}

