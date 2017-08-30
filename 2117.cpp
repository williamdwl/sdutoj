#include<stdio.h>
#include<iostream>
using namespace std;

//#define LOCAL

struct node
{
        int data;
        node* next;
};

int main()
{
        int n, d;
#ifdef LOCAL
        freopen("in.txt", "r", stdin);
#endif // LOCAL
        cin >> n;
        node *header = new node;
        header->next = NULL;
        node *header2 = new node;
        header2->next = NULL;
        node *l = new node;
        l->next = NULL;
        node *q = new node;
        q->next = NULL;
        q = header;
        for (int i = 0; i < n; i++)
        {
                cin >> d;
                node* p = new node;
                p->next = NULL;
                p->data = d;
                q->next = p;
                q = p;
        }
        q = header->next;


        while (q)
        {


                node* p = new node;
                p->next = NULL;
                header2->data = q->data;//与链表逆置不同，传的是数据
 //               header2->next=NULL;
                p->next = header2;
                header2 = p;
                #ifdef LOCAL

                #endif // LOCA
                q = q->next;

        }


        l = header2->next;

        while (l)
        {
                cout << l->data<<" ";
                l = l->next;
        }
        return 0;
}
