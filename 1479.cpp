#include<iostream>
#include<stdio.h>
using namespace std;
#define  MAX  25000
typedef char StackItem;
typedef struct astack* Stack;
typedef struct astack{
        int top,maxtop;
        StackItem *data;
        char  paragraphmark;
};

Stack StackInit(int size){
        Stack S=new astack();
        S->top=-1;
        S->maxtop=size;
        S->data=new StackItem;//只要是一块数据。都要分配空间
        S->paragraphmark=0;
        return S;
}
int StackEmpty(Stack S){
        return (S->top)<0;
}
int StackFull(Stack S){
        return S->top=S->maxtop;
}
int main(){
        Stack S=StackInit(MAX);
        int i=0;
//        freopen("in.txt","r",stdin);
//        freopen("out.txt","w",stdout);
//        cout<<"i'm ok1"<<endl;
//        cout<<S->top<<endl;
        while((*((S->data)+i)=getchar())!=EOF){
//               cout<<"开始输入"<<endl;
//                count++;

                if(*((S->data)+i)=='\n')
                        S->paragraphmark=i+1;
//                if(count%3==0){
//                        S->paragraphmark=i+1;
//                        *((S->data)+i+1)=*((S->data)+i);
//                        *((S->data)+i)='\n';
//                        i++;
//                        count++;
//                }
                if(*((S->data)+i)=='#'){
                        if(*((S->data)+i-1)=='\n')
                                continue;
                        i--;
                        if(i<0)i=0;//考虑特殊情况，有多个退格，如：#####123456#abcdfg#
                        continue;
                }

                if(*((S->data)+i)=='@'){
                        i=S->paragraphmark;
                        continue;
                }

                i++;


        }
        S->top=i;
//        cout<<"i'm ok";
        for(i=0;i<(S->top);i++){


                cout<<*((S->data)+i);
        }
        return 0;
}
