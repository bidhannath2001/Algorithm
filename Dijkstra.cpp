//usiing adjacency list and  priority queue

#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#define ll long long int
using namespace std;

const ll INF = 1e18;
ll dist[100005], path[100005];
vector<ll>adj[100005];
map<pair<ll,ll>,ll>mp;
priority_queue<ll>pq;
ll V,E,i,j,u,v,w;

void printPath(ll j) {
    if(j!=1) printPath(path[j]);
    cout<<j<<' ';
}

void dijkstra(int V, int S) {

    for (i=2; i<=V; i++)
        dist[i]=INF;

    dist[S] = 0;
    pq.push(S);
    while (pq.size()) {
        u = pq.top();
        pq.pop();
        for (const auto& edge : adj[u]) {
            v = edge;
            w = mp[{u,v}];
            if (dist[u]+w<dist[v]) {
                dist[v] = dist[u] + w;
                path[v] = u;
                pq.push(v);
            }
        }
    }
    if (dist[V] == INF) {
        cout << "-1" << endl;
        return;
    } 
    else {
        printPath(V);
    }
}

int main() {
    cin >> V >> E;
    while (E--)
    {
        cin>>u>>v>>w;
        adj[u].push_back(v);
        adj[v].push_back(u);
        mp[{u,v}] = w;
        mp[{v,u}] = w;
    }
    
    int S = 1;
    dijkstra(V, S);
    return 0;
}
