
#include <bits/stdc++.h>
using namespace std;

struct  node
{
    int data;
    node *next;
};
node *head[1010], *p;
void BFS(int s);
bool vis[1010];
int n, m, s;

int main()
{
    int k;
    cin >> k;
    for(int i = 0; i < 1010; i++)
    {
        head[i] = new node;
    }
    while(k --)
    {
     memset(vis, 0, sizeof(vis));
     cin >> n >> m >> s;
     for(int i = 0; i < n; i++)
        {
            head[i] -> next = NULL;
        }
        for(int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            p = new node;
            p -> data = v;
            p -> next = head[u] -> next;
            head[u] -> next = p;
            p = new node;
            p -> data = u;
            p -> next = head[v] -> next;
            head[v] -> next = p;
        }
        BFS(s);
        cout << endl;
    }
    return 0;
}

void BFS(int s)
{

    for(int i = 0; i < m; i++)//(同一个结点的同层邻接点，节点编号小的优先遍历）排序，将节点小的放在之前;
    {
        for(node *p = head[i] -> next; p; p = p -> next)
        {
            for(node *q = p -> next; q; q = q -> next)
            {
                if(p -> data > q -> data)
                {
                    int tmp = p -> data;
                    p -> data = q -> data;
                    q -> data = tmp;
                }
            }
        }
    }
    int q;
    queue<int >Q;
    Q.push(s);
    vis[s] = 1;
    while(!Q.empty())
    {
        cout << (q = Q.front()) << ' ';
        Q.pop();
        for(p = head[q] -> next; p; p = p -> next)
        {
            if(!vis[p -> data])
            {
                vis[p -> data] = 1;
                Q.push(p -> data);
            }
        }
    }

}
