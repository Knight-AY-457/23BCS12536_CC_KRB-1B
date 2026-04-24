#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n){
    if(n < 2) return false;
    for(int i = 2; i * i <= n; i++)
        if(n % i == 0) return false;
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    
    vector<int> primes;
    for(int i = 2; i <= n; i++)
        if(isPrime(i)) primes.push_back(i);
    
    set<int> primeSet(primes.begin(), primes.end());
    
    int cnt = 0;
    for(int i = 0; i + 1 < (int)primes.size(); i++){
        int candidate = primes[i] + primes[i + 1] + 1;
        if(candidate <= n && primeSet.count(candidate))
            cnt++;
    }
    
    cout << (cnt >= k ? "YES" : "NO") << "\n";
    return 0;
}
