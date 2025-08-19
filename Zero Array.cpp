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
        //whatever we are left with at any position always decrease the max and min by 1
        //when we do this then the only condition is that we can never make all zeroes if we don't have either enough sum of elements to make the largest element zero or we don't have the sum as even
        ll sum = 0, maxi = 0;
        for(ll i=0; i<n; i++) {
            sum += a[i];
            maxi = max(maxi, a[i]);
        }
        if((sum & 1) || (sum < 2*maxi)) no;
        else yes;
    }
    return 0;
}