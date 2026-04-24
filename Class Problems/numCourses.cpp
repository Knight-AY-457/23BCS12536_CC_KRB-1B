#include<bits/stdc++.h>
using namespace std;

void DFS(int node, vector<int>& vis, stack<int>& st, vector<int> adj[]) {
    vis[node] = 1;
    for (auto it : adj[node]) {
        if (!vis[it]) {
            DFS(it, vis, st, adj);
        }
    }
    st.push(node);
}

vector<int> dfstopoSort(int V, vector<int> adj[]) {
    vector<int> vis(V, 0);
    stack<int> st;
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            DFS(i, vis, st, adj);
        }
    }
    vector<int> ans;
    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

int main(){

    int V = 4;
    vector<int> adj[4];
    adj[1].push_back(0);
    adj[2].push_back(0);
    adj[3].push_back(1);
    adj[3].push_back(2);
    vector<int> dfsans = dfstopoSort(V, adj);

    for (auto it : dfsans) cout << it << " ";

    return 0;
}
