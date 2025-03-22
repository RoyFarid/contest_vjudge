#include <bits/stdc++.h>
using namespace std;
#define inic ios_base::sync_with_stdio(false)
#define inic1 cin.tie(NULL)
#define inic2 cout.tie(NULL)
#define sl '\n'
typedef long long ll;

const ll MX = 1e5 + 2;

vector<ll> adj[MX];
ll resp[MX];

ll tamanio[MX], lider[MX];
ll find_lider(ll nodo) {
    if (lider[nodo] == nodo) {
        return nodo;
    }
    lider[nodo] = find_lider(lider[nodo]);
    return lider[nodo];
}
void join(ll nodo_a, ll nodo_b) {
    nodo_a = find_lider(nodo_a);
    nodo_b = find_lider(nodo_b);
    if (nodo_a != nodo_b) {
        if (tamanio[nodo_a] > tamanio[nodo_b]) {
            tamanio[nodo_a] += tamanio[nodo_b];
            lider[nodo_b] = nodo_a;
        } else {
            tamanio[nodo_b] += tamanio[nodo_a];
            lider[nodo_a] = nodo_b;
        }
    }
}

ll rp[MX];
set<ll> ses[MX];
vector <ll> color(MX);
void dfs(ll ini, ll pap) {
    ll tamMay = -1, nodoMay = ini;
    for (ll i = 0; i < adj[ini].size(); i++) {
        if (adj[ini][i] != pap) {
            dfs(adj[ini][i], ini);
            if (tamMay < tamanio[find_lider(adj[ini][i])]) {
                tamMay = tamanio[find_lider(adj[ini][i])];
                nodoMay = adj[ini][i];
            }
        }
    }
    ll lid = find_lider(nodoMay);
    for (ll i = 0; i < adj[ini].size(); i++) {
        if (adj[ini][i] != pap && adj[ini][i] != nodoMay) {
            ll asd = find_lider(adj[ini][i]);
            join(asd, lid);
            for (set<ll>::iterator it = ses[asd].begin(); it != ses[asd].end(); it++) {
                 ses[lid].insert(*it);
            }
        }
    }
    join(ini, lid);
    ses[find_lider(ini)].insert(color[ini]);
    resp[ini] = ses[find_lider(ini)].size();
}

int main() {
    inic;
    inic2;
    ll n;
    cin >> n;

    for(ll i = 1; i <= n; i++) {
        cin >> color[i];
    }

    for(int i = 0; i < n - 1; i++) {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    fill(tamanio, tamanio + n + 1, 1);
    iota(lider, lider + n + 1, 0);
    dfs(1, 1);
    for(ll i = 1; i <= n; i++) {
        cout << resp[i] << " ";
    }
    return 0;
}