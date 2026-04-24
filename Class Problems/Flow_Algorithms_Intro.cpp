#include <bits/stdc++.h>
using namespace std;

class EdmondsKarp {
public:
    int n, source, sink;
    vector<vector<int>> capacity;
    vector<vector<int>> flow;

    EdmondsKarp(int n, int source, int sink) : n(n), source(source), sink(sink) {
        capacity.assign(n, vector<int>(n, 0));
        flow.assign(n, vector<int>(n, 0));
    }

    void addEdge(int u, int v, int cap) {
        capacity[u][v] = cap;
    }

    int bfs(vector<int>& parent) {
        fill(parent.begin(), parent.end(), -1);
        parent[source] = -2;
        queue<pair<int, int>> q;
        q.push({source, INT_MAX});

        while (!q.empty()) {
            int cur = q.front().first;
            int flow = q.front().second;
            q.pop();

            for (int next = 0; next < n; ++next) {
                if (parent[next] == -1 && capacity[cur][next] - this->flow[cur][next] > 0) {
                    parent[next] = cur;
                    int new_flow = min(flow, capacity[cur][next] - this->flow[cur][next]);
                    if (next == sink) return new_flow;
                    q.push({next, new_flow});
                }
            }
        }
        return 0;
    }

    int maxFlow() {
        vector<int> parent(n);
        int max_flow = 0;
        int new_flow;

        while ((new_flow = bfs(parent)) > 0) {
            max_flow += new_flow;
            int cur = sink;
            while (cur != source) {
                int prev = parent[cur];
                flow[prev][cur] += new_flow;
                flow[cur][prev] -= new_flow;
                cur = prev;
            }
        }
        return max_flow;
    }
};

int main() {
    int n = 6, source = 0, sink = 5;
    EdmondsKarp ek(n, source, sink);
    ek.addEdge(0, 1, 16);
    ek.addEdge(0, 2, 13);
    ek.addEdge(1, 2, 10);
    ek.addEdge(1, 3, 12);
    ek.addEdge(2, 1, 4);
    ek.addEdge(2, 4, 14);
    ek.addEdge(3, 2, 9);
    ek.addEdge(3, 5, 20);
    ek.addEdge(4, 3, 7);
    ek.addEdge(4, 5, 4);
    cout << ek.maxFlow() << endl;
    return 0;
}
