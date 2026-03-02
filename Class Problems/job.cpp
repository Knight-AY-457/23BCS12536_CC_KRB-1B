#include<bits/stdc++.h>
using namespace std;
vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
    int n = deadline.size();
    vector<int> ans = {0, 0};
    vector<pair<int, int>> jobs;
    for (int i = 0; i < n; i++) {
        jobs.push_back({deadline[i], profit[i]});
    }
    sort(jobs.begin(), jobs.end());
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < jobs.size(); i++) {
        if (jobs[i].first > pq.size())
            pq.push(jobs[i].second);
        else if (!pq.empty() && pq.top() < jobs[i].second) {
            pq.pop();
            pq.push(jobs[i].second);
        }
    }
    while (!pq.empty()) {
        ans[1] += pq.top();
        pq.pop();
        ans[0]++;
    }
    return ans;
}
int main() {
    vector<int> deadline = {2, 1, 2, 1, 1};
    vector<int> profit = {100, 19, 27, 25, 15};
    vector<int> ans = jobSequencing(deadline, profit);
    cout<<ans[0]<<" "<<ans[1];
    return 0;
}
