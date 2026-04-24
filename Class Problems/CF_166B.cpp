#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Point {
    ll x, y;
};

ll cross(Point O, Point A, Point B){
    return (ll)(A.x - O.x) * (B.y - O.y) - (ll)(A.y - O.y) * (B.x - O.x);
}

bool strictlyInsideConvex(const vector<Point>& poly, Point p){
    int n = poly.size();
    for(int i = 0; i < n; i++){
        ll c = cross(poly[i], poly[(i+1) % n], p);
        if(c >= 0) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<Point> A(n);
    for(auto &p : A) cin >> p.x >> p.y;
    
    int m;
    cin >> m;
    vector<Point> B(m);
    for(auto &p : B) cin >> p.x >> p.y;
    
    for(auto &p : B){
        if(!strictlyInsideConvex(A, p)){
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}
