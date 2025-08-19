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
        //dp[i] is min no of elements we have to delete if we consider (i to n-1)
        vector<ll> dp(n+1,INF);
        //we have to delete 0 element if we consider n to n-1
        dp[n] = 0;
        for(ll i=n-1; i>=0; i--) {
            //delete the ith element
            dp[i] = dp[i+1] + 1;
            //keep the ith element
            if((i+a[i]+1) <= n) dp[i] = min(dp[i], dp[i+a[i]+1]);
        }
        cout << dp[0] << "\n";
    }
    return 0;
}