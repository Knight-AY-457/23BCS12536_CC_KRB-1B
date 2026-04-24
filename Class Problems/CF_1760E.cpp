#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(auto &x : a) cin >> x;

        ll totalOnes = 0;
        for(int x : a) totalOnes += x;

        ll base = 0;
        {
            ll ones = 0;
            for(int i = 0; i < n; i++){
                if(a[i] == 0) base += ones;
                else ones++;
            }
        }

        ll ans = base;
        ll ones_before = 0;
        ll zeros_before = 0;
        for(int i = 0; i < n; i++){
            ll zeros_after = (n - i - 1) - (totalOnes - ones_before - a[i]);
            ll ones_after = totalOnes - ones_before - a[i];
            if(a[i] == 0){
                ll gain = ones_after - ones_before;
                ans = max(ans, base + ones_before - ones_after);
            } else {
                ans = max(ans, base - ones_before + zeros_after);
            }
            if(a[i] == 1) ones_before++;
            else zeros_before++;
        }
        cout << ans << "\n";
    }
    return 0;
}
