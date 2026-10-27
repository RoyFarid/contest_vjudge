#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sl '\n' 
//min a[i] tal que a[i] = b[j] - a[i] = target;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        ll n, m; cin >> n >> m;
        vector<ll>a(n+1),b(m);
        for(ll i = 1; i <= n; i++) cin >> a[i];
        for(ll i = 0; i < m; i++) cin >> b[i];
        a[0] = -2e9;
        sort(b.begin(),b.end());
        bool ans = 1;
        for(ll i = 1; i <= n; i++) {
            ll l = 0;
            ll r = m - 1;
            while(l < r) {
                ll med = (l + r) / 2;
                if(b[med] - a[i] < a[i-1]) {
                    l = med + 1;
                }
                else r = med;
            }
            if(a[i] < a[i-1] && b[l] - a[i] < a[i-1]) {
                ans = 0;
                break;
            }
            if(a[i] >= a[i-1] && b[l] - a[i] >= a[i-1]) a[i] = min(a[i], b[l] - a[i]);
            if(a[i] < a[i-1] && b[l] - a[i] >= a[i-1]) a[i] = b[l] - a[i];

        }
        // for(ll e : a) cout << e << " ";
        // cout << sl;
        if(ans) cout << "YES";
        else cout << "NO";
        cout << sl;
    }   
    return 0;
}
