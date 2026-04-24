#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    
    vector<pair<ll,int>> events;
    for(int i = 0; i < n; i++){
        ll l, r;
        cin >> l >> r;
        events.push_back({l, 1});
        events.push_back({r + 1, -1});
    }
    sort(events.begin(), events.end());
    
    ll ans = 0;
    int cur = 0;
    ll prev = 0;
    bool first = true;
    for(auto &[x, d] : events){
        if(!first && cur > 0) ans += (x - prev) * cur;
        cur += d;
        prev = x;
        first = false;
    }
    cout << ans << "\n";
    return 0;
}
