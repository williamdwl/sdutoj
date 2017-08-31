#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
//哈夫曼编码长度=WPL
using namespace std;

int main()
{
    char s[10000];
    while(scanf("%s",s)!=EOF)
    {
        priority_queue<int,vector<int>,greater<int> > Q;
        int len=strlen(s);
        int i,max=0;
        int count[256]= {0}; //ascii码有256=8位=一个字
        for(i=0; i<len; i++)
        {
            count[s[i]]++;
            if(s[i]>max)
                max=s[i];
        }
        for(i=0; i<=max; i++)
        {
            if(count[i]!=0)
                Q.push(count[i]);
        }
        int sum=0;
        while(!Q.empty())
        {
            int a=Q.top();
            Q.pop();
            if(!Q.empty())
            {
                int b=Q.top();
                Q.pop();
                sum+=(a+b);//计算WPL
                Q.push(a+b);
            }
        }
        printf("%d %d %.1f\n",len*8,sum,len*8.0/sum);
    }
    return 0;
}

