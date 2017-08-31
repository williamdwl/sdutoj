#include<stdio.h>
#include<math.h>
#include<malloc.h>
#include<memory.h>
int visit[1000];//当前要访问的节点
int queue[1000];//将要访问的节点保存到队列
int n,m,k;
struct node
{
    int data;
    struct node*next;
}*head[1000];

//初始化邻接表
void InitG()
{
    int i;
    for(i=0;i<n;i++)
    {
        head[i]=(struct node*)malloc(sizeof(struct node));
        head[i]->data=i;
        head[i]->next=NULL;
    }
}
//建立邻接表型图
void buildG(int u,int v)
{
    struct node*p1,*p2;
    //插入节点，和逆序建立链表形式相同，分别将u插入v链串，将v插入u链串
    p1=(struct node*)malloc(sizeof(struct node));
    p1->data=v;
    p1->next=head[u]->next;
    head[u]->next=p1;
    //同上面插入
    p2=(struct node*)malloc(sizeof(struct node));
    p2->data=u;
    p2->next=head[v]->next;
    head[v]->next=p2;

}

//将邻接表进行排序
void cmp()
{
    struct node*p,*q;
    int i;
    for(i=0;i<n;i++)
    {
        for(p=head[i]->next;p!=NULL;p=p->next)
        {
            for(q=p->next;q!=NULL;q=q->next)
            {
                if(p->next>q->next)
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

//广度优先遍历,利用队列，设置visit
void bfs(int k)
{
    memset(visit,0,sizeof(visit));
    int front=0,rear=0;
    queue[front++]=k;
    visit[k]=1;
    struct node*p;
    while(front>rear)
    {
        int count;
        count=queue[rear++];
        for(p=head[count]->next;p!=NULL;p=p->next)
        {
            if(visit[p->data]==0)
            {
                printf("%d ",p->data);
                queue[++front]=p->data;
                visit[p->data]=1;
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
        InitG();
        int i;
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&u,&v);
            buildG(u,v);
        }
        cmp();
        printf("%d ",k);
        bfs(k);
        printf("\n");
    }
    return 0;
}
