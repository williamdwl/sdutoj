#include<stdio.h>


void QuickSort(int R[],int l,int r)
{
    int temp;
    int i=l,j=r;


    if(l<r)
    {
        temp=R[l];
        //下面这个循环完成了一趟排序，即将数组中小于temp的元素放在左边，大于temp的元素放在右边
        while(i<j)
        {
            while(j>i && R[j]>=temp)j--;
            if(i<j)
            {
                R[i]=R[j];
            //    printf("%d\n",R[i]);
                i++;//i右移一位
            }
            while(j>i && R[i]<=temp)i++;
            if(i<j)
            {
                R[j]=R[i];
             //   printf("%d\n",R[j]);
                j--;//j左移一位
            }

        }

        R[i]=temp;
//        QuickSort(R,l,i-1);
 //       QuickSort(R,i+1,r);
    }
}

int main()
{
    int N,i;
    while(~scanf("%d",&N))
    {
        int R[100010],i;
        memset(R,0,sizeof(R));
        for(i=0;i<N;i++)//使用while(N--)有关于数据顺序不同，排列 出来的过程会不同
        {
            scanf("%d",&R[i]);
        }
        QuickSort(R,0,N-1);
        for(i=0;i<N-1;i++)
            printf("%d ",R[i]);
        printf("%d\n",R[N-1]);

    }
    return 0;
}

