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

    string s;
    cin >> s;
    ll n = s.size();
    //remember we don't need whole substrings we are asked about only subsequences ending at 'a' and have at least one 'b' in between both ending points
    //now what we are doing is that making chunks of a's that have at least b after them
    //so now every chunk has (size+1) poss like we can take 0,1,2,...,size a's from it, every chunk has b's in between so no tension, now only 1 case when all of the choosen sz is 0 that is no a's are choosen that will be invalid
    ll ans = 1;
    ll curr = 0;
    for(ll i=0; i<n; i++) {
        if(s[i] == 'a') {
            curr++;
        }else if(s[i] == 'b') {
            ans = (ans * (curr+1)) % M;
            curr = 0;
        }
    }
    ans = (ans * (curr+1)) % M;
    //extra 1 way which is everyone is selected with 0 size
    cout << (ans - 1) << "\n";
    return 0;
}