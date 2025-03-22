#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MX = 2e5 + 10;

// Combinar dos pares para obtener los dos mayores valores
pair<ll, ll> combine(pair<ll, ll> a, pair<ll, ll> b) {
    vector<ll> values = {a.first, a.second, b.first, b.second};
    sort(values.rbegin(), values.rend()); // Ordenar en orden descendente
    return {values[0], values[1]};        // Retornar los dos mayores valores
}

struct SegmentTree {
    pair<ll, ll> t[2 * MX]; // Cada nodo almacena los dos mayores valores
    int n;

    // Inicializa el Segment Tree con ceros
    void clear(int n) {
        for (int i = 0; i < 2 * n; i++) {
            t[i] = {0, LLONG_MIN}; // Inicializar con el segundo máximo como -∞
        }
        this->n = n;
    }

    // Construcción del Segment Tree
    void build(vector<ll> &a, ll id, ll tl, ll tr) { // O(n)
        if (tl == tr) {
            t[id] = {a[tl], LLONG_MIN};
        } else {
            ll tm = (tl + tr) / 2;
            ll left = id + 1;
            ll right = id + 2 * (tm - tl + 1);
            build(a, left, tl, tm);
            build(a, right, tm + 1, tr);
            t[id] = combine(t[left], t[right]);
        }
    }

    void build(vector<ll> &a) {
        n = a.size();
        build(a, 1, 0, n - 1);
    }

    pair<ll, ll> query(ll l, ll r, ll id, ll tl, ll tr) {
        if (l <= tl && tr <= r) return t[id];
        ll tm = (tl + tr) / 2;
        ll left = id + 1;
        ll right = id + 2 * (tm - tl + 1);
        if (r < tm + 1) return query(l, r, left, tl, tm);
        else if (tm < l) return query(l, r, right, tm + 1, tr);
        else return combine(query(l, r, left, tl, tm), query(l, r, right, tm + 1, tr));
    }

    ll query(ll l, ll r) {
        assert(n > 0);
        pair<ll, ll> result = query(l, r, 1, 0, n - 1);
        return result.first + result.second;
    }

    void update(ll pos, ll val, ll id, ll tl, ll tr) {
        if (tl == tr) {
            t[id] = {val, LLONG_MIN};
        } else {
            ll tm = (tl + tr) / 2;
            ll left = id + 1;
            ll right = id + 2 * (tm - tl + 1);
            if (pos <= tm) update(pos, val, left, tl, tm);
            else update(pos, val, right, tm + 1, tr);
            t[id] = combine(t[left], t[right]);
        }
    }

    void update(ll pos, ll val) {
        assert(n > 0);
        update(pos, val, 1, 0, n - 1);
    }
} st;

vector<ll> vec;
int main() {
    ll n;
    cin >> n;
    for (ll i = 0; i < n; i++) {
        ll l;
        cin >> l;
        vec.push_back(l);
    }
    st.build(vec);

    ll t;
    cin >> t;
    while (t--) {
        char option;
        cin >> option;
        if (option == 'U') { // Actualización
            ll pos, val;
            cin >> pos >> val;
            st.update(pos - 1, val);
        } else if (option == 'Q') {
            ll x, y;
            cin >> x >> y;
            cout << st.query(x - 1, y - 1) << endl; // Convertir a índices 0-based
        }
    }
    return 0;
}