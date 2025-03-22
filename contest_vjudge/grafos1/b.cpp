#include <bits/stdc++.h>
using namespace std;
#define inic ios_base::sync_with_stdio(false);
#define inic1 cin.tie(NULL);
#define inic2 cout.tie(NULL);
typedef long long ll;

const ll MX = 2e5 + 5;
vector<ll> adj[MX];
bool vis[MX];
void dfs(ll u) {
    if(vis[u]) return;
    vis[u] = 1;
    for(ll v : adj[u]) {
        dfs(v);
    }
}
int main () {
    inic;
    inic1;
    inic2;
    ll n , m;
    cin >> n >> m;
    ll x, y;
    for(ll i = 0; i < m; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    ll comp = 0;
    for(ll i = 1; i <= n; i++) 
        if(!vis[i]) {
            dfs(i);
            comp++;
        }

    cout << comp;
    return 0;
}