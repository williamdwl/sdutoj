#include<iostream>
#include<stdio.h>
using namespace std;

//#define LOCAL

struct node
{
        int data;
        struct node* next;
};

void InitNode(node* &Node)
{
        Node = new node;
        Node->next = NULL;
}

void Print(node* &header)
{
        node*q;
        InitNode(q);
        q = header->next;
        while (q != NULL)
        {
                if(q->next==NULL)//格式问题
                        cout<<q->data;
                else
                        cout << q->data << " ";
                q = q->next;
        }

}

int main()
{

#ifdef LOCAL
        freopen("in.txt", "r", stdin);
#endif // LOCAL

        int n, m, d, cot = 0;

        node*header1;
        node*header2;
        node*q1;
        node*q2;

        InitNode(header1);
        InitNode(header2);
        InitNode(q1);
        InitNode(q2);

        q1 = header1;

        cin >> n;
        m = n;
        while (m--)
        {
                cin >> d;
                node*p;
                InitNode(p);
                p->data = d;
                q1->next = p;
                q1 = p;
        }

        q1 = header1;
        q2 = header2;

        while (q1->next != NULL)
        {
                if ((q1->next->data) % 2 != 0)
                {
                        cot++;
                        node*p;
                        InitNode(p);
                        p->data = q1->next->data;
                        q2->next = p;
                        q2 = p;
                        if (q1->next->next != NULL)
                        {
                                q1->next = q1->next->next;
                        }
                        else
                        {
                                q1->next = NULL;
                        }

                }
                else
                {
                        q1 = q1->next;
                }
        }
        cout << n - cot << " " << cot << endl;
        Print(header1);
        cout << endl;
        Print(header2);
}
