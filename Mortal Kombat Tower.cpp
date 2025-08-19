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

const ll N = 2e5 + 10;
ll n;
ll a[N];
ll seen[N][2];
ll dp[N][2];
ll version = 0;

ll rec(ll level, ll person) {
    //returns the min skips we need for [level...N] 
    //pruning

    //base case
    if(level == n) return 0;
    //cache check
    if(seen[level][person] == version) return dp[level][person];
    ll ans = INF;
    if(person == 0) {
        ans = a[level] + rec(level+1, 1);
        if(level + 2 <= n) ans = min(ans, a[level]+a[level+1] + rec(level+2, 1));
    }else {
        ans = rec(level+1, 0);
        if(level + 2 <= n) ans = min(ans, rec(level+2, 0));
    }
    seen[level][person] = version;
    return dp[level][person] = ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll t = 1;
    cin >> t;
    while(t--) {
        cin >> n;
        for(ll i=0; i<n; i++) cin >> a[i];
        version++; // mark new test case 
        cout << rec(0,0) << "\n";
    }
    return 0;
}