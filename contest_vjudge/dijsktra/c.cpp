#include <bits/stdc++.h>
#define pb push_back
#define inic ios_base::sync_with_stdio(false);
#define inic1 cin.tie(NULL);
#define inic2 cout.tie(NULL);
using namespace std;
typedef long long ll;
const ll MX = 1e5 + 2;
const ll INF = 1e18 + 2;

vector<pair<ll, ll>> adj[MX];
// map<pair<ll, ll>, ll> mapa;
set<pair<ll, ll>> sepa;
ll distancia_minima[MX], primer_ancestro[MX];
void dijkstra(ll root) { // (n + m) * (log2 n)
    sepa.insert(make_pair(0, root));
    distancia_minima[root] = 0;
    set<pair<ll, ll>>::iterator it;
    primer_ancestro[root] = root;
    while (!sepa.empty()) {
        it = sepa.begin();
        ll valorActual = (*it).second;
        sepa.erase(it);
        for (ll i = 0; i < adj[valorActual].size(); i++) {
            if (distancia_minima[adj[valorActual][i].first] > distancia_minima[valorActual] + adj[valorActual][i].second) {
                sepa.erase(make_pair(distancia_minima[adj[valorActual][i].first], adj[valorActual][i].first));
                distancia_minima[adj[valorActual][i].first] = distancia_minima[valorActual] + adj[valorActual][i].second;
                sepa.insert(make_pair(distancia_minima[adj[valorActual][i].first], adj[valorActual][i].first));
                primer_ancestro[adj[valorActual][i].first] = valorActual;
            }
        }
    }
}

void mostrar_camino(ll destino) {
    if(distancia_minima[destino] == INF) {
        cout << "-1";
        return;
    }
        vector<ll> camino;
        ll actual = destino;
        while (actual != primer_ancestro[actual]) {
            camino.pb(actual);
            actual = primer_ancestro[actual];
        }
        camino.pb(actual);
        reverse(camino.begin(), camino.end());
        for (ll nodo : camino) {
            cout << nodo << " ";
        }
    }

int main() {
    inic;
    inic1;
    inic2;
    ll n, m;
    cin >> n >> m;
    fill(distancia_minima, distancia_minima + n + 1, INF);
    while (m--) {
        ll a, b, w;
        cin >> a >> b >> w;
        adj[a].pb({b, w});
        adj[b].pb({a, w});
        // mapa[make_pair(a, b)] = w;
        // mapa[make_pair(b, a)] = w;
    }
    dijkstra(1);
    mostrar_camino(n);

    return 0;
}