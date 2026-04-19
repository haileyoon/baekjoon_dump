// Source: https://usaco.guide/general/io
#include <iostream>
#include <vector> 
using namespace std;
class SegmentTree{
    int n;
    vector<int> st;
    bool mx;
    int query(int p, int L, int R, int QL, int QR){
        if(L>QR || R < QL){
            return mx ? 0 : 1e7;
        }
        if(L>=QL && R<=QR){
            return st[p];
        }
        int mid = (L+R)/2;
        int leftQ = query(2*p+1,L,mid,QL,QR);
        int rightQ = query(2*p+2,mid+1,R,QL,QR);
        return mx ? max(leftQ, rightQ) : min(leftQ,rightQ);
    }
    void build(int p, int L, int R, vector<int> &data){
        if(L==R){
            st[p]=data[L];
            return;	
        }
        int mid = (L+R)/2;
        build(2*p+1,L,mid,data);
        build(2*p+2,mid+1,R,data);
        st[p]= mx ? max(st[2*p+1],st[2*p+2]) : min(st[2*p+1],st[2*p+2]);
    }
    public:
    SegmentTree(int n, bool mx, vector<int> &data):n(n),mx(mx),st(4*n){build(0,0,n-1,data);}
    int query(int L, int R){
        return query(0,0,n-1,L,R);
    }
};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q; cin>>n>>q;
    vector<int> data(n);
    for(int i = 0; i < n; ++i){
        cin>>data[i];
    }
    SegmentTree minSt(n,0,data);
    SegmentTree maxSt(n,1,data);
    for(int i = 0; i < q; ++i){
        int L,R; cin>>L>>R; --L,--R;
        cout<<maxSt.query(L,R)-minSt.query(L,R)<<"\n";
    }
}
