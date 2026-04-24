#include <bits/stdc++.h>
using namespace std;

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
        
        vector<int> freq(n + 1, 0);
        for(int x : a) freq[x]++;
        
        vector<bool> special(n + 1, false);
        
        for(int l = 0; l < n; l++){
            int sum = a[l];
            for(int r = l + 1; r < n; r++){
                sum += a[r];
                if(sum > n) break;
                special[sum] = true;
            }
        }
        
        int ans = 0;
        for(int v = 1; v <= n; v++){
            if(special[v]) ans += freq[v];
        }
        cout << ans << "\n";
    }
    return 0;
}
