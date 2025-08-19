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
        ll ans = 0;
        for(ll i=1; i<n; i++) {
            if(a[i] >= a[i-1]) continue;
            ll needed = a[i-1] - a[i];
            ll curr = (ll)(log2(needed)) + 1;
            //we can make any combination of the numbers what we have with (1 << curr) - 1 to add to a[i] so that it will be a[i-1] we will not add whole (1 << curr) - 1 every time because we have to maintain every element as small as possible so that for next all numbers we have wider range of probabilities
            a[i] = a[i-1];
            ans = max(ans, curr);
        }
        cout << ans << "\n";
    }
    return 0;
}