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
        //same as manhattan queries
        vector<ll> x,y;
        for(ll i=0; i<n; i++) {
            ll a,b;
            cin >> a >> b;
            x.push_back(a);
            y.push_back(b);
        }
        sort(whole(x)); sort(whole(y));
        ll s1 = x.size(), s2 = y.size();
        ll possX = 0, possY = 0;
        if(s1 & 1) possX = 1;
        else possX = x[s1/2] - x[s1/2 - 1] + 1;
        if(s2 & 1) possY = 1;
        else possY = y[s2/2] - y[s2/2 - 1] + 1;
        cout << possX * possY << "\n";
    }
    return 0;
}