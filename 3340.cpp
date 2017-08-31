#include<iostream>
#include<cstring>
#include<cstdlib>

//代码过于冗长，还需优化
using namespace std;
int sign[100];
int num=0;
struct node
{
    char data;
    struct node*l,*r;
};

struct node1
{
    char data;
    int a,b;//记录编号
} q[100];

struct node* create(struct node*root,int n)
{
    root=new node;
    root->l=NULL;
    root->r=NULL;
    root->data=q[n].data;
    if(q[n].a!=-1)
    {
        root->l=create(root->l,q[n].a);
    }
    if(q[n].b!=-1)
    {
        root->r=create(root->r,q[n].b);
    }
    return root;
}

struct node*InitTree(int n,char*s1,char*s2,char*s3)
{


    memset(sign,0,sizeof(sign));
    for(int i=0; i<n; i++)
    {
        cin>>s1>>s2>>s3;
        q[i].data=s1[0];
        if(s2[0]=='-')
            q[i].a=-1;
        else
        {
            q[i].a=s2[0]-'0';
            sign[q[i].a]=1;

        }
        if(s3[0]=='-')
            q[i].b=-1;
        else
        {
            q[i].b=s3[0]-'0';
            sign[q[i].b]=1;
        }
    }
    struct node*Root;
    if(n!=0)
    {
        int j;
        for(j=0; j<n; j++)//找根节点
            if(!sign[j])
                break;
        Root=create(Root,j);
    }
    return Root;
}

int isomorphism(struct node*p,struct node*q)
{
    if(!p&&!q)
        return 1;
    else if(p&&q)
    {
        if(p->data!=q->data)
            return 0;
        else
            num++;
        if((isomorphism(p->l,q->l)&&isomorphism(p->r,q->r))
                || (isomorphism(p->r,q->l)&&isomorphism(p->l,q->r)))
            return 1;
        else
            return 0;
    }
    else
        return 0;
}


int main()
{
    int n,m;
    char s1[5],s2[5],s3[5];
    while(cin>>n)
    {
        struct node* Root=InitTree(n,s1,s2,s3);
        cin>>m;
        struct node* root=InitTree(m,s1,s2,s3);

        num=0;
        isomorphism(Root,root);
        if(num==n)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
