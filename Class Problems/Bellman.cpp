#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S)
    {
        vector<int> dist(V+1, 1e9);
        dist[S] = 0;
        for (int i = 0; i < V; i++)
        {
            for (auto it : edges)
            {
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                if (dist[u] != 1e9 && dist[u] + wt < dist[v])
                {
                    dist[v] = dist[u] + wt;
                }
            }
        }
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if (dist[u] != 1e9 && dist[u] + wt < dist[v])
            {
                return {-1};
            }
        }
        return dist;
    }
};

int main()
{
    int V, E;
    cin >> V >> E;

    vector<vector<int>> edges;

    for (int i = 0; i < E; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back({u, v, wt});
    }

    int S=1;

    Solution obj;
    vector<int> ans = obj.bellman_ford(V, edges, S);

    if (ans.size() == 1 && ans[0] == -1)
    {
        cout << "Negative cycle detected\n";
    }
    else
    cout<< "Answer" << "\n";
    {
        for (int i=1;i<ans.size();i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
