#include<bits/stdc++.h>
using namespace std;

#define INF INT_MAX

int spend[510][510];
int vis[510][510];
int dist[510][510];

int N,M,S,D,u,v,s,d;

void floyd()
{
    int i,j,k;
    for(k=0; k<N; k++)//k为中间点 dist[i][j]=dist[i][k]+dist[k][j];
        for(i=0; i<N; i++)
            for(j=0; j<N; j++)
            {
                if(dist[i][j]>dist[i][k]+dist[k][j])
                {
                    dist[i][j]=dist[i][k]+dist[k][j];
                    spend[i][j]=spend[i][k]+spend[k][j];
                }
                else if(dist[i][j]==dist[i][k]+dist[k][j] && spend[i][j] > spend[i][k] + spend[k][j])
                    spend[i][j] = spend[i][k] + spend[k][j];
            }
    cout<<dist[S][D]<<" "<<spend[S][D]<<endl;
}

int main()
{
    int t;
    while(cin>>t)
    {
        while(t--)
        {
            int i,j;
            cin>>N>>M>>S>>D;
            for(i=0; i<N; i++)
                for(j=0; j<N; j++)
                {
                    if(i==j)
                    {
                        spend[i][j]=0;
                        dist[i][j]=0;
                    }
                    else
                    {
                        spend[i][j]=INF;
                        dist[i][j]=INF;
                    }

                }
            while(M--)
            {
                cin>>u>>v>>d>>s;
                if(spend[u][v]>s)
                {
                    spend[u][v]=spend[v][u]=s;
                    dist[u][v]=dist[v][u]=d;
                }
            }
            floyd();
        }
    }
}
