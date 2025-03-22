#include <bits/stdc++.h>
#define inic ios_base::sync_with_stdio(false);
#define inic2 cin.tie(NULL);
#define inic3 cout.tie(NULL);
using namespace std;
typedef long long ll;
const int MX = 2e5 + 1;
const int INF = 1e9;

int combine(int a, int b) {
    // return a + b;
    return max(a, b);
}

struct SegmentTree {
    int t[2 * MX];
    //int lazy[2 * MX];
    int n;

    void clear(int n) {
        for (int i = 0; i <= 2 * n; i++) {
            t[i] = 0;
            //lazy[i] = 0;
        }
        this->n = n;
    }

    void build(vector<int> &a, int id, int tl, int tr) { // O(n)
        //lazy[id] = 0;
        if (tl == tr) {
            t[id] = a[tl-1];
        } else {
            int tm = (tl + tr) / 2;
            int left = id + 1;
            int right = id + 2 * (tm - tl + 1);
            build(a, left, tl, tm);
            build(a, right, tm + 1, tr);
            t[id] = max(t[left], t[right]);
        }
    }

    void build(vector<int> &a) {
        n = a.size();
        build(a, 1, 1, n);
    }

    /* void push(int id, int tl, int tr) { // O(1)
        int tm = (tl + tr) / 2;
        int left = id + 1;
        int right = id + 2 * (tm - tl + 1);
        int szLeft = tm - tl + 1;
        int szRight = tr - tm;
        // Apply the lazy value of the node to the children
        // t[left] += lazy[id] * szLeft;
        //t[left] += lazy[id];
        // t[right] += lazy[id] * szRight;
        //t[right] += lazy[id];
        // Aggregate the lazy value
        //lazy[left] += lazy[id];
        //lazy[right] += lazy[id];

        // Restart the lazy value
        //lazy[id] = 0;
    } */

    int query(int l, int r, int id, int tl, int tr) { // O(logn)
        if (tr < l || tl > r || l > r) return 0;
        if (l <= tl && tr <= r) return t[id];
        int tm = (tl + tr) / 2;
        int left = id + 1;
        int right = id + 2 * (tm - tl + 1);
        /* push(id, tl, tr);
        int leftVal = query(l, r, left, tl, tm);
        int rightVal = query(l, r, right, tm + 1, tr); */
        // Cases: Left, Right Child
        if (r < tm + 1) return query(l, r, left, tl, tm); 
        else if (tm < l) return query(l, r, right, tm + 1, tr);
        else return combine(query(l, r, left, tl, tm), query(l, r, right, tm + 1, tr));
        // Both child
        //return max(leftVal, rightVal); 
    }

    int query(int l, int r) {
        assert(n > 0);
        return query(l, r, 1, 1, n);
    }

    /* void update(int l, int r, int val, int id, int tl, int tr) { // O(logn)
        if (l > r) return;
        if (tr < l || tl > r) return;
        if (l <= tl && tr <= r) {
            int sz = tr - tl + 1;
            // Apply the lazy value
            // t[id] += val * sz;
            t[id] += val;
            // Aggregate the lazy value
            lazy[id] += val;
        } else {
            int tm = (tl + tr) / 2;
            int left = id + 1;
            int right = id + 2 * (tm - tl + 1);
            push(id, tl, tr);
            update(l, r, val, left, tl, tm);
            update(l, r, val, right, tm + 1, tr);
            t[id] = combine(t[left], t[right]);
        }
    } */

    // Point update
    void update(int pos, int val, int id, int tl, int tr) {
        if(tl == tr) {
            t[id] = val;
        }
        else {
            int tm = (tl + tr) / 2;
            int left = id + 1;
            int right = id + 2 * (tm - tl + 1);
            if(pos <= tm)
                update(pos, val, left, tl, tm);
            else
                update(pos, val, right, tm + 1, tr);

            t[id] = max(t[left], t[right]);
        }
    }

    void update(int pos, int val) {
        assert(n > 0);
        update(pos, val, 1, 1, n);
    }
} st;

struct Graph {
    vector<int> adj[MX];
    int parent[MX];
    int depth[MX];
    int heavy[MX];
    int head[MX];
    int pos[MX];
    int curPos = 0;
    int conteo = 1;
    int posEntrada[MX], posSalida[MX];

    void clear(int n) { // O(n)
        conteo = 1;
        for (int i = 0; i <= n; i++) {
            adj[i].clear();
            parent[i] = -1;
            heavy[i] = -1;
            depth[i] = head[i] = pos[i] = 0;
        }
        curPos = 0;
    }

    void addEdge(int u, int v) { // O(1)
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int dfs(int u = 1) { // O(V + E)
        int sz = 1;
        int maxSize = 0;
        heavy[u] = -1;
        for (int v : adj[u]) {
            if (v != parent[u]) {
                parent[v] = u;
                depth[v] = depth[u] + 1;
                int szV = dfs(v);
                sz += szV;
                if (szV > maxSize) {
                    maxSize = szV;
                    heavy[u] = v;
                }
            }
        }
        return sz;
    }

    void decompose(int u, int h) { // O(V + E)
        posEntrada[u] = conteo;
        head[u] = h;
        pos[u] = ++curPos;
        if (heavy[u] != -1) {
            conteo++;
            decompose(heavy[u], h);
        }
        for (int v : adj[u]) {
            if (v != parent[u] && v != heavy[u]) {
                conteo++;
                decompose(v, v);
            }
        }
        posSalida[u] = conteo;
    }

    void build(int root = 1) {
        curPos = 0;
        depth[root] = 0;
        parent[root] = -1;
        dfs(root);
        decompose(root, root);
    }
    void update(int u, int val) {
        st.update(pos[u], val);
    }

    int query(int u, int v) { // O(O(|query|) log V)
        int ans = 0;
        while (head[u] != head[v]) {
            if (depth[head[u]] > depth[head[v]]) {
                swap(u, v);
            }
            int curHeavyVal = st.query(pos[head[v]], pos[v]);
            ans = max(ans, curHeavyVal);
            // cout << "Respuesta: " << ans << " Nodos: " << head[v] << " " << v << endl;
            v = parent[head[v]];
        }
        if (depth[u] > depth[v]) swap(u, v);
        // u = heavy[u];          // when weight are on edges
        // if (u == -1) return 0; // when weight are on edges

        // last heavy path
        int lastVal = st.query(pos[u], pos[v]);
        ans = max(ans, lastVal);
        return ans;
    }

} G;

int main() {
    inic;
    inic2;

    int n, q;
    cin >> n >> q;
    vector <int> vec(n);
    for(int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    for(int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        G.addEdge(a,b);
    }
    G.build();      // intENO LOS ARREGLOS NECESARIO DE HEAVY LIGHT
    vector<int> hldValues(n);
    for (int i = 1; i <= n; i++) {
        hldValues[G.pos[i] - 1] = vec[i - 1];
    }

    st.build(hldValues);

    while(q--) {
        short op;
        cin >> op;
        if(op == 1) {
            int s, x;
            cin >> s >> x;
            G.update(s,x);
        }
        else {
            int a, b;
            cin >> a >> b;
            cout << G.query(a,b) << ' ';
        }
    }
    return 0;
}
