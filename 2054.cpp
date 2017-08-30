#include<iostream>
#include<stdio.h>
using namespace std;

//#define LOCAL

struct DoubleLink
{
        int data;
        struct DoubleLink *left;//养成好习惯，struct
        struct DoubleLink *right;
};
int main()
{
        int i;
        int n, m, d, s;
#ifdef LOCAL
        freopen("in.txt", "r", stdin);
#endif // LOCAL
        cin >> n >> m;
        DoubleLink* header = new DoubleLink;
        header->left = NULL;
        header->right = NULL;
        DoubleLink* q = new DoubleLink;
        q->left = NULL;
        q->right = NULL;
        q = header;
        for (i = 0; i < n; i++) //初始化
        {
                DoubleLink *p = new DoubleLink;
                p->right = NULL;
                p->left = NULL;
                cin >> d;
                p->data = d;

                p->left = q;
                q->right = p;
                q = p;
        }

        q = header->right;

        while (m--)
        {
                q = header->right;//每次从头遍历
                cin >> s;
                for (i = 0; i < n; i++)
                {
#ifdef LOCAL
                        //         cout<<"jinlaile2"<<endl;
#endif // LOCAL
                        if (s == (q->data))
                        {
#ifdef LOCAL
                                //   cout<<"jinlaile"<<endl;
#endif // LOCAL
                                if (q->left != header)
                                {
                                        cout << q->left->data <<" ";
                                }
                                if (q->right != NULL)
                                {
                                        cout << q->right->data << endl;
                                }
                                else
                                {
                                        cout << endl;
                                }
                                break;
                        }
                        q = q->right;

                }
        }
        return 0;
}
