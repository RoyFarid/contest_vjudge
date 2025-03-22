#include <bits/stdc++.h>
using namespace std;
#define inic ios_base::sync_with_stdio(false);
#define inic1 cin.tie(NULL);
#define inic2 cout.tie(NULL);
typedef long long ll;

int main() {
    inic;
    inic1;
    inic2;
    int t;
    cin >> t;
    while(t--) {
        int n,m;
        cin >> n >> m;
        vector<vector<int>> v(n, vector<int>(m));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> v[i][j];
            }
            sort(v[i].begin(),v[i].end());
        }

        vector<vector<int>> v_or(n, vector<int>(m));
        for(int i = 0; i < n; i++) {
            int razon = i;
            for(int j = 0; j < m; j++) {
                v_or[i][j] = razon;
                razon += n;
            }
        }

        vector<int> p(n);
        iota(p.begin(), p.end(), 1);
        for(int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if(v[i][0] > v[j][0]) {
                    vector <int> temp_v = v[i];
                    v[i] = v[j];
                    v[j] = temp_v;
                    ll temp = p[i];
                    p[i] = p[j];
                    p[j] = temp;
                }
            }
        }

        if(v == v_or) {
            for(auto x : p) {
                cout << x << " ";
            }
        }
        else {
            cout << "-1";
        }
        
        cout << "\n";
    }
        
    return 0;
}