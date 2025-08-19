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
vector<ll> graph[N];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    map<pair<ll,ll>,ll> index;
    ll n;
    cin >> n;
    for(ll i=0; i<n-1; i++) {
        ll u,v;
        cin >> u >> v;
        --u; --v;
        index[{u,v}] = i;
        index[{v,u}] = i;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    ll num = 0;
    vector<ll> ans(n-1,-1);
    for(ll i=0; i<n; i++) {
        //leaf node
        if(graph[i].size() == 1) {
            pair<ll,ll> pr = {i, graph[i][0]};
            ll ind = index[pr];
            if(ans[ind] == -1) ans[ind] = num++;
        }
    }
    for(ll i=0; i<n; i++) {
        if(graph[i].size() == 1) continue;
        //other nodes
        for(auto& child : graph[i]) {
            pair<ll,ll> pr = {i,child};
            ll ind = index[pr];
            if(ans[ind] == -1) ans[ind] = num++;
        }
    }
    for(ll i=0; i<n-1; i++) cout << ans[i] << "\n";
    return 0;
}