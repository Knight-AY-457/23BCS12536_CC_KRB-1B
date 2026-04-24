#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    ll S;
    cin >> n >> S;
    
    vector<ll> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    
    auto check = [&](int k) -> pair<bool, ll> {
        vector<ll> cost(n + 1);
        for(int i = 1; i <= n; i++) cost[i] = a[i] + (ll)i * k;
        sort(cost.begin() + 1, cost.end());
        ll total = 0;
        for(int i = 1; i <= k; i++) total += cost[i];
        return {total <= S, total};
    };
    
    int lo = 0, hi = n;
    while(lo < hi){
        int mid = (lo + hi + 1) / 2;
        if(check(mid).first) lo = mid;
        else hi = mid - 1;
    }
    
    cout << lo << " " << check(lo).second << "\n";
    return 0;
}
