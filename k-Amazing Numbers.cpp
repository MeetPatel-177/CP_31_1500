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
        vector<ll> a(n);
        for(ll i=0; i<n; i++) cin >> a[i];
        map<ll,vector<ll>> occs;
        //we will store every occurences of any perticular number in a map 
        for(ll i=0; i<n; i++) {
            occs[a[i]].push_back(i);
        }
        vector<ll> ans(n, -1);
        ll last = n;
        for(auto& it : occs) {
            ll max_gap = 0;
            vector<ll> v = it.second;
            //for any current number what is the max gap that will be the min k we can put that number into
            ll mini = v[0], maxi = v[v.size() - 1];
            max_gap = max(max_gap, mini);
            max_gap = max(max_gap, n - maxi - 1);
            for(ll i=1; i<v.size(); i++) {
                max_gap = max(max_gap, v[i] - v[i-1] - 1);
            }
            for(ll i=max_gap; i<last; i++) ans[i] = it.first;
            last = min(last, max_gap);
        }
        for(ll i=0; i<n; i++) cout << ans[i] << " "; cout << "\n"; 
    }
    return 0;
}