#include <bits/stdc++.h>
#define pb push_back
#define inic ios_base::sync_with_stdio(false);
#define inic2 cin.tie(NULL);
#define inic3 cout.tie(NULL);
using namespace std;
typedef long long ll;
const ll MX = 5e4 + 2;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const double INF_DOUBLE = 1e18 / 1.0;
const double EPS = 1e-8;
const double PI = acos(-1.0);

vector<ll> vec;
ll operacionSuma(ll izqui, ll dere) {
    if (izqui == INF) {
        return INF;
    }
    if (dere == INF) {
        return INF;
    }
    return izqui + dere;
}

struct valores {
    ll sumapref, sumasuf, sumatot, sumamax;
    valores() : sumapref(0), sumasuf(0), sumatot(0), sumamax(0) {}
    void llenar(valores izquierda, valores derecha) {
        sumapref = max(izquierda.sumapref, operacionSuma(izquierda.sumatot, derecha.sumapref));
        sumasuf = max(derecha.sumasuf, operacionSuma(derecha.sumatot, izquierda.sumasuf));
        sumatot = operacionSuma(izquierda.sumatot, derecha.sumatot);
        sumamax = max(max(max(max(izquierda.sumamax, derecha.sumamax),
                              operacionSuma(izquierda.sumasuf, derecha.sumapref)),
                          sumapref),
                      sumasuf);
    }
} ids[4 * MX];
/*
ll combine(valores x , valores y) {
        return x + y;
}*/

struct SegmentTree {
    ll t[4 * MX];

    ll maxN;

    void clear(ll n) {
        for (ll i = 0; i < 4 * n; i++) {
            t[i] = 0;
        }
        maxN = n;
    }

    void build(vector<ll> &a, ll id, ll tl, ll tr) { // O(n)
        if (tl == tr) {
            // t[id] = a[tl];
            ids[id].sumapref = a[tl];
            ids[id].sumasuf = a[tl];
            ids[id].sumatot = a[tl];
            ids[id].sumamax = a[tl];
        } else {
            ll tm = (tl + tr) / 2;
            ll left = 2 * id;
            ll right = 2 * id + 1;
            build(a, left, tl, tm);
            build(a, right, tm + 1, tr);
            ids[id].llenar(ids[left], ids[right]);
            // t[id] = combine(t[left] , t[right]);
        }
    }

    void build(vector<ll> &a) {
        maxN = a.size();
        build(a, 1, 0, maxN - 1);
    }

    valores query(ll l, ll r, ll id, ll tl, ll tr) { // O(logn)
        valores resp;
        resp.sumapref = -INF;
        resp.sumasuf = -INF;
        resp.sumatot = -INF;
        resp.sumamax = -INF;
        if (l <= tl && tr <= r) {
            return ids[id];
        }
        ll tm = (tl + tr) / 2;
        ll left = 2 * id;
        ll right = 2 * id + 1;
        if (r < tm + 1) {
            // only left child
            return query(l, r, left, tl, tm);
        } else if (tm < l) {
            // only right child
            return query(l, r, right, tm + 1, tr);
        } else {
            // both children
            resp.llenar(query(l, r, left, tl, tm), query(l, r, right, tm + 1, tr));
            return resp;
        }
    }

    valores query(ll l, ll r) {
        assert(maxN > 0);
        return query(l, r, 1, 0, maxN - 1);
    }

    void update(ll pos, ll val, ll id, ll tl, ll tr) { // O(logn)
        if (tl == tr) {
            ids[id].sumapref = val;
            ids[id].sumasuf = val;
            ids[id].sumatot = val;
            ids[id].sumamax = val;
            // t[id]= val;
        } else {
            ll tm = (tl + tr) / 2;
            ll left = 2 * id;
            ll right = 2 * id + 1;
            if (pos <= tm) {
                update(pos, val, left, tl, tm);
            } else {
                update(pos, val, right, tm + 1, tr);
            }
            ids[id].llenar(ids[left], ids[right]);
            // t[id] = combine(t[left] , t[right] );
        }
    }

    void update(ll pos, ll val) {
        assert(maxN > 0);
        update(pos, val, 1, 0, maxN - 1);
    }
} st;

int main() {
    ll n, m;
    cin >> n;
    while (n--) {
        ll l;
        cin >> l;
        vec.pb(l);
    }
    st.build(vec);
    cin >> m;
    while (m--) {
        int option;
        cin >> option;
        ll a, b;
        if(option == 1) {
            cin >> a >> b;
            cout << st.query(a - 1,b - 1).sumamax << "\n";
        }
        else {
            cin >> a >> b;
            st.update(a - 1, b);
        }
    }
    return 0;
}