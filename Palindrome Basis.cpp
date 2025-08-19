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

const ll N = 4e4 + 1;
//498 palindromes
vector<ll> palindromes;

bool isPalindrome(ll n) {
    string s = to_string(n);
    ll m = s.size();
    for(ll i=0; i<m/2; i++) {
        if(s[i] != s[m-i-1]) return false;
    }
    return true;
}

void pre_computation() {
    for(ll i=1; i<N; i++) {
        if(isPalindrome(i)) palindromes.push_back(i);
    }
}

ll dp[N][500];

ll rec(ll i, ll j) {
    //returns the no of ways to partition i such that the max number used is palindrome[j]
    //pruning
    if(i < 0) return 0;
    //base case
    if(j < 0) return (i == 0);
    //cache check
    if(dp[i][j] != -1) return dp[i][j];
    //compute
    //don't use this num
    ll ans = (rec(i,j-1) + rec(i-palindromes[j], j)) % M;
    //save and return
    return dp[i][j] = ans;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    pre_computation();
    ll m = palindromes.size();
    memset(dp, -1, sizeof(dp));
    ll t = 1;
    cin >> t;
    //we don't have to recalculate for every n we can just clear one time dp and use it for every query why because we used the version of left i.e. what sum is left to created and remember when we are using this thing it dosen't need to pass every time
    while(t--) {
        ll n;
        cin >> n;
        //dp[i][j] is the no of ways we can partition i using j as the biggest num
        cout << rec(n,m-1) << "\n";
    }
    return 0;
}