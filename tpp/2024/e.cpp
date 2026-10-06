#include <bits/stdc++.h>
using namespace std;
#define inic ios_base::sync_with_stdio(false);
#define inic1 cin.tie(NULL);
#define inic2 cout.tie(NULL);
typedef long long ll;
#define sl '\n'

ll f(ll n , ll d) {
    ll ans = 0;
    while(true) {
        n /= d;
        if(n == 0) break;
        ans += n;
    }
    return ans;
}

int main() {
    inic;
    inic1;
    inic2;
    int t = 1;
    //cin >> t;
    while(t--) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        ll l = 1;
        ll r = 1e14*7;
        for(int i = 0; i <= 52; i++) {
            if(r == l) break;
            ll m = (l + r) / 2;
            if(f(m, 2) < a) {
                l = m + 1;
            }
            else r = m;
        }
        a = r;
        l = 1;
        r = 1e14*7;
        for(int i = 0; i <= 52; i++) {
            if(r == l) break;
            ll m = (l + r) / 2;
            if(f(m, 3) < b) {
                l = m + 1;
            }
            else r = m;
        }
        b = r;
        l = 1;
        r = 1e14*7;
        for(int i = 0; i <= 52; i++) {
            if(r == l) break;
            ll m = (l + r) / 2;
            if(f(m, 5) < c) {
                l = m + 1;
            }
            else r = m;
        }
        c = r;
        l = 1;
        r = 1e14*7;
        for(int i = 0; i <= 52; i++) {
            if(r == l) break;
            ll m = (l + r) / 2;
            if(f(m, 7) < d) {
                l = m + 1;
            }
            else r = m;
        }
        d = r;
        ll ans = max(a,b);
        ans = max(ans, c);
        ans = max(ans, d);
        cout << ans << " " << f(ans, 2) << sl;

    }
    return 0;
}