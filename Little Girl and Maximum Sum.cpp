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
        ll n, q;
        cin >> n >> q;
        vector<ll> arr(n);
        for(ll i=0; i<n; i++) cin >> arr[i];
        sort(whole(arr), greater<ll>());
        vector<ll> occs(n+1,0);
        for(ll i=0; i<q; i++) {
            ll l,r;
            cin >> l >> r;
            --l; --r;
            //what we are doing is that which occurence will be counted how many times, whichever will be the largest we will put there the available largest number
            occs[l]++;
            occs[r+1]--;
        }
        //difference of array
        for(ll i=1; i<=n; i++) occs[i] += occs[i-1];
        ll ind_of_a = 0;
        sort(whole(occs), greater<ll>());
        ll ans = 0;
        for(ll i=0; i<=n; i++) {
            if(occs[i] > 0) {
                ans += (occs[i]*arr[ind_of_a++]);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}