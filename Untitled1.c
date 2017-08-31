#include<stdio.h>
#include<math.h>
#include<malloc.h>
#include<memory.h>
int v[1000];//��ǰҪ���ʵĽڵ�
int queue[1000];//�����ʹ��Ľڵ㱣�浽����
int n,m,k;
struct node
{
    int data;
    struct node *next;
};
struct node *head[1000];

//��ʼ���ڽӱ�ͼ
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

//�����ڽӱ���ͼ
void buildG(int u,int v)
{
    struct node *p1,*p2;
    //����ڵ㣬��������������ʽ��ͬ
    p1=(struct node *)malloc(sizeof(struct node));
    p1->data=v;
    p1->next=head[u]->next;
    head[u]->next=p1;
    p2=(struct node *)malloc(sizeof(struct node));
    p2->data=u;
    p2->next=head[v]->next;
    head[v]->next=p2;
}

//���ڽӱ��������
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

//������ȱ���
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
        InitG();//��ʼ���ڽӱ�
        int i;
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&u,&v);
            buildG(u,v);//�����ڽӱ�
        }
        cmp();//�ڽӱ�����
        printf("%d ",k);
        bfs(k);//������ȱ���
        printf("\n");
    }
    return 0;
}
