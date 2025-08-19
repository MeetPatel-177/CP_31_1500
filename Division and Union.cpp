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
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        vector<vector<ll>> segs;
        for(ll i=0; i<n; i++) {
            ll l,r;
            cin >> l >> r;
            segs.push_back({l,r,i});
        }
        sort(whole(segs));
        vector<ll> ans(n);
        ll group = 1;
        ll prev = -1;
        for(ll i=0; i<n; i++) {
            ll l = segs[i][0], r = segs[i][1], ind = segs[i][2];
            if(prev != -1 && l > prev) {
                group = 2;
            }
            ans[ind] = group;
            //right side will be always maxi right side
            prev = max(prev, r);
        }
        if(group == 1) cout << -1 << "\n";
        else {
            for(ll i=0; i<n; i++) cout << ans[i] << " "; cout << "\n";
        }
    }
    return 0;
}