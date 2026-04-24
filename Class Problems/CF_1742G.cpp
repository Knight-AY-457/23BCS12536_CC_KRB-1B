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
        
        vector<bool> used(n, false);
        vector<int> res;
        int cur = 0;
        
        while((int)res.size() < n){
            int bestVal = cur, bestIdx = -1;
            for(int i = 0; i < n; i++){
                if(!used[i] && (cur | a[i]) > bestVal){
                    bestVal = cur | a[i];
                    bestIdx = i;
                }
            }
            if(bestIdx == -1) break;
            used[bestIdx] = true;
            cur = bestVal;
            res.push_back(a[bestIdx]);
        }
        for(int i = 0; i < n; i++){
            if(!used[i]) res.push_back(a[i]);
        }
        
        for(int i = 0; i < n; i++){
            cout << res[i];
            if(i + 1 < n) cout << " ";
        }
        cout << "\n";
    }
    return 0;
}
