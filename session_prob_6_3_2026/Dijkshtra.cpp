// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     vector<pair<int,int>>graph[6];
//     graph[1].push_back({2,2});
//     graph[1].push_back({3,4});
//     graph[1].push_back({3,1});
//     graph[1].push_back({4,7});
//     graph[1].push_back({5,3});
//     graph[1].push_back({4,1});

//     priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
//     dist[1]=0;
//     pq.push({0,1});
//     while(!pq.empty()){
//         auto it=pq.top();
//         pq.pop();
//         int node=it.second;
//         int cost=it.first;
//         for(auto adjnode:graph[node]){
//             int v=adjnode.first;
//             int wt=adjnode.second;
    
//         }
//     }
// }





#include<bits/stdc++.h>
using namespace std;

int main(){

    vector<pair<int,int>> graph[6];

    graph[1].push_back({2,2});
    graph[1].push_back({3,4});
    graph[1].push_back({3,1});
    graph[1].push_back({4,7});
    graph[1].push_back({5,3});
    graph[1].push_back({4,1});

    vector<int> dist(6,INT_MAX);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dist[1] = 0;
    pq.push({0,1});

    while(!pq.empty()){

        auto it = pq.top();
        pq.pop();

        int node = it.second;
        int cost = it.first;

        for(auto adjnode : graph[node]){

            int v = adjnode.first;
            int wt = adjnode.second;

            if(cost + wt < dist[v]){
                dist[v] = cost + wt;
                pq.push({dist[v], v});
            }
        }
    }

    for(int i=1;i<=5;i++){
        cout<<"Distance from 1 to "<<i<<" = "<<dist[i]<<endl;
    }
}