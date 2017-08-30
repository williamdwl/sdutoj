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
        node *head,*tail,*p,*temp;
        int n,a,i,del,cot=0;
        cin>>n;

        cout<<n<<endl;
        head=(node*)malloc(sizeof(node));
        head->next=NULL;
        tail=head;
        for(i=1;i<=n;i++){
                p=(node*)malloc(sizeof(node));
                cin>>a;
//                cout<<a<<" ";
                p->data=a;
                p->next=NULL;
                tail->next=p;
                tail=p;
        }
        p=head->next;
        print(p);

        cin>>del;
        p=head;
        while(p->next){
                if(p->next->data==del){
                        cot++;
                        temp=p->next;
                        p->next=temp->next;
                        free(temp);
                }
                p=p->next;
        }
        cout<<n-cot<<endl;
        p=head->next;
        print(p);
        return 0;
}
