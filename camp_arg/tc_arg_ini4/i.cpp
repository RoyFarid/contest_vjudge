#include <bits/stdc++.h>
using namespace std;
#define inic ios_base::sync_with_stdio(false);
#define inic1 cin.tie(NULL);
#define inic2 cout.tie(NULL);
#define sl '\n';
typedef long long ll;

int main() {
    inic;
    inic1;
    inic2;
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector <ll> adj[n + 1];
        ll a = n - 1;
        for(int i = 0; i < a; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        if(adj[x].size() == 1 || n == 1) {
            cout << "Ayush";
        }
        else {
            if(n % 2 == 1) {
                cout << "Ashish";
            }
            else {
                cout << "Ayush";
            }
        }
        cout << sl;
    }
    return 0;
}