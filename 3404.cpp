#include<bits/stdc++.h>
using namespace std;
vector<string>vt[2010];//�ַ����Ͷ�̬����,������һά�ռ䣬��ά��̬�Ķ�ά����

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
        /*sort(begin,end,cmp)��begin~end��ʾһ����Χ,����cmp��������
            Ĭ������������Ҫ������Լ�д�ȽϺ�������cmp:��a b��ϵΪ > < = ʱ���ֱ𷵻���ֵ ��ֵ �� �������෴����
            ��˱�������дcmp����Ҳ��ȷ����  sort(vt[i].begin(),vt[i].end());
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
