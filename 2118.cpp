#include<iostream>
#include<stdio.h>
using namespace std;

//#define LOCAL

struct node{
        int data;
        node* next;
};

int main(){
        #ifdef LOCAL
                freopen("in.txt","r",stdin);
        #endif // LOCAL
        node* header =new node;
        header->next=NULL;
        node* header2 =new node;
        header2->next=NULL;
        node* l =new node;
        l->next=NULL;
        node* q =new node;
        q->next=NULL;
        q=header;
        int d;
        while(scanf("%d",&d)!=-1){//初始化
                node* p =new node;
                p->next=NULL;
                p->data=d;
                q->next=p;
                q=p;
        }
        #ifdef LOCAL
 //               cout<<"chulaile"<<endl;
        #endif // LOCAL
        q=header->next;
        while(q->data!=-1){
                node* p =new node;
                p->next=NULL;
                header2->data=q->data;
                p->next=header2;
                header2=p;
                q=q->next;
        }
        l=header2->next;
        while(l!=NULL){
                cout<<l->data<<" ";
                l=l->next;
        }
        #ifdef LOCAL
 //               cout<<"chulaile2"<<endl;
        #endif // LOCAL
        return 0;
}
