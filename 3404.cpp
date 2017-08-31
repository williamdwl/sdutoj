#include<bits/stdc++.h>
using namespace std;
vector<string>vt[2010];//字符串型动态数组,声明了一维空间，二维动态的二维数组

int M[2010];

bool cmp(string x,string y)
{
    return x<y;
}

int main()
{
    int i,j,n,m,k,t;
    string temp;
    scanf("%d %d",&n,&m);
    memset(M,0,sizeof(M));
    for(i=0;i<n;i++)
    {
        cin>>temp;
        cin>>k;
        for(j=0;j<k;j++)
        {
            cin>>t;
            vt[t].push_back(temp);
            M[t]++;
        }
    }
    for(i=0;i<2010;i++)
    {
        /*sort(begin,end,cmp)，begin~end表示一个范围,利用cmp进行排序
            默认升序排序，若要降序得自己写比较函数，如cmp:当a b关系为 > < = 时，分别返回正值 负值 零 （或者相反）。
            因此本题若不写cmp函数也正确，即  sort(vt[i].begin(),vt[i].end());
        */
        if(M[i]!=0)
        {
            sort(vt[i].begin(),vt[i].end(),cmp);
            cout<<i<<" "<<M[i]<<endl;
            for(j=0;j<vt[i].size();j++)
                cout<<vt[i][j]<<endl;
        }
    }
}
