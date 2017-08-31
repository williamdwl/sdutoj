#include<stdio.h>
int n;
int a[10010];
int b[10010];
void shellsort1(int a[],int n)
{
    int d,i,j,t;
    d=n/2;
    for(i=d;i<n;i++)
        for(j=i-d;j>=0;j-=d)
        {
            if(a[j]>a[j+d])
            {
                t=a[j];
                a[j]=a[j+d];
                a[j+d]=t;
            }
        }

}
void shellsort2(int a[],int n)
{
    int d,i,j,t;
    d=1;
    for(i=d;i<n;i++)
        for(j=i-d;j>=0;j-=d)
        {
            if(a[j]>a[j+d])
            {
                t=a[j];
                a[j]=a[j+d];
                a[j+d]=t;
            }
        }

}
int main()
{
    while(~scanf("%d",&n))
    {
        int i;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            b[i]=a[i];
        }
        shellsort1(a,n);
        for(i=0;i<n;i++)
        {
            if(i<n-1)
                printf("%d ",a[i]);
            else
                printf("%d\n",a[i]);
        }
        shellsort2(b,n);
        for(i=0;i<n;i++)
        {
            if(i<n-1)
                printf("%d ",b[i]);
            else
                printf("%d\n",b[i]);
        }
    }
}
