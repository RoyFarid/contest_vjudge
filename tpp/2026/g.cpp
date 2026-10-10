#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sl '\n' 
ll n;
bool f(vector<ll>&x, vector<ll> &y, ll k, ll target) {
    ll sum = 0;
    for(ll i = 0; i < n; i++) {
        if(y[i] + x[i]*k < 0) continue;
        sum += y[i] + x[i]*k;
        if(sum>=target) return 1;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while (t--) {
        ll target; cin >> n >> target;
        vector<ll>x(n);
        vector<ll>y(n);
        for(ll i = 0; i <n; i++) {
            cin >> x[i];
        }
        for(ll i = 0; i <n; i++) {
            cin >> y[i];
            y[i]*=-1;
        }

        ll l = 1, r = 2e9;
        while(l < r) {
            if(l == r) break;
            ll m = (l + r) / 2;
            if(!f(x, y, m, target)) l = m + 1;
            else r = m;
        }
        cout << l;
    }   
    return 0;
}
