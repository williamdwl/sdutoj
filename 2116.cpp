#include<iostream>
#include<stdio.h>
using namespace std;

//#define LOCAL

struct node
{
        struct node *next;
        int data;
};


int main()
{
        int n, d;
        #ifdef LOCAL
                freopen("in.txt","r",stdin);
        #endif // LOCAL
        cin >> n;
        node* header = new node;
        header->next = NULL;
        node*q = new node;
        q->next = NULL;
        q=header;
        for (int i = 0; i < n; i++)//
        {
                cin >> d;
                node*p = new node;
                p->next = NULL;
                p->data = d;
                q->next = p;
                q = p;
        }
        q = header->next;
        while (q != NULL)
        {
                cout << q->data << " ";
                q = q->next;
        }
        return 0;
}
