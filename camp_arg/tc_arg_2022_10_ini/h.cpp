#include <bits/stdc++.h>
using namespace std;
#define inic ios_base::sync_with_stdio(false)
#define inic1 cin.tie(NULL)
#define inic2 cout.tie(NULL)
#define sl '\n'
typedef long long ll;

int main() {
    inic;
    inic1;
    inic2;
    int n, m;
    cin >> n >> m;

    vector<set<int>> adj(n + 1);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
    }

    map<int, set<int>> grad;
    for (int i = 1; i <= n; ++i) {
        grad[adj[i].size()].insert(i);
    }

    for (auto &g : grad) {
        vector<int> nodes(g.second.begin(), g.second.end());
        int size = nodes.size();

        for (int i = 0; i < size; ++i) {
            for (int j = i + 1; j < size; ++j) {
                if (adj[nodes[i]].find(nodes[j]) == adj[nodes[i]].end()) {
                    cout << "NO" << sl;
                    return 0;
                }
            }
        }
    }

    cout << "YES" << sl;
    return 0;
}