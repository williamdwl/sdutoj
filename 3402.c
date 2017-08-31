#include<stdio.h>
#include<stdlib.h>
long long int count=0;
void Merge(int a[],int low,int mid,int high)
{
    int i=low;//第一段序列的下标
    int j=mid+1;//第二段序列的下标
    int k=0;//暂存数组的下标
    int *b=(int*)malloc((high-low+1)*sizeof(int));
    while(i<=mid && j<= high)//判断第一段和第二段取出的数哪一个更小，将其存入合并序列，并继续向下遍历
    {
        if(a[i]<=a[j])
            b[k++]=a[i++];
        else{
            b[k++]=a[j++];
            count+=(mid-i+1);//求逆序对（在有序序列中若a[i]>a[j]，则a[i]后的元素皆大于a[j]；
        }
    }
    while(i<=mid)//若第一段序列还没遍历完，将剩余全部复制到合并序列
        b[k++]=a[i++];
    while(j<=high)//若第二段序列还没遍历完，将剩余全部复制到合并序列
        b[k++]=a[j++];
    for(k=0,i=low;i<=high;i++,k++)//将合并序列复制到原始序列中
        a[i]=b[k];
}

void MergeSort(int a[],int low,int high)//先递归，再归并
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        MergeSort(a,low,mid);
        MergeSort(a,mid+1,high);
        Merge(a,low,mid,high);//归并相邻的两组
    }

}

int a[100010];
int main()
{
    int N,i;
    scanf("%d",&N);
    for(i=0;i<N;i++)
        scanf("%d",&a[i]);
    MergeSort(a,0,N-1);
    printf("%lld",count);

}
