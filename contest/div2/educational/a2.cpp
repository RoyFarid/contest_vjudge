#include <bits/stdc++.h>
using namespace std;
#define inic ios_base::sync_with_stdio(false);
#define inic1 cin.tie(NULL);
#define inic2 cout.tie(NULL);
#define sl '\n';
typedef long long ll;

const ll MOD = 998244353;
const ll MX = 2e5 + 1;

ll suma_mod(ll a, ll b, ll mod) {
    return (a + b) % mod;
}

int main() {
    inic;
    inic1;
    inic2;

    // Precomputamos potencias de 2 módulo MOD
    ll dp[MX];
    dp[0] = 1;
    for (int i = 1; i < MX; i++) {
        dp[i] = (dp[i - 1] * 2) % MOD;
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<ll> prefix_count(n + 1, 0); // Suma acumulada de `2`s
        vector<int> ones, threes; // Posiciones de `1`s y `3`s

        // Leer entrada y precomputar sumas de `2`s
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] == 1) ones.push_back(i);
            else if (a[i] == 3) threes.push_back(i);
            prefix_count[i + 1] = prefix_count[i] + (a[i] == 2 ? 1 : 0);
        }

        ll sum = 0;

        // Para cada `1`, buscamos el primer `3` con `lower_bound`
        for (int i : ones) {
            auto it = lower_bound(threes.begin(), threes.end(), i + 2);
            while (it != threes.end()) {
                int j = *it;
                ll count2 = prefix_count[j] - prefix_count[i];
                if (count2 > 0) {
                    sum = suma_mod(sum, dp[count2] - 1, MOD);
                }
                ++it; // Avanzamos al siguiente `3`
            }
        }

        cout << sum << sl;
    }

    return 0;
}

