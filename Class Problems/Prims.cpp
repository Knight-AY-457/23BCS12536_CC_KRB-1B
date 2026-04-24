#include<bits/stdc++.h>
using namespace std;

int main(){
    int V, E;
    cin >> V >> E;

    vector<vector<pair<int,int>>> adj(V);

    for(int i = 0; i < E; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    vector<int>  key(V, INT_MAX);
    vector<bool> inMST(V, false);
    vector<int>  parent(V, -1);

    key[0] = 0;
    pq.push({0, 0});

    int totalWeight = 0;

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();

        if(inMST[u]) continue;
        inMST[u] = true;
        totalWeight += key[u];

        for(auto [v, w] : adj[u]){
            if(!inMST[v] && w < key[v]){
                key[v]    = w;
                parent[v] = u;
                pq.push({w, v});
            }
        }
    }

    for(int i = 1; i < V; i++){
        cout << parent[i] << " - " << i << "  (weight: " << key[i] << ")\n";
    }
    cout << "Total MST Weight: " << totalWeight << endl;

    return 0;
}
