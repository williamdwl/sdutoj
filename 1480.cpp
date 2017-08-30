#include<iostream>
using namespace std;
struct node{
        int num;
        int data;
        struct node*next;
}*head[100010];//头结点指针
int main(){
        int i,n,m,y,mnum=0,mdata=100000000;
        node*p,*q,*r;
        cin>>n;
        for(i=0;i<100000;i++)
        {

                head[i]=new node;
                head[i]->next=NULL;
        }
        for(i=0;i<n;i++)
        {
               // cout<<"进来了"<<endl;
                cin>>m;
                y=m%100000;
                p=head[y];
                q=head[y]->next;
                while(q!=NULL)//数是否存在，不存在就新建
                {
                        // cout<<"jinlail"<<endl;
                       if(q->data==m)
                       {
                             //  cout<<"jinlail"<<endl;
                               q->num++;
                               if((q->num)>mnum)
                               {
                                       mnum=q->num;
                                       mdata=q->data;
                               }else if(q->num==mnum)
                               {
                                       if(q->data<mdata)
                                                mdata=q->data;
                               }
                               break;
                       }
                       p=q;
                       q=q->next;
                }
                // cout<<"出来了w"<<endl;
                if(q==NULL)
                {
                        r=new node;
                        r->num=1;
                        r->data=m;
                        r->next = NULL;
                        p->next=r;
                        if(r->num>mnum)
                        {
                               mnum=r->num;
                               mdata=r->data;
                        }else if(r->num==mnum)
                        {
                               if(r->data<mdata)
                                        mdata=r->data;
                        }
                }
               // cout<<"出来了"<<endl;
        }
        cout<<mdata<<' '<<mnum;

        return 0;
}
