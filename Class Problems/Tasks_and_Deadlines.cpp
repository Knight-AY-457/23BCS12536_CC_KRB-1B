#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<pair<long long, long long>> tasks(n);
    for (int i = 0; i < n; i++) {
        cin >> tasks[i].first >> tasks[i].second;
    }

    sort(tasks.begin(), tasks.end(), [](auto& a, auto& b) {
        return a.first < b.first;
    });

    long long time_now = 0, reward = 0;

    for (auto& [dur, deadline] : tasks) {
        time_now += dur;
        reward += deadline - time_now;
    }

    cout << reward << "\n";

    return 0;
}
