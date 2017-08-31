#include<bits/stdc++.h>
using namespace std;  //��ʱԭ��:ʹ����cin��cout�������ڴ�����ƴ���I/O�������Ŀʱ������ʹ��cin/cout, ����sanf/printf��,��Ϊscanf��printf����ʱ
//������  std::ios::sync_with_stdio(false);��Ҳ��ͨ����������cin/cout�����ݽ��뻺��������ʡʱ��
/*
C++ Ϊ�˼��� C�����˺ܶ����Ĺ����������� iostream ʱ�в��ٶ�����Ҫע�⡣
Ϊ��֧�� cout / cin �� printf / scanf ���ã�cout / cin ��ÿһ�� IO ������ɺ󶼻Ὣ�ڲ��������� printf / scanf �Ļ�����ͬ����
��������ã�ͨ�� std::ios::sync_with_stdio(false); �ر�ͬ��������
������������ٶȡ��� std::endl ���� '\n' ��Ƚ�������Ϊ std::endl ����˼�ǡ����в���ջ���������
*/


int n,m;
struct Heap{
    int data[12];
    int Size;
};

void HeapAdjust(Heap *H,int s,int len)
{
    int x=H->data[s];
    for(int j=2*s;j<=len;j*=2)
    {

        if(j<len && H->data[j] > H->data[j+1])//�ҳ����Һ�������С�ĺ��ӵ��±�
            j++;
        if(x<H->data[j])//��˫�׽ڵ�Ⱥ��ӽڵ㶼С��ֱ���˳�ѭ�������Ѿ�����С���ѡ�
            break;
        H->data[s]=H->data[j];
        s=j;

    }
    H->data[s]=x;
}

void HeapSort(Heap*H,int len)
{
    for(int i=len;i>=1;--i)
    {
        int t=H->data[1];//������С�����ٵ�����С���ѡ�
        H->data[1]=H->data[i];
        H->data[i]=t;
        HeapAdjust(H,1,i-1);
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    Heap *H=new Heap;
    cin>>n>>m;
    H->Size=m;
    for(int i=1;i<=m;i++)
        cin>>H->data[i];
    for(int i=m/2;i>0;i--)//�������¸��ѣ��������ϵ������ӵ����ڶ��㿪ʼ���ϲ��С����ȷ���ɵײ������
        HeapAdjust(H,i,m);

    for(int i=m+1;i<=n;i++)//��ʣ�µ����ּ������롣������С��H->data[1]��С��ֱ�����ӡ�����С������������ѡ�
    {
        int x;
        cin>>x;
        if(x>H->data[1])
        {
            H->data[1]=x;
   //         for(int j=m/2;j>0;j--)
            HeapAdjust(H,1,m);
        }
    }
    HeapSort(H,m);
    for(int i=1;i<=m;i++)
    {
        (i==m)?printf("%d\n",H->data[i]):printf("%d ",H->data[i]);//��Ŀ�������  ���������һ���������ע����һ�޷ֺ�
    }
    return 0;
}

