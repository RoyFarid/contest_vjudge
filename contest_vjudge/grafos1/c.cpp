#include <bits/stdc++.h>
using namespace std;
#define inic ios_base::sync_with_stdio(false);
#define inic1 cin.tie(NULL);
#define inic2 cout.tie(NULL);
typedef long long ll;

//tecnica de recorrido de euler
/* void dfs(int crr,int pre){
  ans.push_back(crr);
  for(int nxt:G[crr])if(nxt!=pre){
    dfs(nxt,crr);
    ans.push_back(crr);
  }
} */
const ll MX = 2e5 + 5;
vector<ll> adj[MX];
void dfs(ll u, ll parent) {
    cout << u << " ";
    for(ll v : adj[u]) {
        if(v != parent) {
            dfs(v, u);
            cout << u << " ";
        }
    }
}

int main () {
    inic;
    inic1;
    inic2;
    ll n;
    cin >> n;
    ll x, y;
    for(ll i = 0; i < n-1; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(ll i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }
    dfs(1, -1);
    return 0;
}