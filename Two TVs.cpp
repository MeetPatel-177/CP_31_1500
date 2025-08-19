#include <bits/stdc++.h>
using namespace std;

#define ll long long int
const ll INF = 1e18;
const ll MINF = -1e18;
const ll M = 1e9 + 7;
#define PI acos(-1)

#define whole(x) (x).begin(), (x).end()
#define count_bits(x) 64 - __builtin_clzll(x);
#define set_bits(x) __builtin_popcountll(x);

#define yes cout << "YES\n"
#define no cout << "NO\n"

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll t = 1;
    // cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        vector<vector<ll>> segs;
        for(ll i=0; i<n; i++) {
            ll l,r;
            cin >> l >> r;
            segs.push_back({l,r});
        }
        sort(whole(segs));
        bool poss = 1;
        ll p1 = -1, p2 = -1;
        for(auto& seg : segs) {
            ll l = seg[0], r = seg[1];
            if(p1 > p2) swap(p1,p2);
            if(l <= p1) {
                poss = 0;
                break;
            }
            p1 = max(r, p1);
        }
        if(poss) yes;
        else no;
    }
    return 0;
}