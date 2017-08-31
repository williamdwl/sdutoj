#include<bits/stdc++.h>
using namespace std;

#define Max INT_MAX
#define MaxE 510

int Edge[MaxE][MaxE];
int cost[MaxE][MaxE];

void Dijkstra(int n,int v0,int vn)
{
    int dist[MaxE];
    int s[MaxE];//标记数组
    int mon[MaxE];
    for(int i=0; i<n; i++) //初始化dist数组和path数组
    {
        dist[i]=Edge[v0][i];
        mon[i]=cost[v0][i];
    }
    memset(s,0,sizeof(s));
    s[v0]=1;
    dist[v0]=0;
    mon[v0]=0;
    for(int i=1; i<n; i++)
    {
        int Min=Max;
        int k=v0;
        for(int j=0; j<n; j++)//选取当前集合中最短路径的定点k
            if(!s[j] && dist[j]<Min)
            {
                Min=dist[j];
                k=j;
            }
        s[k]=1;
        for(int j=0; j<n; j++)
            if(!s[j] && Edge[k][j]<Max)
                if(dist[k]+Edge[k][j]<dist[j])
                {
                    dist[j]=dist[k]+Edge[k][j];
                    mon[j]=mon[k]+cost[k][j];
                }
                else if(dist[k]+Edge[k][j]==dist[j] && mon[k]+cost[k][j]<mon[j]) //路程相同，选取费用最小的
                    mon[j]=mon[k]+cost[k][j];



    }
    cout<<dist[vn]<<" "<<mon[vn]<<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,s,d;
        cin>>n>>m>>s>>d;
        for(int i=0; i<n; i++) //初始化邻接矩阵
            for(int j=0; j<n; j++)
                if(i==j)
                    Edge[i][j]=0;
                else
                    Edge[i][j]=Max;
        for(int i=0; i<m; i++)
        {
            int a,b,l,c;
            cin>>a>>b>>l>>c;
            Edge[a][b]=Edge[b][a]=l;
            cost[a][b]=cost[b][a]=c;
        }
        Dijkstra(n,s,d);
    }
}
