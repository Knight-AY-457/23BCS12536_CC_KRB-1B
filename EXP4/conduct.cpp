#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& a) {
    const int MOD = 1e9;
    int n = a.size();
    long long ans = 0;

    for (int bit = 0; bit < 32; bit++) {
        long long count1 = 0;

        for (int i = 0; i < n; i++) {
            if (a[i] & (1 << bit))
                count1++;
        }

        long long count0 = n - count1;

        ans = (ans + (2LL * count1 * count0) % MOD) % MOD;
    }

    return ans;
}

int main() {
    vector<int> a = {1,3,5};
    cout << solve(a);
}