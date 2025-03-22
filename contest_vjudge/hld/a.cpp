#include <bits/stdc++.h>
#define pb push_back
#define inic ios_base::sync_with_stdio(false)
#define inic2 cin.tie(NULL)
#define inic3 cout.tie(NULL)
#define sl '\n'
using namespace std;
typedef long long ll;

const int MAXN = 200002;
vector<int> adj[MAXN], values(MAXN);
int parent[MAXN], depth[MAXN], heavy[MAXN], head[MAXN], pos[MAXN];
int segtree[4 * MAXN], arr[MAXN];
int cur_pos = 0;

void build(int node, int start, int end) {
    if (start == end) {
        segtree[node] = arr[start];
    } else {
        int mid = (start + end) / 2;
        int left = 2 * node;
        int right = left + 1;
        build(left, start, mid);
        build(right, mid + 1, end);
        segtree[node] = max(segtree[left], segtree[right]);
    }
}

void update(int node, int start, int end, int idx, int val) {
    if (start == end) {
        segtree[node] = val;
    } else {
        int left = 2 * node;
        int right = left + 1;
        int mid = (start + end) / 2;
        if (idx <= mid)
            update(left, start, mid, idx, val);
        else
            update(right, mid + 1, end, idx, val);
        segtree[node] = max(segtree[left], segtree[right]);
    }
}

int query(int node, int start, int end, int l, int r) {
    if (r < start || end < l) return INT_MIN;
    if (l <= start && end <= r) return segtree[node];
    int left = 2 * node;
    int right = left + 1;
    int mid = (start + end) / 2;
    return max(query(left, start, mid, l, r), query(right, mid + 1, end, l, r));
}

int dfs(int v) {
    int size = 1, max_subtree = 0;
    heavy[v] = -1;
    for (int u : adj[v]) {
        if (u == parent[v]) continue;
        parent[u] = v;
        depth[u] = depth[v] + 1;
        int subtree_size = dfs(u);
        if (subtree_size > max_subtree) {
            max_subtree = subtree_size;
            heavy[v] = u;
        }
        size += subtree_size;
    }
    return size;
}

void decompose(int v, int h) {
    head[v] = h;
    pos[v] = cur_pos;
    arr[cur_pos++] = values[v];
    if (heavy[v] != -1) decompose(heavy[v], h);
    for (int u : adj[v]) {
        if (u != parent[v] && u != heavy[v]) {
            decompose(u, u);
        }
    }
}

int query_hld(int a, int b) {
    int res = INT_MIN;
    while (head[a] != head[b]) {
        if (depth[head[a]] < depth[head[b]]) swap(a, b);
        res = max(res, query(1, 0, cur_pos - 1, pos[head[a]], pos[a]));
        a = parent[head[a]];
    }
    if (depth[a] > depth[b]) swap(a, b);
    res = max(res, query(1, 0, cur_pos - 1, pos[a], pos[b]));
    return res;
}

int main() {
    inic;
    inic2;
    inic3;

    int n, q;
    cin >> n >> q;

    if (n == 1) {
      int val;
      cin >> val;
      while (q--) {
          int op;
          cin >> op;
          if (op == 1) {
              int s, x;
              cin >> s >> x;
              val = x;
          } else {
              int a, b;
              cin >> a >> b;
              cout << val << " ";
          }
      }
      return 0;
    }
    
    for (int i = 1; i <= n; i++) {
        cin >> values[i];
    }
    
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    parent[1] = -1;
    depth[1] = 0;
    dfs(1);
    decompose(1, 1);
    build(1, 0, cur_pos - 1);
    
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int s, x;
            cin >> s >> x;
            update(1, 0, cur_pos - 1, pos[s], x);
        } else {
            int a, b;
            cin >> a >> b;
            cout << query_hld(a, b) << " ";
        }
    }
    
    return 0;
}
