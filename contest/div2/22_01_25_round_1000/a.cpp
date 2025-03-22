#include <bits/stdc++.h>
using namespace std;
#define inic ios_base::sync_with_stdio(false);
#define inic1 cin.tie(NULL);
#define inic2 cout.tie(NULL);
typedef long long ll;
int main () {
    inic;
    inic1;
    inic2;
    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        vector<vector<ll>> adj(n+1);
        ll x, y;
        for(ll i = 0; i < n-1; i++) {
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        ll cant_adj_max = 0;
        ll v_de_adj_max;
        for(ll v = 1; v <= n; v++) {
            if(adj[v].size() > cant_adj_max) {
                cant_adj_max = adj[v].size();
                v_de_adj_max = v;
            }
        }

        sort(adj[v_de_adj_max].begin(), adj[v_de_adj_max].end());

        ll cant_adj_max_2 = 0;
        for(ll v = 1; v <= n; v++) {
            if(v == v_de_adj_max || binary_search(adj[v_de_adj_max].begin(), adj[v_de_adj_max].end(), v)) {
                continue;
            }
            if(adj[v].size() > cant_adj_max_2) {
                cant_adj_max_2 = adj[v].size();
            }
        
        }
        cout << cant_adj_max + cant_adj_max_2 - 1 << "\n";
    }      
    return 0;
}