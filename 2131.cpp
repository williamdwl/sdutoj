#include<iostream>
#include<stdio.h>
using namespace std;
//#define LOCAL
int d[100];
int main()
{
        #ifdef LOCAL
                freopen("in.txt","r",stdin);
        #endif // LOCAL
        int n,b=0;
        int R;
        cin>>n>>R;
        while(n>0)
        {
                d[b]=n%R;
                b++;
                n=n/R;
        }
        for(int i=b-1;i>=0;i--)
                cout<<d[i];

        return 0;
}
