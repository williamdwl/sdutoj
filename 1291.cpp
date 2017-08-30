#include<stdio.h>
#include<iostream>

using namespace std;

int n=0;
int flag=0;
char post[100];
int locationInMid(char*mid,int ms,int me,char preps){//找出相对的根节点
        int i;
        for(i=ms;i<=me;i++){
                if(mid[i]==preps)
                        return i;
        }
        return -1;//表示没找到；
}
void postOrder(char* pre,int ps,int pe,char* mid,int ms,int me){
//        cout<<"我在递归"<<endl;
        post[--n]=pre[ps];//逆着保存后序遍历节点
        int hm=locationInMid(mid,ms,me,pre[ps]);
 //       cout<<hm<<endl;
        if(hm==-1)
        {
        //  printf("No\n");
                flag=-1;
                return ;
        }
        else
        {

                int cr=me-hm;//相对根节点的右边
                int cl=hm-ms;//相对根节点的左边
                if(cr>0)//从右边开始
                {    //   cout<<cr<<endl;
                     //   cout<<ps+cr+1<<" "<<pe<<" "<<hm+1<<" "<<me<<endl;
                        postOrder(pre,ps+cl+1,pe,mid,hm+1,me);//处理好加1还是不加，带入检查！
                }
                if(cl>0)
                {
                      //  cout<<ps+1<<" "<<pe+cr<<" "<<ms<<" "<<hm-1<<endl;
                        postOrder(pre,ps+1,ps+cl,mid,ms,hm-1);
                }
        }
}
int main(){
        char pre[100];//放在main函数里，默认初值随机数。放在main函数外，默认初值为0.
        char mid[100];
 //       freopen("in.txt","r",stdin);
//        freopen("out.txt","w",stdout);
        int i=0,t;

//        cout<<"开始输入"<<endl;
        while((pre[i]=getchar())!='\n')
        {
//                cout<<"我在输入pre"<<endl;

                i++;

        }
 //       cout<<"i="<<i<<endl;
        n=i;
        t=n;
//        for(i=0;i<t;i++){
//                cout<<pre[i];
//        }

        i=0;
        while((mid[i]=getchar())!=-1)
        {
//                cout<<"我在输入mid"<<endl;

                i++;
        }
//        cout<<"i="<<i<<endl;
//        for(i=0;i<t;i++){
//                cout<<mid[i];
//        }
 //       cout<<"输入完成"<<endl;

        postOrder(pre,0,n-1,mid,0,n-1);

//        cout<<"我递归好了"<<endl;
        for(i=0;i<t;i++){
                cout<<post[i];
        }
        return 0;
}
