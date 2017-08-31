#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
/*
	��Ҫ˼·���Ȱѱ�����Ȼ�󲢲鼯���ж��Ƿ���ͨ   kruskal=����+���鼯
*/

struct node
{
    int u,v,w;
    bool operator < (const node &x)const//��ĳ�Ա������ʽ����thisָ��
    {                                                     //�ڳ�Ա�������const��ʾ���ݵ���һ��������ָ���������thisָ��
                                                        // const node *const this
        return w<x.w;//w=this->w;
    }
} q[1000002];

int e=0;
int fa[100002];
int findset(int x)//���鼯
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
        sort(q,q+m);//��������
        for(i=0; i<=n; i++)
            fa[i]=i;
        int ans=0;
        int cnt=0;
        for(int k=0; k<m; k++)
        {
            if(findset(q[k].u)!=findset(q[k].v))
            {
                fa[fa[q[k].u]]=fa[q[k].v];//ѹ��
                ans+=q[k].w;
                cnt++;
                if(cnt==n-1)//���д�ׯ����ͨ
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
