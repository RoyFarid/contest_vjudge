#include <bits/stdc++.h>
using namespace std;
#define inic ios_base::sync_with_stdio(false);
#define inic1 cin.tie(NULL);
#define inic2 cout.tie(NULL);
typedef long long ll;
#define sl '\n'

void solve(deque <ll> &d, ll &ans) {
    if(d.size() == 1) {
        return;
    }
    deque <ll> d1;
    ll val1 = 0;
    for(auto it = d.begin() + 1; it < d.end(); it++) {
        auto itc = it - 1;
        ll c = *it - *itc;
        val1 += c;
        d1.push_back(c);
    }
    ans = max(val1,ans);
    val1 *= (-1);
    ans = max(val1,ans);
    solve(d1, ans);
    return;
}

int main() {
    inic;
    inic1;
    inic2;
    ll t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        deque <ll> d;
        ll ans = 0;
        for(ll i = 0; i < n; i++) {
            ll a; cin >> a;
            d.push_back(a);
            ans+=a;
        }

        solve(d, ans);
        cout << ans << sl;
    }
    return 0;
}