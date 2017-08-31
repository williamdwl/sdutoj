#include<bits/stdc++.h>
using namespace std;
int n,m,c;//点数，边数，起始点的数值
int v[3100];//每个点的访问状态
int Map[3100][3100];
int a[3100];//存储深度遍历的遍历轨迹
int num;//记录符合条件的点的数目

void DFS(int x)
{
    /*
        为什么用深度优先：深度优先相当于树的前序遍历，运用了递归，递归=“去”+“来”，所以连通图的每个点都
        被访问两次，如果不是连通图，那么访问次数就小于2*n-1（最后一个点只访问一次）；即每个灯亮两次
    */
    int i;
    v[x]=1;
    a[num++]=x;//记录“去”时候的遍历轨迹
    for(i=1;i<=n;i++)
    {
        if(v[i]==0 && Map[x][i]==1)
        {

                v[i]=1;
                DFS(i);
                a[num++]=x;

        }
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(v,0,sizeof(v));
        memset(Map,0,sizeof(Map));
        scanf("%d %d %d",&n,&m,&c);
        int i;
        for(i=0;i<m;i++)
        {
            int u,v;
            scanf("%d %d",&u,&v);
            Map[u][v]=Map[v][u]=1;
        }
        num=0;
        DFS(c);
        for(i=0;i<num;i++)
        {
            if(i==0)
                printf("%d",a[i]);//
            else
                printf(" %d",a[i]);
        }
        if(num!=2*n-1)//因为来回两次，最后一个数就访问一次。
            printf(" 0");
        printf("\n");
    }
}

