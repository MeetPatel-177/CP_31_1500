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
    // cin >> t;
    while(t--) {
        ll n, m;
        cin >> n >> m;
        vector<ll> graph[n];
        vector<bool> vis(n);
        for(ll i=0; i<m; i++) {
            ll u,v;
            cin >> u >> v;
            --u; --v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        vector<bool> pushed(n);
        vector<ll> ans;
        pq.push(0);
        while(!pq.empty()) {
            ll ver = pq.top(); pq.pop();
            vis[ver] = 1;
            ans.push_back(ver);
            for(auto& child : graph[ver]) {
                if(vis[child] || pushed[child]) continue;
                pq.push(child);
                pushed[child] = 1;
            }
        }
        for(auto& a : ans) cout << a+1 << " "; cout << "\n";
    }
    return 0;
}