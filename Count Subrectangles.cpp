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

vector<ll> divisors(ll n) {
    vector<ll> res;
    for(ll i=1; i*i<=n; i++) {
        if(n % i == 0) {
            res.push_back(i);
            if(n/i != i) res.push_back(n/i);
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll t = 1;
    // cin >> t;
    while(t--) {
        ll n,m,k;
        cin >> n >> m >> k;
        vector<ll> a(n), b(m);
        for(ll i=0; i<n; i++) cin >> a[i];
        for(ll i=0; i<m; i++) cin >> b[i];
        //how many continuous 1s are there in a and b
        vector<ll> cont_a(n+10,0), cont_b(m+10,0);
        ll cont = 0;
        for(ll i=0; i<n; i++) {
            if(a[i] == 1) cont++;
            else cont = 0;
            //diffrence of array method
            cont_a[1]++;
            cont_a[cont+1]--;
        }
        cont = 0;
        for(ll i=0; i<m; i++) {
            if(b[i] == 1) cont++;
            else cont = 0;
            cont_b[1]++;
            cont_b[cont+1]--;
        }
        //difference of array
        for(ll i=1; i<=n; i++) cont_a[i] += cont_a[i-1];
        for(ll i=1; i<=m; i++) cont_b[i] += cont_b[i-1];
        ll ans = 0;
        //we will iterate thrugh all the divisors of k
        vector<ll> divs = divisors(k);
        //any rectangle can only be formed of any perticular area if both the length and breadth of the rectangle is the divisors of the area
        for(ll& p : divs) {
            ll q = k/p;
            //p*q = k
            if(p > n || q > m) continue;
            ll curr = cont_a[p] * cont_b[q];
            ans += curr;
        }
        cout << ans << "\n";
    }
    return 0;
}