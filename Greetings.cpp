#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
//find_by_order, order_of_key
//*s.find_by_order(index) will give us the value at that index in O(logn)
//s.order_of_key(val) will give us the number of smaller elements than val in O(logn)
//it has all other functionalities that a simple set has 

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
        vector<pair<ll,ll>> pp;
        for(ll i=0; i<n; i++) {
            ll s,e;
            cin >> s >> e;
            pp.push_back({s,e});
        }
        sort(whole(pp));
        oset<ll> st;
        for(ll i=0; i<n; i++) st.insert(pp[i].second);
        ll ans = 0;
        for(ll i=0; i<n; i++) {
            ans += st.order_of_key(pp[i].second);
            st.erase(pp[i].second);
        }
        cout << ans << "\n";
    } 
    return 0;
}