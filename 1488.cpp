#include<bits/stdc++.h>//这个头文件包含c++所以头文件
//#define LOCAL
using namespace std;
int main(){//利用查并集，即找老大
        int T,n,e;
        int *a=new int;
#ifdef LOCAL
        freopen("in.txt","r",stdin);
//        freopen("out.txt","w",stdout);
#endif // LOCAL
        cin>>T;


        while(T--){
                cin>>n>>e;
                for(int i=1;i<=n;i++)//初始化
                        a[i]=i;
                int u,v;

                while(e--){
                        cin>>u>>v;
                        while(u!=a[u])//找大哥
                                u=a[u];
                        while(v!=a[v])//找大哥
                                v=a[v];
                        if(u!=v)//找到大哥后结盟
                                a[u]=v;
                }
                int num=0;
                for(int i=1;i<=n;i++){
                        if(i==a[i])
                                num++;
                }
                cout<<num<<endl;
        }
        return 0;
}
