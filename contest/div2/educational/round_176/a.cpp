#include <bits/stdc++.h>
#define pb push_back
#define inic ios_base::sync_with_stdio(false)
#define inic2 cin.tie(NULL)
#define inic3 cout.tie(NULL)
#define sl '\n'
using namespace std;
typedef long long ll;

int main() {
    inic;
    inic2;
    inic3;
    int t; 
    cin >> t;
    while(t--) {
        ll n, k;
        cin >> n >> k;
        ll ans = 0;
        vector <ll> v(n);
        for(ll i = 0; i < n; i++) {
            /* v[i].first = i + 1;
            cin >> v[i].second; */
            cin >> v[i];
        }
        if(k > 1) {
            sort(v.begin(), v.end());
            ll pos = n - 1;
            for(ll i = 0; i < k + 1; i++) {
                ans += v[pos];
                pos--;
            }
        }

        else {
            ll e_l = v[0];
            ll e_r = v[n-1];
            if (n > 2) {
                auto m = max_element(v.begin() + 1, v.end() - 1);
                ans += *m;
                ans += max(e_l, e_r);
                ans = max(ans, e_l + e_r);
            }
            else {
                ans = e_l + e_r;
            }
        }
        cout << ans << sl;
    }
    return 0;
}