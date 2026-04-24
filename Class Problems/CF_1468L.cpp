#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int k;
        cin >> k;
        vector<int> a(k);
        for(auto &x : a) cin >> x;
        
        auto primeFactors = [](int n) -> set<int> {
            set<int> res;
            for(int p = 2; (long long)p * p <= n; p++){
                if(n % p == 0){
                    res.insert(p);
                    while(n % p == 0) n /= p;
                }
            }
            if(n > 1) res.insert(n);
            return res;
        };
        
        map<int,int> primeCnt;
        for(int x : a){
            auto factors = primeFactors(x);
            for(int p : factors) primeCnt[p]++;
        }
        
        bool ideal = true;
        for(auto &[p, cnt] : primeCnt){
            if(cnt == 1){
                ideal = false;
                break;
            }
        }
        
        cout << (ideal ? "Ideal" : "Not ideal") << "\n";
    }
    return 0;
}
