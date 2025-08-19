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
        string s;
        cin >> s;
        ll zero_xor = 0, one_xor = 0;
        vector<ll> pfxor(n,0);
        pfxor[0] = a[0];
        if(s[0] == '0') zero_xor = a[0];
        else one_xor = a[0];
        for(ll i=1; i<n; i++) {
            pfxor[i] = pfxor[i-1] ^ a[i];
            if(s[i] == '0') zero_xor ^= a[i];
            else one_xor ^= a[i];
        }
        ll q;
        cin >> q;
        while(q--) {
            ll type;
            cin >> type;
            if(type == 1) {
                ll l,r;
                cin >> l >> r;
                --l;
                --r;
                ll curr_xor = -1;
                //we will have to xor both with whole xor of curr segment because we want to remove one type of thing ie 0 or 1 and want to add another so we have to do xor with both of them so no matter what we do we will xor both with curr segment's xor
                if(l == 0) curr_xor = pfxor[r];
                else curr_xor = pfxor[r] ^ pfxor[l-1];
                zero_xor ^= curr_xor;
                one_xor ^= curr_xor;
            }else {
                ll g;
                cin >> g;
                if(g == 0) {
                    cout << zero_xor << " ";
                }else {
                    cout << one_xor << ' ';
                }
            }
        }
        cout << "\n";
    }
    return 0;
}