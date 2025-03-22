#include <bits/stdc++.h>
using namespace std;
#define inic ios_base::sync_with_stdio(false);
#define inic1 cin.tie(NULL);
#define inic2 cout.tie(NULL);
typedef long long ll;

const ll MX = 1e5 + 5;
vector <ll> adj [MX];
vector <int> colors(MX);
bool vis[MX] {0};
bool f = true;
void dfs (ll u, int colorprev) {
    if(vis[u]) {
        if(colorprev == colors[u]) {
            f = false;
        }
        return;
    }
    vis[u] = 1;
    int coloract = 1;
    if(colorprev == 1) {
        coloract = 2;
    }
    colors[u] = coloract;
    for(auto x : adj[u]) {
        dfs(x, coloract);
    }
}

int main () {
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
    for(ll i = 1; i < n + 1; i++) {
        if(!vis[i]) {
            dfs(i,0);
        }
    }
    if(f) {
        for(ll i = 1; i < n + 1; i++) {
            cout << colors[i] << " ";
        }
    }
    else {
        cout << "IMPOSSIBLE";
    }
    return 0;
}