#include<stdlib.h>
#include<iostream>
using namespace std;
struct node{
        int data;
        node*next;
};
void print(node* head){
        while(head){
                if(head->next==NULL)
                        cout<<head->data<<endl;
                else
                        cout<<head->data<<" ";
                head=head->next;
        }
}
int main(){
        node*head,*tail,*p,*q,*temp;
        int i,n,a,del,cot=0;
        tail=(node*)malloc(sizeof(node));
        tail->next=NULL;
        head=tail;
        cin>>n;
        cout<<n<<endl;
        p=(node*)malloc(sizeof(node));
        p->next=NULL;
        for(i=1;i<=n;i++){//容易乱，需要画图；
                cin>>a;

                p->data=a;

                head->next=p;

                p=(node*)malloc(sizeof(node));
                p->next=head->next;

        }
        p=head->next;
        print(p);

        p=head->next;

        while(p){
                q=p;
                while(q->next){
                        if(p->data!=q->next->data){
                                q=q->next;
                        }else{
                                cot++;
                                temp=q->next;
                                q->next=temp->next;
                                free(temp);
                        }

                }
                p=p->next;
        }
        cout<<n-cot<<endl;
        p=head->next;
        print(p);
        return 0;
}
