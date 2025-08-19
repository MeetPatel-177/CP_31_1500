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
            segs.push_back({l,r,i+1});
        }
        //always remember when writing comparator always write only strict conditions, because when you write like (a >= b) it violates strict breaking rules of comparators, because let's say you have two things (1,3) and (1,3) then when it compares first with second it will be true and vice versa also, so it will go in infinite loop and causing runtime error or corrupted results
        sort(whole(segs), [](auto& s1, auto& s2) {
            if(s1[0] == s2[0]) return s1[1] > s2[1];
            return s1[0] < s2[0];
        });
        pair<ll,ll> ans = {-1,-1};
        ll prevr = -1, prev_ind = -1;
        for(auto& seg : segs) {
            ll l = seg[0], r = seg[1], i = seg[2];
            if(r <= prevr) {
                ans = {i,prev_ind};
                break;
            }else {
                prevr = max(r, prevr);
                prev_ind = i;
            }
        }
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}