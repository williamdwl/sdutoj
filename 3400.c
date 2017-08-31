#include<stdio.h>
int a[110];
int main()
{
    int N,age;
    scanf("%d",&N);
    memset(a,0,sizeof(a));
    while(N--)
    {
        scanf("%d",&age);
        if(age>100)
            a[100]++;
        else
            a[age]++;
    }
    for(age=0;age<=100;age++)
    {
        if(a[age]!=0)
            printf("%d %d\n",age,a[age]);
    }
    return 0;
}
