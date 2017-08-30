#include<iostream>
#include<stdio.h>
using namespace std;

//#define LOCAL

struct node
{
        int data;
        struct node* next;
};

node *InitLink(int x)
{
        int d;
        node*header = new node;
        header->next = NULL;
        node*q = new node;
        q->next = NULL;
        q = header;
        while (x--)
        {
                node*p = new node;
                p->next = NULL;
                cin >> d;
                p->data = d;
                q->next = p;
                q = p;
        }
        return header;
}
void InitNode(node* &Node)//要用引用，否则是值传递，或者**
{
        Node = new node;
        Node->next = NULL;

}

int main()
{
#ifdef LOCAL
        freopen("in.txt", "r", stdin);
#endif // LOCAL
        int n, m;
        cin >> n >> m;
        node*header, *header2, *header3, *q, *l, *k;

        InitNode(header);
        InitNode(header2);
        InitNode(header3);
        InitNode(q);
        InitNode(l);
        InitNode(k);

        header = InitLink(n);
        header2 = InitLink(m);

        l = header->next;
        k = header2->next;
#ifdef LOCAL
        //                while(l!=NULL)
        //                {
        //                        cout<<l->data<<" ";
        //                        l=l->next;
        //                }
#endif // LOCAL
        q = header3;
#ifdef LOCAL
        cout << "I am OK" << endl;
#endif // LOCAL
        while (l != NULL || k != NULL)
        {
#ifdef LOCAL
                cout << "I am OK3" << endl;
#endif // LOCAL
                if (k == NULL && l != NULL)
                {
                        node*p;
                        InitNode(p);
                        p->data = l->data;
                        q->next = p;
                        q = p;
                        l = l->next;
                }
                else if (l == NULL && k != NULL)
                {
                        node*p;
                        InitNode(p);
                        p->data = k->data;
                        q->next = p;
                        q = p;
                        k = k->next;
                }
                else if ( l->data < k->data )
                {
                        node*p;
                        InitNode(p);
                        p->data = l->data;
                        q->next = p;
                        q = p;
                        l = l->next;
                }
                else if ( l->data >= k->data)
                {
                        node*p;
                        InitNode(p);
                        p->data = k->data;
                        q->next = p;
                        q = p;
                        k = k->next;
                }
#ifdef LOCAL
                cout << "I am OK4" << endl;
#endif // LOCAL
        }
#ifdef LOCAL
        cout << "I am OK2" << endl;
#endif // LOCAL
        q = header3->next;
        while (q != NULL)
        {
                cout << q->data << " ";
                q = q->next;
        }

        return 0;
}
