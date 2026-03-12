#include <bits/stdc++.h>
using namespace std;

vector<int> topoSort(int V, vector<int> adj[]) {

    vector<int> indegree(V,0);

    for(int i=0;i<V;i++){
        for(int v: adj[i]){
            indegree[v]++;
        }
    }

    queue<int> q;

    for(int i=0;i<V;i++){
        if(indegree[i]==0)
            q.push(i);
    }

    vector<int> topo;

    while(!q.empty()){

        int node=q.front();
        q.pop();

        topo.push_back(node);

        for(int v: adj[node]){
            indegree[v]--;

            if(indegree[v]==0)
                q.push(v);
        }
    }

    return topo;
}