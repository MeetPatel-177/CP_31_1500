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
        string s;
        cin >> s;
        ll p = 0, m = 0;
        for(auto& ch : s) {
            if(ch == '+') ++p;
            else ++m;
        }
        ll q;
        cin >> q;
        while(q--) {
            ll a,b;
            cin >> a >> b;
            if(a == b) {
                if(p == m) yes;
                else no;
            }else {
                ll t = (m - p)*b / (a - b);
                ll num = (m - p)*b;
                ll den = (a - b);
                if(num % den == 0 && t >= -m && t <= p) yes;
                else no; 
            }
        }
    }
    return 0;
}