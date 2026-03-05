#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> vis;

void dfs(int node){
    vis[node] = 1;
    for(int x : adj[node]){
        if(!vis[x]) dfs(x);
    }
}

int main(){
    int n,m;
    cin>>n>>m;

    adj.resize(n+1);
    vis.resize(n+1,0);

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> comp;

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            comp.push_back(i);
            dfs(i);
        }
    }

    cout<<comp.size()-1<<"\n";

    for(int i=1;i<comp.size();i++){
        cout<<comp[i-1]<<" "<<comp[i]<<"\n";
    }
}