#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
//#define LOCAL

int binSearch(int*a, int low, int high, int m)//注意cout测试要注释掉再提交
{
        int mid;
//        int low=s,high=t;

        if (high >= low)
        {
                mid = low  + (high - low) / 2;
//                cout<<mid<<endl;
                if (a[mid] == m)
                {
                        return mid;
                }
                else if (m < a[mid])
                {
                        return binSearch(a, low, mid - 1, m);//记得写return结果才会往回传
                }
                else if (m > a[mid])
                {
                        return binSearch(a, mid + 1, high, m);
                }
        }
        return -1;

}

int main()
{

#ifdef LOCAL
        //        freopen("in.txt","r",stdin);
        //        freopen("out.txt","w",stdout);
#endif // LOCAL

        int n, m;
        int a[100010];

        while(~scanf("%d", &n))
        {

                for (int i = 0; i < n; i++)
                {
                        cin >> a[i];
                }
                scanf("%d", &m);
                if (binSearch(a, 0, n -1, m) != -1)
                {
                        cout << "YES"<<endl;
                }
                else
                {
                        cout << "NO"<<endl;
                }
        }
        return 0;
}
