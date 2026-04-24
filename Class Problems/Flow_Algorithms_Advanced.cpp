#include <bits/stdc++.h>
using namespace std;

class BipartiteMatching {
public:
    int n, m, source, sink;
    vector<vector<int>> capacity;
    vector<vector<int>> flow;
    vector<int> level, ptr;

    BipartiteMatching(int n, int m) : n(n), m(m), source(0), sink(n + m + 1) {
        capacity.assign(n + m + 2, vector<int>(n + m + 2, 0));
        flow.assign(n + m + 2, vector<int>(n + m + 2, 0));
        level.resize(n + m + 2);
        ptr.resize(n + m + 2);
    }

    void addEdge(int u, int v) {
        capacity[u + 1][v + 1 + n] = 1;
    }

    bool bfs() {
        fill(level.begin(), level.end(), -1);
        level[source] = 0;
        queue<int> q;
        q.push(source);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v = 0; v <= n + m + 1; ++v) {
                if (level[v] == -1 && capacity[u][v] - flow[u][v] > 0) {
                    level[v] = level[u] + 1;
                    q.push(v);
                }
            }
        }
        return level[sink] != -1;
    }

    int dfs(int u, int push) {
        if (u == sink || push == 0) return push;
        for (int& i = ptr[u]; i <= n + m + 1; ++i) {
            int v = i;
            if (level[v] == level[u] + 1 && capacity[u][v] - flow[u][v] > 0) {
                int f = dfs(v, min(push, capacity[u][v] - flow[u][v]));
                if (f > 0) {
                    flow[u][v] += f;
                    flow[v][u] -= f;
                    return f;
                }
            }
        }
        return 0;
    }

    int maxMatching() {
        for (int i = 1; i <= n; ++i) capacity[source][i] = 1;
        for (int i = 1; i <= m; ++i) capacity[i + n][sink] = 1;
        int matching = 0;
        while (bfs()) {
            fill(ptr.begin(), ptr.end(), 0);
            int f;
            while ((f = dfs(source, INT_MAX)) > 0) {
                matching += f;
            }
        }
        return matching;
    }
};

int main() {
    int n = 3, m = 3;
    BipartiteMatching bm(n, m);
    bm.addEdge(0, 0);
    bm.addEdge(0, 1);
    bm.addEdge(1, 1);
    bm.addEdge(1, 2);
    bm.addEdge(2, 0);
    cout << bm.maxMatching() << endl;
    return 0;
}
