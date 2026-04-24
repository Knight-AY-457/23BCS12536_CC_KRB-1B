#define P pair<int, pair<int, int>>
class DisjointSet {
   public:
    vector<int> size;
    vector<int> parent;

    DisjointSet(int N) {
        size.resize(N, 1);
        parent.resize(N);
        for (int i = 0; i < N; i++) {
            parent[i] = i;
        }
    }
    bool find(int u, int v) { return findUPar(u) == findUPar(v); }
    int findUPar(int i) {
        if (parent[i] == i) {
            return i;
        }
        return parent[i] = findUPar(parent[i]);
    }
    void unionBySize(int u, int v) {
        int ul_u = findUPar(u);
        int ul_v = findUPar(v);
        if(ul_u==ul_v) return;
        if (size[ul_u] < size[ul_v]) {
            parent[ul_u] = ul_v;
            size[ul_v] += size[ul_u];
        }
        else {
        parent[ul_v] = ul_u;
        size[ul_u] += size[ul_v];
        }
    }
};

class Solution {
   public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<P> edges;
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                int adjN = it[0];
                int wt = it[1];
                edges.push_back({wt, {adjN, i}});
            }
        }
        sort(edges.begin(), edges.end());
        DisjointSet ds(V);
        int weight = 0;
        for (auto it : edges) {
            int wt = it.first;
            int curr = it.second.first;
            int parent = it.second.second;

            if (!ds.find(curr, parent)) {
                weight += wt;
                ds.unionBySize(curr, parent);
            }
        }
        return weight;
    }
};
