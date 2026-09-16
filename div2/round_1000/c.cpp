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
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector <int> d(n + 1, 0);
        vector <pair<int,int>> nose(n);
        map <pair<int,int>, bool> m;
        vector <pair<int, int>> p(n - 1);
        for(int i = 0; i < n - 1; i++) {
            int u, v; cin >> u >> v;
            d[u]++;
            d[v]++;
            m[{u,v}] = 1;
            p[i].first = u;
            p[i].second = v;
        }

        for(int i = 0; i < n; i++) {
            nose[i].first = d[i+1];
            nose[i].second = i + 1;
        }
        int ans = 0;
        for(int i = 0; i < n - 1; i++) {
            ans = max(ans, d[p[i].first] + d[p[i].second] - 2);
        }

        /* for( auto p :  nose) {
            cout << p.first << " " << p.second << sl;
        } */

        sort(nose.rbegin(), nose.rend());
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(m[{nose[i].second,nose[j].second}] == 0 && m[{nose[j].second,nose[i].second}] == 0) {
                    ans = max(ans, nose[i].first + nose[j].first - 1);
                    break;
                }
            }
        }

        cout << ans << sl;



    }
    return 0;
}