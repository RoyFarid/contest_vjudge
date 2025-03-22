#include <bits/stdc++.h>
#define pb push_back
#define inic ios_base::sync_with_stdio(false);
#define inic1 cin.tie(NULL);
#define inic2 cout.tie(NULL);
#define all(s) s.begin(), s.end()
using namespace std;
typedef long long ll;
const ll MX = 2e5 + 5;
const ll MOD = 998244353;
const ll INF = 1e18;
const long double INF_DOUBLE = 1e18 / 1.0;
const long double EPS = 1e-8;
const long double PI = acos(-1.0);
typedef long double ld;
typedef unsigned long long ull;

ll getBit(ll x, ll i) {
    return (x >> i) & 1;
}

// n nodos , n e [1,1e5];
// m aristas, m e [1,2e6];
vector<ll> adj[MX];
bool usado[MX];
ll cont = 0;
ll profundidad[MX], padre[MX], hijos[MX], tiempo_entrada[MX], tiempo_salida[MX];
void dfs(ll nodo_actual, ll prof, ll pap) {
    cont++;
    tiempo_entrada[nodo_actual] = cont;
    profundidad[nodo_actual] = prof;
    usado[nodo_actual] = true;
    padre[nodo_actual] = pap;
    for (ll i = 0; i < adj[nodo_actual].size(); i++) {
        if (usado[adj[nodo_actual][i]] == false) {
            dfs(adj[nodo_actual][i], prof + 1, nodo_actual);
            hijos[nodo_actual] += hijos[adj[nodo_actual][i]] + 1;
        }
    }
    cont++;
    tiempo_salida[nodo_actual] = cont;
}

int main() {
    inic;
    inic1;
    inic2;
    ll n;
    ll root;
    cin >> n;
    vector <ll> cumplen;
    ll c[n+1];
    for(ll i = 1; i <= n; i++) {
        ll a;
        cin >> a >> c[i];
        if(a == -1) {
            root = i;
        }
        else {
            adj[a].pb(i);
            adj[i].pb(a);
        }
        if(c[i] == 1) {
            cumplen.push_back(i);
        }
    }
    dfs(root, 0, -1);
    vector <ll> final;
    for (ll nodo : cumplen) {
        bool f = true;
        for(ll x : adj[nodo]) {
            if(padre[x] == nodo) {
                // x es hijo de nodo;
                if(c[x] != 1) {
                    f = false;
                    break;
                }
            }
        }
        if(f) {
            final.push_back(nodo);
        }
    }
    if(final.empty()) {
        cout << "-1";
    }
    else {
        sort(final.begin(), final.end());
        for(ll vertice : final) {
            cout << vertice << " ";
        }
    }
    return 0;
}