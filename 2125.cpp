#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
//#define LOCAL

//next是C++里的东西。所以不能命名next

void Getnexttval(char*p, int nextt[])//next 数组各值的含义：代表当前字符之前的字符串中，有多大长度的相同前缀后缀。
{
        int pLen = strlen(p);
        nextt[0] = -1;
        int k = -1;
        int j = 0;
        while (j < pLen -1 )
        {
                if (k == -1 || p[j] == p[k])
                {
                        ++j;
                        ++k;
                        if (p[j] != p[k])//优化，判断p[j]==p[next[j]]情况
                        {
                                nextt[j] = k;
                        }
                        else
                        {
                                nextt[j] = nextt[k];//因为不能出现p[j] = p[ next[j ]]，所以当出现时需要继续递归，k = next[k] = next[next[k]]
                        }
                }
                else
                {
                        k = nextt[k];
                }
        }
}
void KmpSearch(char*s, char *p,int*nextt)
{
        Getnexttval(s, nextt);
        int i = 0, j = 0;
        int sLen = strlen(s);
        int pLen = strlen(p);
        while (i < sLen && j < pLen)
        {

                if (j == -1 || s[i] == p[j])//-1的作用：跳到第一个（下标为0）比较如果也不匹配，则j=next[0]=-1;i++,j++一起往后匹配
                {                           //通俗一点：碰到-1已经匹配到的串没有重复的地方
                        i++;
                        j++;
                }
                else
                {
                        j = nextt[j];//解释：若j=nextt[j]=0->若s[i]!=p[0]->j=next[j]=-1;
                }
        }
        if (j == pLen)
        {
                cout << "YES" << endl;
        }
        else
        {
                cout << "NO" << endl;
        }
}

int main()
{
        //        for(int i=0;i<101;i++){
        //                nextt[i++]=0;
        //                cout<<nextt[i++];
        //        }
#ifdef LOCAL
        freopen("in.txt", "r", stdin);
#endif // LOCAL

        char n[101];


        while (~scanf("%s", n))
        {
                char s[101];
                int nextt[101];
                while (~scanf("%s", s))
                {

                        KmpSearch(n, s,nextt);
                        break;

                }

        }
        return -1;
}
