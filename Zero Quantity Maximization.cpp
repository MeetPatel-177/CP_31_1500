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
        vector<ll> a(n), b(n);
        for(ll i=0; i<n; i++) cin >> a[i];
        for(ll i=0; i<n; i++) cin >> b[i];
        ll ans = 0;
        map<pair<ll,ll>, ll> freq;
        for(ll i=0; i<n; i++) {
            if(a[i] == 0) {
                if(b[i] == 0) ans++;
            }else {
                ll gcd = __gcd(a[i],b[i]);
                //factorise it until they are in the minimal form
                pair<ll,ll> d = {-b[i]/gcd, a[i]/gcd};
                freq[d]++;
            }
        }
        ll maxi = 0;
        for(auto& f : freq) {
            maxi = max(maxi, f.second);
        }
        ans += maxi;
        cout << ans << "\n";
    }
    return 0;
}