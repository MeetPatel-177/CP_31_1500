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
        vector<ll> graph[n];
        vector<ll> w(n), childs(n);
        for(ll i=0; i<n; i++) cin >> w[i];
        ll sum = 0;
        for(auto& v : w) sum += v;
        for(ll i=0; i<n-1; i++) {
            ll u,v;
            cin >> u >> v;
            --u; --v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        queue<ll> q;
        q.push(0);
        while(q.size()) {
            ll ver = q.front(); q.pop();
            for(auto& child : graph[ver]) {
                if(childs[child]) continue;
                childs[ver]++;
                q.push(child);
            }
        }
        childs[0]--;
        //how much time any weight can get add if we do it with different color is available
        vector<pair<ll,ll>> available(n);
        for(ll i=0; i<n; i++) {
            available[i] = {w[i], childs[i]};
        }
        //we will pick first k greatest weight which are available
        sort(whole(available), greater<pair<ll,ll>>());
        cout << sum << " ";
        ll j = 0;
        for(ll k=2; k<=n-1; k++) {
            while(available[j].second == 0) ++j; 
            available[j].second--;
            sum += available[j].first;
            cout << sum << " ";
        }
        cout << "\n";
    }
    return 0;
}