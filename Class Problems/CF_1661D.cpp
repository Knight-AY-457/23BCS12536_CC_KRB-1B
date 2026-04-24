#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct BIT {
    int n;
    vector<ll> t;
    BIT(int n): n(n), t(n+2,0){}
    void upd(int i, ll v){ for(;i<=n;i+=i&-i) t[i]+=v; }
    ll qry(int i){ ll s=0; for(;i>0;i-=i&-i) s+=t[i]; return s; }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    vector<ll> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];

    BIT B(n), C(n);

    while(q--){
        int t; cin>>t;
        if(t==1){
            int l,r; ll b,c;
            cin>>l>>r>>b>>c;
            B.upd(l,b); B.upd(r+1,-b);
            C.upd(l,c-(ll)l*b); C.upd(r+1,-(c-(ll)l*b));
        } else {
            int i; cin>>i;
            ll sb=B.qry(i), sc=C.qry(i);
            cout<<a[i]+sb*i+sc<<"\n";
        }
    }
    return 0;
}
