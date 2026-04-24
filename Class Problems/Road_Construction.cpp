#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
public:
    vector<int> size, parent;
    int components;
    int maxSize;

    DisjointSet(int N) {
        size.resize(N + 1, 1);
        parent.resize(N + 1);
        components = N;
        maxSize = 1;

        for (int i = 1; i <= N; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);

        if (pu == pv) return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
            maxSize = max(maxSize, size[pv]);
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
            maxSize = max(maxSize, size[pu]);
        }

        components--;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    DisjointSet ds(N);

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;

        ds.unionBySize(u, v);

        cout << ds.components << " " << ds.maxSize << "\n";
    }

    return 0;
}
