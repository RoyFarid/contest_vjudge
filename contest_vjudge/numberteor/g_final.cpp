#include <bits/stdc++.h>
using namespace std;
#define inic ios_base::sync_with_stdio(false);
#define inic1 cin.tie(NULL);
#define inic2 cout.tie(NULL);
typedef long long ll;

const ll MX = 15000000;

int main() {
    inic;
    inic1;
    inic2;
  
    ll n;
    cin >> n;
    vector<ll> v(n);
    ll gcd = 0;
    ll max_val = 0;
    for (ll i = 0; i < n; i++) {
        cin >> v[i];
        if(v[i] > max_val) {
            max_val = v[i];
        }
        gcd = __gcd(gcd, v[i]);
    }

    for (ll i = 0; i < n; i++) {
        v[i] /= gcd;
    }

    max_val /= gcd;

    vector<ll> d_count(MX, 0);
    for (ll x : v) {
        d_count[x]++;
    }

    bool es_primo[MX];
    fill(es_primo, es_primo + max_val + 1, true);
    for (ll d = 2; d <= max_val; d++) {
        if(es_primo[d]) {
            for (ll multiple = d * 2; multiple <= max_val; multiple += d) {
                d_count[d] += d_count[multiple];
                es_primo[multiple] = false;
            }
        }
    }

    ll max_count = 0;
    for (ll d = 2; d <= max_val; d++) {
        max_count = max(max_count, d_count[d]);
    }

    if (max_count == 0) {
        cout << "-1";
    } else {
        cout << n - max_count;
    }

    return 0;
}