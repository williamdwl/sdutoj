#include <bits/stdc++.h>

using namespace std;

int main()
{
    int Hash[5510];
    int n,k;
    while(cin>>n>>k)
    {
        /* void *memset(void *s,int c,size_t n)
��   ���ܵ����ã����ѿ����ڴ�ռ� s ���� n ���ֽڵ�ֵ��Ϊֵ c��
    */
        memset(Hash,-1,sizeof(Hash));
        for(int i=0;i<n;i++)
        {
            int x,t;
            cin>>x;
            t=x%k;
            if(Hash[t]==-1)
            {
                cout<<t;
                Hash[t]=x;
            }else{
                bool Flag=false;
                for(int j=0;j<k;j++)
                {
                    if(Hash[j]==x)
                    {
                        cout<<j;
                        Flag=true;
                        break;
                    }
                }
                if(!Flag)
                {
                    while(Hash[t%k]!=-1)
                        t++;
                    cout<<t%k;
                    Hash[t%k]=x;
                }
            }
            if(i==n-1)
                cout<<endl;
            else
                cout<<" ";
        }
    }
    return 0;
}
