#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
/*
�����ȡ0x7fffffff��ԭ�򣺷�ֹ��������������
0x3f3f3f3f��ʮ������1061109567����10^9����ģ���0x7fffffffһ������������
��һ�㳡���µ����ݶ���С��10^9�ģ�������������Ϊ�����ʹ�ö����³������ݴ������������Ρ�
*/
int Map[1010][1010];
bool visit[1010];
int lowcost[1010];
int m,n;
int sum,flag;

void prim()
{
/*
prim�㷨������ȡһ���㣬������ѡ1��Ȼ��ȡ������ѡȡ�ĵ㼯������ĵ����㼯�ϡ�
*/
    int k;
    int temp;
    visit[1]=false;
    for(int i=1;i<=m;i++)//lowcost�洢��ѡ�㼯������δѡ������б�
        lowcost[i]=Map[i][1];
    for(int i=2;i<=m;i++)
    {
        temp=INF;
        for(int j=1;j<=m;j++)//�ҳ�����ĵ�
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
        for(int j=1;j<=m;j++)//������ѡ�㼯�ϵ�lowcost�����и��̵�·���������ԭ������·��
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
