#include"stdio.h"
#include <iostream>
#include <stdlib.h>
using namespace std;
struct node{
        node* next;
        int data;
};
int main(){
    int n,i,a,k=0;
    node *head,*tail,*p,*q,*temp,mabc;
    head=(node *)malloc(sizeof(node));
    head->next=NULL;//null要大写才对，NULL
    tail=head;
    cin>>n;
    for(i=1;i<=n;i++){
        p=(node*)malloc(sizeof(node));

        cin>>a;
        p->data=a;
        p->next=NULL;//尾节点要指NULL，安全。
        tail->next=p;
        tail=p;

    }
/*
    cout<<"26行ok"<<endl;



    p=head->next;
    cout<<n-k<<endl;
    while(p!=NULL){
        cout<<p->data<<endl;
        p=p->next;
    }
//测试输出
*/

    p=head->next;

    while(p){
        q=p;
        while(q->next){
                if(p->data!=q->next->data){
                       q=q->next;

                }else{
                       temp=q->next;
                       q->next=temp->next;
                       free(temp);
                       k++;

                }
        }
        p=p->next;
    }
    p=head->next;
    cout<<n-k<<endl;
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
    return 0;
}
