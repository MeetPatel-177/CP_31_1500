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
        ll ans = 0;
        //we are making groups of k periods 
        //n = 9, k = 3
        //g0 = {0,3,6}
        //g1 = {1,4,7}
        //g2 = {2,5,8}
        //now try to see every palindrome pair is in the mirror group like (0-8) (3-5) (6-2)
        //so in order to make both palindrome and periodic we have to merge both the group and it's mirror group
        //so what we are doing is that we are iterating through first k/2 group and try to manipulate both the kth group and (k-g-1)th group at once and find minimal answer for that perticular group
        //now when we have k as odd the middle group will always be reamined so we have to take care of that individually
        for(ll g=0; g<k/2; g++) {
            vector<ll> freq(26,0);
            ll count = 0;
            for(ll j=g; j<n; j+=k) {
                freq[s[j] - 'a']++;
                count++;
            }
            //mirror group
            ll j = k - g - 1;
            for(; j<n; j+=k) {
                freq[s[j] - 'a']++;
                count++;
            }
            ll maxi = *max_element(whole(freq));
            ans += (count - maxi);
        }
        //if k is odd then middle group will remain alone
        if(k & 1) {
            vector<ll> freq(26,0);
            ll count = 0;
            for(ll j=k/2; j<n; j+=k) {
                freq[s[j] - 'a']++;
                count++;
            }
            ll maxi = *max_element(whole(freq));
            ans += (count - maxi);
        }
        cout << ans << "\n";
    }
    return 0;
}