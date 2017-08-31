#include<stdio.h>
#include<math.h>
#include<malloc.h>
#include<memory.h>
int visit[1000];//��ǰҪ���ʵĽڵ�
int queue[1000];//��Ҫ���ʵĽڵ㱣�浽����
int n,m,k;
struct node
{
    int data;
    struct node*next;
}*head[1000];

//��ʼ���ڽӱ�
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
//�����ڽӱ���ͼ
void buildG(int u,int v)
{
    struct node*p1,*p2;
    //����ڵ㣬��������������ʽ��ͬ���ֱ�u����v��������v����u����
    p1=(struct node*)malloc(sizeof(struct node));
    p1->data=v;
    p1->next=head[u]->next;
    head[u]->next=p1;
    //ͬ�������
    p2=(struct node*)malloc(sizeof(struct node));
    p2->data=u;
    p2->next=head[v]->next;
    head[v]->next=p2;

}

//���ڽӱ��������
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

//������ȱ���,���ö��У�����visit
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
