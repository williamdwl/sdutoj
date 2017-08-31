#include<stdio.h>
#include<math.h>
#include<malloc.h>
#include<memory.h>
int v[1000];//当前要访问的节点
int queue[1000];//将访问过的节点保存到队列
int n,m,k;
struct node
{
    int data;
    struct node *next;
};
struct node *head[1000];

//初始化邻接表图
void InitG()
{
    int i;
    for( i=0;i<n;i++)
    {
        head[i]=(struct node *)malloc(sizeof(struct node));
        head[i]->data=i;
        head[i]->next=NULL;
    }
}

//建立邻接表型图
void buildG(int u,int v)
{
    struct node *p1,*p2;
    //插入节点，跟逆序建立链表形式相同
    p1=(struct node *)malloc(sizeof(struct node));
    p1->data=v;
    p1->next=head[u]->next;
    head[u]->next=p1;
    p2=(struct node *)malloc(sizeof(struct node));
    p2->data=u;
    p2->next=head[v]->next;
    head[v]->next=p2;
}

//将邻接表进行排序
void cmp()
{
    struct node *p,*q;
    int i;
    for(i=0;i<n;i++)
    {
        for(p=head[i]->next;p!=NULL;p=p->next)
        {
            for(q=p->next;q!=NULL;q=q->next)
            {
                if(p->data>q->data)
                {
                    int t;
                    t=p->data;
                    p->data=q->data;
                    q->data=t;
                }
            }
        }
    }
}

//广度优先遍历
void bfs(int k)
{
    memset(v,0,sizeof(v));
    int num1,num2;
    num1=num2=0;
    queue[num1]=k;
     num1++;
    v[k]=1;
    struct node *p;
    while(num1>num2)
    {
        int count;
        count=queue[num2++];
        for(p=head[count]->next;p!=NULL;p=p->next)
        {
            if(v[p->data]==0)
            {
                printf("%d ",p->data);
                queue[++num1]=p->data;
                //num1++;
                v[p->data]=1;

            }
        }
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d",&n,&m,&k);
        int u,v;
        InitG();//初始化邻接表
        int i;
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&u,&v);
            buildG(u,v);//构建邻接表
        }
        cmp();//邻接表排序
        printf("%d ",k);
        bfs(k);//广度优先遍历
        printf("\n");
    }
    return 0;
}
