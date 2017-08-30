#include<iostream>
#include<stdio.h>
using namespace std;
//#define LOCAL

struct node{
        int data;
        struct node*next;

};

void InitNode(node* &Node)
{
        Node = new node;
        Node->next=NULL;
}

int main()
{
        #ifdef LOCAL
                freopen("in.txt","r",stdin);
        #endif

        int n,nn,d,temp;
        node*header;
        node*q;
        InitNode(header);
        InitNode(q);

        cin>>n;
        nn=n;
        q=header;
        while(nn--)
        {
              cin>>d;
              node*p;
              InitNode(p);
              p->data=d;
              q->next=p;
              q=p;
        }
        q=header->next;
        while(q!=NULL)
        {
                node*p;
                InitNode(p);
                if(q->next!=NULL)
                        p=q->next;
                else
                        break;
                while(p!=NULL)
                {
                        if(q->data>p->data)
                        {
                                temp=p->data;
                                p->data=q->data;
                                q->data=temp;
                        }
                        p=p->next;
                }
                q=q->next;
        }
        q=header->next;
        while(q!=NULL)
        {
                cout<<q->data<<" ";
                q=q->next;
        }
}
