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
        ll n, k; cin >> n >> k;
        vector <ll> v(n);
        vector <bool> vis(n, 0);
        for(ll &e : v) cin >> e;
        vector <ll> m;
        for(ll i = 0; i < n - 1; i++) {
            if(v[i] == v[i + 1]) {
                vis[i] = 1;
                vis[i+1] = 1;
                m.push_back(v[i]);
                ll j = 1;
                while(i - j >= 0 && i + 1 + j < n) {
                    if(v[i - j] == v[i + 1 + j] && !vis[i-j] && !vis[i + 1 + j]) {
                        m.push_back(v[i-j]);
                        vis[i - j] = 1;
                        vis[i + 1 + j] = 1;
                    }
                    else break;
                    j++;
                }
                i += j;
            }
        }
        sort(m.begin(), m.end());
        ll sz = m.size();
        if (sz < k) {
            cout << -1 << sl;
            continue;
        }
        ll ans = 0;
        for(ll i = sz - 1; i >= sz - k; i--) {
            if(i == sz - 1) {
                ans += m[i] * (sz - k + 1);
            }
            else ans += m[i];
        }
        cout << ans << sl;


    }
    return 0;
}