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

ll fact[15];

void pre_computation() {
    fact[0] = 1;
    for(ll i=1; i<15; i++) fact[i] = fact[i-1] * i;
}
//6 -> 4+2
//24 -> 16+8
//120 -> 64+32+24
//720 -> 512+128+64+16
//720 -> 256+128=484
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    pre_computation();
    ll t = 1;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll ans = INF;
        //we will consider facts from 3 to 14
        //we are iterating through all subsets of factorials excluding 1 and 2 due to avoiding repetation
        for(ll mask=0; mask<(1<<12); mask++) {
            //how many factorials we are using
            ll used = set_bits(mask);
            ll done = 0;
            for(ll i=0; i<12; i++) {
                if((mask >> i) & 1) {
                    done += fact[i+3];
                }
            }
            if(done > n) continue;
            ll rem = n - done;
            //how many powers of two we are using
            used += set_bits(rem);
            ans = min(ans, used);
        }
        cout << ans << "\n";
    }
    return 0;
}