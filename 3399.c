#include<stdio.h>

int BubbleSort(int a[],int N)
{
    int i,j=0,count=0;
    for(i=N-1;i>=0;i--)
    {
        for(j=0;j<i;j++)
        {
            if(a[j]>a[j+1])
            {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                count++;
            }
        }
    }
    return count;
}

int QuickSort(int a[],int left,int right)
{
        int count=0;
        int i=left;
        int j=right;
        int temp=a[left];
        if(right>left)
        {
            while(j>i)
            {
                while(j>i && temp<=a[j])j--;
                if(j>i)
                {
                     a[i]=a[j];
//                   printf("%d\n",a[i]);
                    count++;
                }

                while(j>i && temp>=a[i])i++;
                if(j>i)
                {
                    a[j]=a[i];
 //                   printf("%d\n",a[j]);
                    count++;
                }

            }
            a[i]=temp;
            count+=QuickSort(a,left,i-1);
            count+=QuickSort(a,i+1,right);
        }
    return count;
}



int main()
{
    int N,i;
    while(~scanf("%d",&N))
    {
        int a[100010],b[100010];
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for(i=0;i<N;i++)
        {
             scanf("%d",&a[i]);
             b[i]=a[i];
        }
        printf("%d %d\n",BubbleSort(b,N),QuickSort(a,0,N-1));
    }


    return 0;
}
