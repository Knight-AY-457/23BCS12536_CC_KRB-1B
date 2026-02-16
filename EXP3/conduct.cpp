#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
long long gcd(long long x, long long y) {
    if (y == 0) return x;
    return gcd(y,x%y);
}
int main(){
    long long r,a,b;
    cin >>r>>a>>b;
    long long lcm = (a/gcd(a,b))*b;
    long long low =1, high=r*min(a,b),ans=0;
    while (low<=high) {
        long long mid =(low+ high) / 2;
        long long count = mid/a + mid/b - mid/lcm;
        if (count >= r){
            ans=mid;
            high=mid-1;
        } else {
            low=mid+1;
        }
    }
    cout<<ans% MOD;
    return 0;
}