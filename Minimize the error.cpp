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
        ll n, k1, k2;
        cin >> n >> k1 >> k2;
        vector<ll> a(n), b(n);
        for(ll i=0; i<n; i++) cin >> a[i];
        for(ll i=0; i<n; i++) cin >> b[i];
        priority_queue<ll> nums;
        for(ll i=0; i<n; i++) {
            nums.push(abs(a[i] - b[i]));
        }
        ll ops = k1 + k2;
        while(ops) {
            ll maxi = nums.top(); nums.pop();
            if(maxi == 0) {
                if(ops & 1) nums.push(1);
                break;
            }else {
                nums.push(maxi - 1);
                ops--;
            }
        }
        ll ans = 0;
        while(!nums.empty()) {
            ll num = nums.top(); nums.pop();
            ans += (num*num);
        }
        cout << ans << "\n";
    }
    return 0;
}