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
        //1 2 2 3 4 5
        sort(whole(a));
        ll x = 0;
        ll moves = 0;
        ll i = 0, j = n-1;
        while(i < j) {
            //when we add some val then it becomes x and we can make a second move in the jth element
            if((a[i] + x) > a[j]) {
                a[i] -= (a[j] - x);
                moves += (a[j] - x + 1);
                x = 0;
                --j;
            }
            //we can't make second move even after adding a[i] to x so add a[i] to x
            else {
                moves += a[i];
                x += a[i];
                ++i;
            }
        }
        // cout << i << "\n";
        if(a[i] == 1) moves++;
        else {
            moves += max(0LL,(a[i] - x + 1)/2);
            moves++;
        }
        cout << moves << "\n";
    }
    return 0;
}