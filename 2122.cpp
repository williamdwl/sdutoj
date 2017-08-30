#include<iostream>
#include<stdio.h>
using namespace std;

//#define LOCAL

struct node
{
        int data;
        struct node*next;
};

void InitNode(node* &Node)
{
        Node = new node;
        Node->next = NULL;
}

int main()
{
#ifdef LOCAL
        freopen("in.txt", "r", stdin);
#endif // LOCAL
        int n, nn, d, cot = 0;
        node*header;
        node*q;
        InitNode(header);
        InitNode(q);
        cin >> n;
        cout << n << endl;
        nn = n;
        while (nn--)
        {
                cin >> d;
                node*p;
                InitNode(p);
                header->data = d;
                p->next = header;
                header = p;
        }

        q = header->next;
        while (q != NULL)
        {
                if(q->next==NULL)
                        cout << q->data;
                else
                        cout << q->data << " ";
                q = q->next;
        }
        cout << endl;
        q = header;
        while (q->next != NULL)
        {
                node*p;
                InitNode(p);
                if (q->next->next != NULL)
                {
                        p = q->next;
                }
                else
                {
                        break;
                }
                while (p->next != NULL)
                {
                        if (q->next->data == p->next->data)
                        {
                                cot++;
                                if (p->next->next != NULL)
                                {
                                        p->next = p->next->next;
                                }
                                else
                                {
                                        p->next = NULL;
                                }
                        }else
                                p = p->next;
                }
                q = q->next;
        }
        q = header->next;
        cout << n - cot << endl;
        while (q != NULL)
        {
                if(q->next==NULL)
                        cout << q->data;
                else
                        cout << q->data << " ";
                q = q->next;
        }
        return 0;
}
