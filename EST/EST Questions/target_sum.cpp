#include<bits/stdc++.h>
using namespace std;

struct Node {
    int sum;
    int mini;
    int maxi;
};
class SegmentTree {
    vector<Node>seg;
    int n;
public:
    SegmentTree(vector<int>& arr) {
        n=arr.size();
        seg.resize(4*n);
        build(0,0,n-1,arr);
    }
    Node merge(Node left, Node right) {
        Node res;
        res.sum=left.sum + right.sum;
        res.mini=min(left.mini, right.mini);
        res.maxi=max(left.maxi, right.maxi);
        return res;
    }
    void build(int idx, int l, int r, vector<int>& arr) {
        if(l==r) {
            seg[idx]={arr[l],arr[l],arr[l]};
            return;
        }
        int mid = (l+r)/2;
        build(2*idx+1,l,mid,arr);
        build(2*idx+2,mid+1,r,arr);
        seg[idx]=merge(seg[2*idx+1],seg[2*idx+2]);
    }
    Node query(int idx, int l, int r, int ql, int qr) {
        if(qr<l|| ql>r) {
            return {0,INT_MAX,INT_MIN};
        }
        if(ql<=l && r<=qr) {
            return seg[idx];
        }
        int mid =(l+r) /2;
        Node left =query(2*idx+1,l,mid,ql,qr);
        Node right =query(2*idx+2,mid+1,r,ql,qr);
        return merge(left,right);
    }
    Node rangeQuery(int l,int r) {
        return query(0,0,n-1,l,r);
    }
};

int main() {
    vector<int> arr = {1,3,5,7,9,11};
    SegmentTree st(arr);
    int l=2,r=4;
    Node ans = st.rangeQuery(l, r);
    cout<<"Sum:"<< ans.sum<<endl;
    cout<<"Min:"<< ans.mini<<endl;
    cout<<"Max:"<< ans.maxi<<endl;
    return 0;
}