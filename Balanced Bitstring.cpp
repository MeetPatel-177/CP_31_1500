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
        ll n,k;
        cin >> n >> k;
        string s;
        cin >> s;
        //si and s(i+k) should have the same value because s(i+1) to s(i+k-1) will be in both strings starting at i and i+1
        //so in order to make them balanced we have to make si and s(i+k) 
        bool poss = 1;
        ll z = 0, o = 0;
        for(ll i=0; i<k; i++) {
            ll temp = -1;
            //every si and si+k should be same
            for(ll j=i; j<n; j+=k) {
                if(s[j] == '?') continue;
                if(temp != -1 && (s[j] - '0') != temp) {
                    poss = 0;
                    break;
                }
                temp = (s[j] - '0');
            }
            //z and o maintains the count of z and o in the first k letters substring
            if(temp != -1) {
                if(temp == 0) z++;
                else o++;
            }
        }
        //why we have not checked if (o != z) it's because we also have some of the ? which can take value of whatever we want so we have to check if any value of o or z is greater than (k/2) then it will be impossible to make that string k balanced
        if(max(o,z) > (k/2)) poss = 0;
        if(poss) yes;
        else no;
    }
    return 0;
}