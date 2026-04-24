#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<long long> cnt(n + 1, 0), bad(n + 1, 0);
    vector<long long> diff_cnt(n + 2, 0), diff_bad(n + 2, 0);

    for (int j = 0; j < n; j++) {
        long long reach = min(a[j], (long long)(n - j));

        diff_cnt[j] += 1;
        diff_cnt[j + reach] -= 1;


        if (a[j] <= n - j) {
            diff_bad[j + a[j] - 1] += 1;
        }
    }


    long long c = 0, b = 0;
    for (int i = 0; i < n; i++) {
        c += diff_cnt[i];
        b += diff_bad[i];
        cout << c << " " << b << "\n";
    }

    return 0;
}
