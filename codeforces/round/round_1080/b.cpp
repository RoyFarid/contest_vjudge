#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sl '\n' 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        vector <int> v(n + 1);
        for(int i = 1; i <= n; i++) cin >> v[i];

        vector <bool> vis(n + 1, 0);
        for(int i = 1; i <= n/2; i++) {
            if(vis[i] == 1) continue;
            int j = i;
            vector <int> p;
            while(j <= n) {
                p.push_back(v[j]);
                vis[j] = 1;
                j*=2;
            }
            sort(p.begin(), p.end());
            j=i;
            for(int e : p) {
                v[j] = e;
                j*=2;
            }
        }
        vector <int> o = v;
        sort(o.begin(), o.end());
        // for(int  e : v) cout << e << " ";
        if(o == v) cout << "YES";
        else cout << "NO";
        cout << sl;
    }   
    return 0;
}
