#include<iostream>
#include<stdio.h>
using namespace std;

//#define LOCAL

int main(){
        int n;
        int a[1001];
        while(~scanf("%d",&n))
        {
                for(int i=0;i<n;i++)
                        cin>>a[i];
                int m;
                cin>>m;
                for(int i=0;i<n;i++)
                {
                        if(a[i]==m)
                        {
                                cout<<"YES"<<endl;
                                break;
                        }
                        if(i==n-1)
                        {
//                                #ifdef LOCAL
//                                        cout<<"我进来了"<<endl;
//                                #endif // LOCAL
                                cout<<"NO"<<endl;
                                break;
                        }
//                        #ifdef LOCAL
//                                cout<<i<<endl;
//                        #endif // LOCAL
                }

        }
        return 0;
}
//oj 出现system error可能是数组开太大
