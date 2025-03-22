#include <bits/stdc++.h>
using namespace std;
#define inic ios_base::sync_with_stdio(false);
#define inic1 cin.tie(NULL);
#define inic2 cout.tie(NULL);
typedef long long ll;

const ll MX = 2e5;
vector<ll> adj[MX + 1];
ll hijos[MX + 1] {0};
bool vis[MX + 1];
void dfs(ll u, ll parent) {
    for(ll v : adj[u]) {
        if(v == parent) continue; 
        dfs(v, u);
        hijos[u] += hijos[v] + 1;
    }
}
int main () {
    inic;
    inic1;
    inic2;
    ll n;
    cin >> n;
    ll boss;
    for(ll i = 2; i <= n; i++) {
        cin >> boss;
        adj[boss].push_back(i);
        adj[i].push_back(boss);
    }

    dfs(1, -1);
    for(ll i = 1; i <= n; i++) 
        cout << hijos[i] << " ";

    return 0;
}