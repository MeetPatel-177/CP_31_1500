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
        vector<ll> a(n);
        for(ll i=0; i<n; i++) cin >> a[i];
        ll g = 0;
        for(auto& v : a) g = __gcd(g, v);
        if(g != 1) {
            cout << -1 << "\n";
            continue;
        }
        ll mini = INF;
        ll already_one = 0;
        for(ll i=0; i<n; i++) {
            if(a[i] == 1) {
                already_one++;
            }
        }
        if(already_one) {
            cout << (n - already_one) << "\n";
            continue;
        }
        for(ll i=0; i<n; i++) {
            ll ops1 = INF, ops2 = INF;
            ll tg = a[i];
            for(ll j=i-1; j>=0; j--) {
                tg = __gcd(tg, a[j]);
                if(tg == 1) {
                    ops1 = (i - j);
                    break;
                }
            }
            tg = a[i];
            for(ll j=i+1; j<n; j++) {
                tg = __gcd(tg, a[j]);
                if(tg == 1) {
                    ops2 = (j - i);
                    break;
                }
            }
            ll ops = min(ops1, ops2);
            mini = min(mini, ops);
        }
        cout << (mini + n-1) << "\n";
    }
    return 0;
}