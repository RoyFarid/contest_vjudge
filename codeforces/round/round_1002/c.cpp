#include <bits/stdc++.h>
using namespace std;
#define inic ios_base::sync_with_stdio(0);
#define inic1 cin.tie(0);
#define inic2 cout.tie(0);
typedef long long ll;
#define sl '\n'

int main() {
    inic;
    inic1;
    inic2;
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector <vector<int>> a(n, vector <int> (n));
        vector <int> s(n);
        for(int i = 0; i < n; i++) {
            s[i] = 0;
            for(int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }

        /* for(int i = 0; i < n; i++) {
            for(int j = 0; j <= n; j++) {
                cout <<  a[i][j] << " ";
            }
            cout << sl;
        } */
        for(int i = 0; i < n; i++) {
            for(int j = n - 1 ; j >= 0; j--) {
                if(a[i][j] != 1) break;
                s[i]++;
            }
        }

        multiset<int> m;
        for(int i = 0; i < n; i++) {
            m.insert(s[i]);
        }
        int ans = 1;
        while(!m.empty()) {
            int c = *m.begin();
            if(c >= ans) ans++;
            m.erase(m.begin());
        }

        ans = min(ans, n);
        cout << ans << sl;
    }
    return 0;
}