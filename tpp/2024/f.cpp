#include <bits/stdc++.h>
using namespace std;
#define inic ios_base::sync_with_stdio(false);
#define inic1 cin.tie(NULL);
#define inic2 cout.tie(NULL);
typedef long long ll;
#define sl '\n'
int main() {
    inic;
    inic1;
    inic2;
    int t = 1;
    //cin >> t;
    while(t--) {
        int l, r, z; cin >> l >> r >> z;
        bool f = 1;
        vector <pair<int,int>> v;
        vector <int> d;
        for(int i = l; i < r  && f; i++) {
            for(int j = i + 1; j <= r && f; j++) {
                if(i + j == z) {
                    v.push_back({i, j});
                    d.push_back(j-i);
                }
            }
        }

        int mi = r - l + 1;
        int pos = -1;
        for(int i = 0; i < d.size(); i++) {
            if(d[i] < mi) {
                mi = d[i];
                pos = i;
            }
        }

        if(pos == -1) cout << "no hay respuesta";
        else cout << v[pos].second << " " << v[pos].first;
    }
    return 0;
}