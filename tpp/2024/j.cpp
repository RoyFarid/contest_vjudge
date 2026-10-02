#include <bits/stdc++.h>
using namespace std;
#define inic ios_base::sync_with_stdio(false);
#define inic1 cin.tie(NULL);
#define inic2 cout.tie(NULL);
typedef long long ll;
#define sl '\n'
ll first1(ll n) {
    ll ans = 0;
    while(n > 0) {
        int cif = n % 2;
        if(cif == 1) break;
        n /= 2; 
        ans++;
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
        ll n, m; cin >> n >> m;
        int ans = 0;
        while(n < m) {
            ll s = (ll(1) << first1(n));
            n += s;
            ans ++;
            if(n >= m) break;
        }
        if(n == m) cout << ans;
        else cout << -1;
    }
    return 0;
}