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
        vector<ll> pfxor(n);
        pfxor[0] = a[0];
        for(ll i=1; i<n; i++) pfxor[i] = pfxor[i-1] ^ a[i];
        bool poss = 0;
        //we will partition the first piece at i
        for(ll i=0; i<n-1; i++) {
            ll x = pfxor[i];
            //xx will keep track of the xor from (i+1)
            ll xx = 0;
            bool flag = 0;
            for(ll j=i+1; j<n; j++) {
                xx ^= a[j];
                //if anywhere we got xx==x that means we have found another piece which has xor as x so we reset xx as 0
                if(xx == x) {
                    flag = 1;
                    xx = 0;
                }
            }
            //now at the end xx == 0 and flag also because there can be some elements whose xor can be zero but there is no piece whose xor is x so that is invalid case
            if(xx == 0 && flag) {
                poss = 1;
                break;
            }
        }
        if(poss) yes;
        else no;
    }
    return 0;
}