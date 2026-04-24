#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int x;
    cin >> x;

    int less_x = 0, eq_x = 0, greater_x = 0;
    for (int v : a) {
        if (v < x) less_x++;
        else if (v == x) greater_x++;
        else greater_x++;
    }

    less_x = 0; eq_x = 0; greater_x = 0;
    for (int v : a) {
        if (v < x) less_x++;
        else if (v == x) eq_x++;
        else greater_x++;
    }

    int ans = 0;
    if (eq_x == 0) {

        eq_x++;
        n++;
        ans++;
    }

    while (less_x != greater_x) {
        if (less_x < greater_x) { less_x++; }
        else { greater_x++; }
        ans++;
        n++;
    }
    cout << ans << "\n";
    return 0;
}
