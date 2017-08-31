#include<stdio.h>


void QuickSort(int R[],int l,int r)
{
    int temp;
    int i=l,j=r;


    if(l<r)
    {
        temp=R[l];
        //�������ѭ�������һ�����򣬼���������С��temp��Ԫ�ط�����ߣ�����temp��Ԫ�ط����ұ�
        while(i<j)
        {
            while(j>i && R[j]>=temp)j--;
            if(i<j)
            {
                R[i]=R[j];
            //    printf("%d\n",R[i]);
                i++;//i����һλ
            }
            while(j>i && R[i]<=temp)i++;
            if(i<j)
            {
                R[j]=R[i];
             //   printf("%d\n",R[j]);
                j--;//j����һλ
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
        for(i=0;i<N;i++)//ʹ��while(N--)�й�������˳��ͬ������ �����Ĺ��̻᲻ͬ
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

