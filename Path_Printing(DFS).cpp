#include<bits/stdc++.h>
using namespace std;

const int N = 2e5;
int visited[N] = {0};
vector<int>adj_list[N];
int parent_node[N];
stack<int>path_line;

void DFS(int node)
{
    visited[node] = 1;
    for(int adj_node : adj_list[node])
    {
        if(visited[adj_node] == 0){
            visited[adj_node] = 1;
            parent_node[adj_node] = node;
            DFS(adj_node);
        }
    }
}

void path_print(int src,int dst)
{
    path_line.push(dst);
    while(dst != src){
        int x = parent_node[dst];
        path_line.push(x);
        dst = x;
    }
}
int main()
{
    int nodes,edges;
    cin>>nodes>>edges;

    for(int i = 0;i<edges;i++){
        int u,v;
        cin>>u>>v;

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    int src = 1,dst = nodes;
    parent_node[src] = -1;
    DFS(src);

    path_print(src,dst);
    while(!path_line.empty()){
        cout<<path_line.top()<<" ";
        path_line.pop();
    }



    return 0;
}
