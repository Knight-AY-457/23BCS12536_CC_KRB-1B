#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        set<pair<int,pair<int,int>>> st;
        vector<int> dist(n, 1e9);

        // Build graph
        for (auto &e : flights) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
        }

        st.insert({0, {src, 0}});
        dist[src] = 0;

        while (!st.empty()) {
            auto it = *(st.begin());
            st.erase(it);

            int flightsTaken = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            if (flightsTaken > k) continue;

            for (auto &nbr : adj[node]) {
                int adjNode = nbr.first;
                int weight = nbr.second;

                if (cost + weight < dist[adjNode] && flightsTaken <= k) {
                    dist[adjNode] = cost + weight;
                    st.insert({flightsTaken + 1, {adjNode, dist[adjNode]}});
                }
            }
        }

        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};

int main() {
    int n, m;
    cout << "Enter number of cities and flights: ";
    cin >> n >> m;

    vector<vector<int>> flights(m, vector<int>(3));
    cout << "Enter flights (u v w):\n";
    for (int i = 0; i < m; i++) {
        cin >> flights[i][0] >> flights[i][1] >> flights[i][2];
    }

    int src, dst, k;
    cout << "Enter source, destination and max stops (k): ";
    cin >> src >> dst >> k;

    Solution obj;
    int result = obj.findCheapestPrice(n, flights, src, dst, k);

    cout << "Cheapest Price: " << result << endl;

    return 0;
}