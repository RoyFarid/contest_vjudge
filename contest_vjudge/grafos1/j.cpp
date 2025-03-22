#include <bits/stdc++.h>
using namespace std;
#define inic ios_base::sync_with_stdio(false);
#define inic1 cin.tie(NULL);
#define inic2 cout.tie(NULL);
typedef long long ll;
const ll MX = 2e5 + 1;
vector <ll> adj[MX];
ll dp[MX];
ll ans[MX];
ll n;
void dfs1(ll u, ll father, ll prof) {
    ans[1] += prof;
    dp[u] = 1;
    for(auto x : adj[u]) {
        if(x != father) {
            dfs1(x, u, prof + 1);
            dp[u] += dp[x];
        }
    }
}

void dfs2(ll u, ll father) {
    for(auto x : adj[u]) {
        if(x != father) {
            ans[x] = ans[u] + n - 2 * dp[x];
            dfs2(x, u);
        }
    }
}

int main() {
    inic;
    inic1;
    inic2;
    cin >> n;
    for(ll i = 0; i < n - 1; i++) {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs1(1,0,0);
    dfs2(1,0);
    for(ll i = 1; i <= n; i++) {
        cout << dp[i] <<" ";
    }
    
    cout << endl;

    for(ll i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}