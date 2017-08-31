#include<stdio.h>
#include<stdlib.h>
long long int count=0;
void Merge(int a[],int low,int mid,int high)
{
    int i=low;//��һ�����е��±�
    int j=mid+1;//�ڶ������е��±�
    int k=0;//�ݴ�������±�
    int *b=(int*)malloc((high-low+1)*sizeof(int));
    while(i<=mid && j<= high)//�жϵ�һ�κ͵ڶ���ȡ��������һ����С���������ϲ����У����������±���
    {
        if(a[i]<=a[j])
            b[k++]=a[i++];
        else{
            b[k++]=a[j++];
            count+=(mid-i+1);//������ԣ���������������a[i]>a[j]����a[i]���Ԫ�ؽԴ���a[j]��
        }
    }
    while(i<=mid)//����һ�����л�û�����꣬��ʣ��ȫ�����Ƶ��ϲ�����
        b[k++]=a[i++];
    while(j<=high)//���ڶ������л�û�����꣬��ʣ��ȫ�����Ƶ��ϲ�����
        b[k++]=a[j++];
    for(k=0,i=low;i<=high;i++,k++)//���ϲ����и��Ƶ�ԭʼ������
        a[i]=b[k];
}

void MergeSort(int a[],int low,int high)//�ȵݹ飬�ٹ鲢
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        MergeSort(a,low,mid);
        MergeSort(a,mid+1,high);
        Merge(a,low,mid,high);//�鲢���ڵ�����
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
