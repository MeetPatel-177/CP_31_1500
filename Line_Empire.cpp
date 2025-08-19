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
        ll n, a, b;
        cin >> n >> a >> b; 
        vector<ll> v(n);
        for(ll i=0; i<n; i++) cin >> v[i];
        //we will fix our end position of the kingdom and calculate the cost
        vector<ll> pf(n);
        pf[0] = v[0];
        for(ll i=1; i<n; i++) pf[i] = pf[i-1] + v[i];
        ll cost = INF;
        //if we will not move our kingdom and remain it on 0 itself
        cost = b*pf[n-1];
        for(ll i=0; i<n; i++) {
            //we will move our kingdom to ith position
            ll curr_cost = a*v[i] + b*v[i] + b*(pf[n-1]-pf[i] - (n-1-i)*v[i]);
            cost = min(cost, curr_cost);
        }
        cout << cost << "\n";
    }
    return 0;
}