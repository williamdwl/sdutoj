#include<bits/stdc++.h>
using namespace std;  //超时原因:使用了cin，cout；建议在处理设计大量I/O运算的题目时，放弃使用cin/cout, 改用sanf/printf。,改为scanf，printf不超时
//若加上  std::ios::sync_with_stdio(false);则也能通过，避免了cin/cout的数据进入缓冲区，节省时间
/*
C++ 为了兼容 C，做了很多额外的工作，所以用 iostream 时有不少东西需要注意。
为了支持 cout / cin 和 printf / scanf 混用，cout / cin 的每一次 IO 操作完成后都会将内部缓冲区和 printf / scanf 的缓冲区同步。
如果不混用，通过 std::ios::sync_with_stdio(false); 关闭同步操作，
可以显著提高速度。用 std::endl 代替 '\n' 会比较慢，因为 std::endl 的意思是「换行并清空缓冲区」。
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

        if(j<len && H->data[j] > H->data[j+1])//找出左右孩子中最小的孩子的下标
            j++;
        if(x<H->data[j])//若双亲节点比孩子节点都小，直接退出循环，即已经是最小跟堆。
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
        int t=H->data[1];//交换最小根，再调整最小根堆。
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
    for(int i=m/2;i>0;i--)//建立最下根堆，从下往上调整。从倒数第二层开始。上层大小的正确性由底层决定。
        HeapAdjust(H,i,m);

    for(int i=m+1;i<=n;i++)//将剩下的数字继续输入。若比最小即H->data[1]还小则直接无视。比最小还大，则调整根堆。
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
        (i==m)?printf("%d\n",H->data[i]):printf("%d ",H->data[i]);//三目运算符，  条件？结果一：结果二；注意结果一无分号
    }
    return 0;
}

