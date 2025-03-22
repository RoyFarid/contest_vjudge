#include <bits/stdc++.h>
using namespace std;
#define inic ios_base::sync_with_stdio(false);
#define inic1 cin.tie(NULL);
#define inic2 cout.tie(NULL);
typedef long long ll;
const ll MX = 1e5+2;

vector <ll> adj[MX];
bool vis[MX] {0};
void dfs(ll u) {
    if(vis[u]) return;
    vis[u] = 1;
    for(auto x : adj[u]) {
        dfs(x);
    }
}
int main() {
    inic;
    inic1;
    inic2;
    ll n, m;
    cin >> n >> m;
    for(ll i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector <ll> roads;
    for(ll i = 1; i <= n; i++) {
        if(!vis[i]) {
            roads.push_back(i);
            dfs(i);
        }
    }
    ll l = roads.size();
    cout << l - 1 << "\n";
    for(ll i = 0; i < l - 1; i++) {
        cout << roads[i] << " " << roads[i + 1] << "\n";
    }
    return 0;
}
