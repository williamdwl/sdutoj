#include<iostream>
#include<stdio.h>
#include<cstring>
#define MAX 50+3
using namespace std;
typedef char Elem_Type;
typedef struct BiTree{
        Elem_Type data;
        struct BiTree *Lchild;
        struct BiTree *Rchild;
}BiTree;
int Search_Num(Elem_Type num,Elem_Type *array,int len){
//        cout<<"我进来了"<<endl;
        for(int i=0;i<len;i++)
                if(array[i]==num)
                        return i;
        return -1;//没找到
}
BiTree *Resume_BiTree(Elem_Type *front,Elem_Type *center,int len){//还原树
        if(len<=0){
                return NULL;
        }
        BiTree *temp = new BiTree;
        temp->data = *front;
        int index=Search_Num(*front,center,len);
//        cout<<"我准备递归了"<<endl;
        temp->Lchild=Resume_BiTree(front+1,center,index);
//        cout<<"左孩子递归结束"<<endl;
        temp->Rchild=Resume_BiTree(front+index+1,center+index+1,len-index-1);
//        cout<<"右孩子递归结束"<<endl;
        return temp;
}

void PostOrderTraverse(BiTree *root){
        if(root!=NULL){
                PostOrderTraverse(root->Lchild);
                PostOrderTraverse(root->Rchild);
                cout<<root->data;
        }
}

int main(void){
        Elem_Type *preorder = new Elem_Type[MAX];
        Elem_Type *inorder = new Elem_Type[MAX];
//        freopen("in.txt","r",stdin);
//        freopen("out.txt","w",stdout);
        cin>>preorder;cin>>inorder;
//        cout<<"我输入好了"<<endl;
        BiTree *root=Resume_BiTree(preorder,inorder,strlen(inorder));
//        cout<<"我递归好了"<<endl;
        PostOrderTraverse(root);
        return 0;
}
