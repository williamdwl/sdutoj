#include<iostream>
#include<stdio.h>
using namespace std;
//#define LOCAL
int a[100][100];
//int b[101][101];
int main()
{
        int m, n;
#ifdef LOCAL
        freopen("in.txt", "r", stdin);
#endif // LOCAL

        while (cin >> m >> n)
        {
#ifdef LOCAL
                //       cout<<"进来了"<<endl;;
#endif // LOCAL
                for (int i = 0; i < m; i++)
                {
#ifdef LOCAL
                        //        cout<<"循环中"<<endl;
#endif // LOCAL
                        for (int j = 0; j < n; j++)
                        {
                                cin >> a[j][i];
                                //                                b[j][i]=a[i][j];
                        }
                }
#ifdef LOCAL
                //     cout<<"结束了"<<endl;
#endif // LOCAL
                for (int i = 0; i < n; i++)
                {

                        for (int j = 0; j < m; j++)
                        {
                                if (j == m - 1)
                                {
                                        cout << a[i][j];
                                }
                                else
                                {
                                        cout << a[i][j] << " ";
                                }
                        }
                        cout << endl;
                }
                cout << endl;



        }

        return 0;
}
