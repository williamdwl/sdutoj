#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
/*
无穷大不取0x7fffffff的原因：防止无穷大加无穷大溢出
0x3f3f3f3f的十进制是1061109567，是10^9级别的（和0x7fffffff一个数量级），
而一般场合下的数据都是小于10^9的，所以它可以作为无穷大使用而不致出现数据大于无穷大的情形。
*/
int Map[1010][1010];
bool visit[1010];
int lowcost[1010];
int m,n;
int sum,flag;

void prim()
{
/*
prim算法，先任取一个点，本程序选1，然后取距离已选取的点集合最近的点加入点集合。
*/
    int k;
    int temp;
    visit[1]=false;
    for(int i=1;i<=m;i++)//lowcost存储已选点集合连接未选点的所有边
        lowcost[i]=Map[i][1];
    for(int i=2;i<=m;i++)
    {
        temp=INF;
        for(int j=1;j<=m;j++)//找出最近的点
        {
            if(visit[j] && lowcost[j]<temp)
            {
                temp=lowcost[j];
                k=j;
            }

        }
        if(temp==INF)
        {
            flag=1;
            break;
        }
        visit[k]=false;
        sum+=temp;
        for(int j=1;j<=m;j++)//更新已选点集合的lowcost，若有更短的路径，则替代原来长的路径
        {
            if(visit[j] && lowcost[j]>Map[j][k])
                lowcost[j]=Map[j][k];
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    int v,u,cost;
    while(cin>>m>>n)
    {
        memset(Map,INF,sizeof(Map));
        memset(visit,true,sizeof(visit));
        flag=0;
        for(int i=0;i<n;i++)
        {
            cin>>v>>u>>cost;
            Map[v][u]=cost;
            Map[u][v]=cost;
        }
        prim();
        if(!flag)cout<<sum<<endl;
        else cout<<-1<<endl;
    }
}
