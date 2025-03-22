#include <bits/stdc++.h>
using namespace std;
#define inic ios_base::sync_with_stdio(false);
#define inic1 cin.tie(NULL);
#define inic2 cout.tie(NULL);
typedef long long ll;

int main() {
    inic;
    inic1;
    inic2;
    int n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    vector<ll> t(n);
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }

    vector<ll> derr(n, 0);
    vector<ll> piles;

    for (int i = 0; i < n; i++) {
        piles.push_back(v[i]);
        ll d = 0;
        vector<ll> piles2;

        for (ll pile : piles) {
            ll part_d = min(pile, t[i]);
            d += part_d;
            pile -= part_d;
            if (pile > 0) {
                piles2.push_back(pile);
            }
        }

        derr[i] = d;
        piles = piles2;
    }

    for (int i = 0; i < n; i++) {
        cout << derr[i] << " ";
    }

    return 0;
}