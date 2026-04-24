#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int q;
        cin >> q;
        
        map<char,ll> scnt, tcnt;
        scnt['a'] = 1;
        tcnt['a'] = 1;
        ll sLen = 1, tLen = 1;
        
        auto canBeLess = [&]() -> bool {
            char sMin = 'z', tMax = 'a';
            for(auto &[c, v] : scnt) if(v > 0) sMin = min(sMin, c);
            for(auto &[c, v] : tcnt) if(v > 0) tMax = max(tMax, c);
            if(sMin < tMax) return true;
            if(sMin > tMax) return false;
            if(sLen < tLen) return true;
            return false;
        };
        
        while(q--){
            int type;
            ll k;
            string x;
            cin >> type >> k >> x;
            
            char mn = *min_element(x.begin(), x.end());
            char mx = *max_element(x.begin(), x.end());
            
            if(type == 1){
                for(char c : x) scnt[c] += k;
                sLen += k * (ll)x.size();
            } else {
                for(char c : x) tcnt[c] += k;
                tLen += k * (ll)x.size();
            }
            cout << (canBeLess() ? "YES" : "NO") << "\n";
        }
    }
    return 0;
}
