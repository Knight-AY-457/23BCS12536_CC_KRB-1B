#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    map<pair<int,int>, int> cnt;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        cnt[{a, b}]++;
    }
    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << cnt[{a, b}] << "\n";
    }
    return 0;
}
