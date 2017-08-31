#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
/*
	主要思路，先把边排序，然后并查集即判断是否连通   kruskal=排序+并查集
*/

struct node
{
    int u,v,w;
    bool operator < (const node &x)const//类的成员函数隐式传递this指针
    {                                                     //在成员函数后加const表示传递的是一个常量的指向常量对象的this指针
                                                        // const node *const this
        return w<x.w;//w=this->w;
    }
} q[1000002];

int e=0;
int fa[100002];
int findset(int x)//并查集
{
    return fa[x]!=x?fa[x]=findset(fa[x]):x;
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int i;
        for(i=0; i<m; i++)
            scanf("%d%d%d",&q[i].u,&q[i].v,&q[i].w);
        sort(q,q+m);//按边排序
        for(i=0; i<=n; i++)
            fa[i]=i;
        int ans=0;
        int cnt=0;
        for(int k=0; k<m; k++)
        {
            if(findset(q[k].u)!=findset(q[k].v))
            {
                fa[fa[q[k].u]]=fa[q[k].v];//压缩
                ans+=q[k].w;
                cnt++;
                if(cnt==n-1)//所有村庄都连通
                    break;
            }
        }
        if(cnt==n-1)
            printf("%d\n",ans);
        else
            printf("-1\n");
    }
    return 0;
}
