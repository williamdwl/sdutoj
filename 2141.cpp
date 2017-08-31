    #include <iostream>
    #include <queue>
    #include <cstring>
    #include <cstdio>
    #include <algorithm>
    using namespace std;
    int map[222][222],vis[222],ans[222];//map[][]为邻接矩阵用来存图 vis[]用来标记节点是否访问 ans[]来保存遍历结果
    int p;
    void bfs(int t,int n) //t是起点，n是节点个数
    {
        queue <int> Q;
        vis[t]=1;ans[p++]=t; //首先访问起点
        Q.push(t);
        while(!Q.empty())
        {
            int v=Q.front();Q.pop();
            for(int i=0;i<n;i++)
            {
                if(!vis[i]&&map[v][i])
                {
                    vis[i]=1;ans[p++]=i;
                    Q.push(i);
                }
            }

        }
    }
    int main()
    {
        int T,k,m,t,i,u,v;
        cin>>T;
        while(T--)
        {
            cin>>k>>m>>t;
            memset(map,0,sizeof(map));
            memset(vis,0,sizeof(vis));
            for(i=0;i<m;i++)
            {
                cin>>u>>v;
                map[u][v]=1;
                map[v][u]=1;
            }
            bfs(t,k);
            for(int i=0;i<p;i++)
                cout<<ans[i]<<" ";
            p=0;
        }
        return 0;
    }
