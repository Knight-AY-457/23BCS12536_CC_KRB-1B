#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
   public:
    vector<int> rank;
    vector<int> size;
    vector<int> parent;

    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i < parent.size(); i++) {
            parent[i] = i;
        }
    }
    int findUlParent(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = findUlParent(parent[node]);
    }
    bool find(int u, int v) { return (findUlParent(u) == findUlParent(v)); }

    void unionByRank(int u, int v) {
        int ulp_u = findUlParent(u);
        int ulp_v = findUlParent(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_u] = ulp_v;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUlParent(u);
        int ulp_v = findUlParent(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

int main(){
    DisjointSet ds(7);

    DisjointSet ds2(5);
    ds2.unionBySize(1, 2);
    ds2.unionBySize(2, 3);
    ds2.unionBySize(4, 5);

    cout << ds2.find(1, 5) << "\n";
    ds2.unionBySize(3, 4);
    cout << ds2.find(1, 5) << "\n";

    return 0;
}
