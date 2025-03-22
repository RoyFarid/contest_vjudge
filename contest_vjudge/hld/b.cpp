#include <bits/stdc++.h>
#define pb push_back
#define inic ios_base::sync_with_stdio(false)
#define inic2 cin.tie(NULL)
#define inic3 cout.tie(NULL)
#define sl '\n'
using namespace std;
typedef long long ll;
const ll MAXN = 200005;
vector<ll> tree[MAXN];
ll parent[MAXN], depth[MAXN], heavy[MAXN], head[MAXN], pos[MAXN], subtree_size[MAXN];
ll segtree[4 * MAXN], values[MAXN], real_values[MAXN], cur_pos = 0;

ll dfs(ll u) {
    subtree_size[u] = 1;
    ll max_size = 0, heavy_child = -1;
    for (ll v : tree[u]) {
        if (v == parent[u]) continue;
        parent[v] = u;
        depth[v] = depth[u] + 1;
        ll sz = dfs(v);
        subtree_size[u] += sz;
        if (sz > max_size) {
            max_size = sz;
            heavy_child = v;
        }
    }
    heavy[u] = heavy_child;
    return subtree_size[u];
}

void decompose(ll u, ll h) {
    head[u] = h;
    pos[u] = cur_pos++;
    if (heavy[u] != -1) decompose(heavy[u], h);
    for (ll v : tree[u]) {
        if (v != parent[u] && v != heavy[u]) decompose(v, v);
    }
}

void build(ll node, ll l, ll r) {
    if (l == r) {
        segtree[node] = values[l];
        return;
    }
    ll mid = (l + r) / 2;
    build(2 * node, l, mid);
    build(2 * node + 1, mid + 1, r);
    segtree[node] = max(segtree[2 * node], segtree[2 * node + 1]);
}

void update(ll node, ll l, ll r, ll idx, ll val) {
    if (l == r) {
        segtree[node] = val;
        return;
    }
    ll mid = (l + r) / 2;
    if (idx <= mid) update(2 * node, l, mid, idx, val);
    else update(2 * node + 1, mid + 1, r, idx, val);
    segtree[node] = max(segtree[2 * node], segtree[2 * node + 1]);
}

ll query(ll node, ll l, ll r, ll ql, ll qr) {
    if (ql > r || qr < l) return 0;
    if (ql <= l && r <= qr) return segtree[node];
    ll mid = (l + r) / 2;
    return query(2 * node, l, mid, ql, qr) + query(2 * node + 1, mid + 1, r, ql, qr);
}

ll query_subtree(ll u) {
    return query(1, 0, cur_pos - 1, pos[u], pos[u] + subtree_size[u] - 1);
}

void update_node(ll u, ll val) {
    update(1, 0, cur_pos - 1, pos[u], val);
}

int main() {
    ll n, q;
    cin >> n >> q;

    for (ll i = 0; i < n; i++) {
        cin >> real_values[i];
    }

    for (ll i = 0; i < n - 1; i++) {
        ll u, v;
        cin >> u >> v;
        tree[u - 1].push_back(v - 1);
        tree[v - 1].push_back(u - 1);
    }

    fill(heavy, heavy + MAXN, -1);
    parent[0] = -1;
    depth[0] = 0;
    dfs(0);
    decompose(0, 0);

    for (ll i = 0; i < n; i++) {
        values[pos[i]] = real_values[i];
    }

    build(1, 0, cur_pos - 1);

    while (q--) {
        ll type, u;
        cin >> type >> u;
        u--;
        if (type == 1) {
            ll val;
            cin >> val;
            update_node(u, val);
        } else if (type == 2) {
            cout << query_subtree(u) << "\n";
        }
    }

    return 0;
}

