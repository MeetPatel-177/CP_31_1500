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

ll n, u, v;
const ll N = 1e5;
vector<ll> graph[N];
vector<ll> childs(N);

void dfs(ll ver, ll par) {
    childs[ver]++;
    for(auto& child : graph[ver]) {
        if(child == par) continue;
        dfs(child,ver);
        childs[ver] += childs[child];
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    cin >> n;
    for(ll i=0; i<n-1; i++) {
        cin >> u >> v;
        --u; --v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    if(n & 1) cout << -1 << "\n";
    else {
        ll ans = 0;
        dfs(0,-1);
        for(ll i=1; i<n; i++) {
            if(childs[i] & 1) continue;
            //we can always cut an edge if there is even number of childs
            ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}