#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    map<string, int>mp;
    for(int i = 0; i < n; i++){
        string data;
        cin >> data;
        mp[data]++;
    }

    int maxi = 0;
    for(auto it : mp){
        if(it.second > maxi){
            maxi = it.second;
        }
    }
    string ans = "";
    for(auto it : mp){
        if(it.second == maxi){
            ans = it.first;
        }
    }
    // sort(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}
