#include<iostream>
#include<stdio.h>
using namespace std;
#define LOCAL

struct Sstack
{
        char  *data;
        int top=-1;
};

int main()//该题只能一位数加减
{
        #ifdef LOCAL
                freopen("in.txt","r",stdin);
        #endif // LOCAL
        Sstack S1,S2;
        S1.data==NULL;
        S2.data==NULL;
        char s;
        while(~scanf("%c",&s))
        {
                int n=s-'0';
                if(n<=9 && n>=0)
                {
                        S1.data[S1->top++]=s;
                }else
        }
        return 0;
}
