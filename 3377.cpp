#include <bits/stdc++.h>

using namespace std;

int main()
{
    int Hash[550];
    int n,k;
    while(cin>>n>>k)
    {
        memset(Hash,-1,sizeof(Hash));
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            int remainder=x%k;
            if(Hash[remainder]==-1)
            {
                    cout<<remainder;
                    Hash[remainder]=x;
            }

            else{
                for(int j=1;j<=k/2;j++)//j=k-1/2��ƽ��ȡ�з����������Ϊk-1��һ�룬
                {                       //����Ϊ��1^2.-1^2.2^2.-2^2.3^2.-3^2...(k-1)/2
                    if(Hash[(remainder+j*j)%k]==-1)
                    {
                        cout<<(remainder+j*j)%k;
                        Hash[(remainder+j*j)%k]=x;
                        break;
                    }else if(Hash[(remainder-j*j)%k]==-1)
                    {
                        cout<<(remainder-j*j)%k;
                        Hash[(remainder-j*j)%k]=x;
                        break;
                    }
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
