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

const ll N = 1e5;
bool vis[N];
vector<ll> graph[N];

ll binExp(ll n, ll k) {
    ll ans = 1;
    while(k) {
        if(k & 1) ans = (ans * n) % M;
        n = (n * n) % M;
        k >>= 1;
    }
    return ans;
}

ll curr = 0;
//this returns the size of the current connected component
void dfs(ll ver) {
    if(vis[ver]) return;
    vis[ver] = 1;
    curr++;
    for(auto& child : graph[ver]) {
        dfs(child);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    ll n, k;
    cin >> n >> k;
    for(ll i=0; i<n-1; i++) {
        ll u,v,x;
        cin >> u >> v >> x;
        --u; --v;
        //we will not make edges when we have x == 1 ie we have black edges in this way we can remove all the black edges
        if(x == 0) {
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
    }
    //what we are doing is finding bad sequences like if all edges have red then it is bad sequence so we are finding all bad sequences and removing it from the total number of sequences
    ll tot = binExp(n,k);
    ll extra = 0;
    for(ll i=0; i<n; i++) {
        if(vis[i]) continue;
        curr = 0;
        dfs(i);
        extra += binExp(curr,k);
        extra %= M;
    }
    cout << (tot - extra + M) % M << "\n";
    return 0;
}