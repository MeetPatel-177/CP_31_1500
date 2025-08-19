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
        vector<ll> a(n), b(n);
        for(ll i=0; i<n; i++) cin >> a[i];
        for(ll i=0; i<n; i++) cin >> b[i];
        //cnt indicates how much time the ith person drinks the full tea
        //add indicates how much extra tea the ith person had drunk after drinking all full teas
        vector<ll> cnt(n+1, 0), add(n+1, 0);
        //pref is just prefix sum array
        vector<ll> pref(n+1,0);
        for(ll i=0; i<n; i++) pref[i+1] = pref[i] + b[i];
        for(ll i=0; i<n; i++) {
            //(pref[j] - pref[i] <= a[i]) --> pref[j] = a[i] + pref[i]
            //upperbound(a[i] + pref[i])
            ll j = upper_bound(whole(pref), a[i]+pref[i]) - pref.begin() - 1;
            //i to j-1 will fully drink the curr tea
            cnt[i]++;
            cnt[j]--;
            //this much will be remained and that will be drunk by the jth person
            add[j] += (a[i] + pref[i] - pref[j]);
        }
        for(ll i=0; i<n; i++) {
            //any person i will drink full tea ie b[i] cnt[i] times and then additional some a[i]
            cout << cnt[i]*b[i] + add[i] << " ";
            //take prefix of cnt as sum of difference method we have applied
            cnt[i+1] += cnt[i];
        }
        cout << "\n";
    }
    return 0;
}