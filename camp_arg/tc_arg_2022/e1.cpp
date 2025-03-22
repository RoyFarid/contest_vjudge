#include <bits/stdc++.h>
using namespace std;
#define inic ios_base::sync_with_stdio(false);
#define inic1 cin.tie(NULL);
#define inic2 cout.tie(NULL);
#define sl '\n';
typedef long long ll;

const int MOD = 1e9 + 7;

ll mult_mod(ll a, ll b, ll mod) {
    return ((a%mod) * (b%mod)) % mod;
}

ll pot_mod (ll a, ll b, ll mod) {
    ll ans = 1;
    while(b > 0) {
        if(b & 1 == 1) {
            ans = mult_mod(ans, a, mod);
        }
        a = mult_mod(a, a, mod);
        b >>= 1;
    }
    return ans;
}

int main() {
    inic;
    inic1;
    inic2;
    
    int n, m;
    cin >> n >> m;

    vector<int> pos(m);
    for (int i = 0; i < m; i++) {
        cin >> pos[i];
    }

    sort(pos.begin(), pos.end());

    vector<int> huecos;
    int total_moves = 0;

    for (int i = 1; i < m; i++) {
        int h = pos[i] - pos[i - 1] - 1;
        if (h > 0) {
         huecos.push_back(h);
            total_moves += h;
        }
    }
    int left_h = pos[0] - 1;
    int right_h = n - pos[m - 1];
    total_moves += left_h + right_h;

    ll f = 1;

    for (int h : huecos) {
        f = (f * pot_mod(2, h - 1, MOD)) % MOD;
    }

    for (int i = 1; i <= total_moves; i++) {
        f = (f * i) % MOD;
    }
    for (int i = 1; i <= left_h; i++) {
        f = (f * pot_mod(i, MOD - 2, MOD)) % MOD;
    }
    for (int i = 1; i <= right_h; i++) {
        f = (f * pot_mod(i, MOD - 2, MOD)) % MOD;
    }
    for (int h : huecos) {
        for (int i = 1; i <= h; i++) {
            f = (f * pot_mod(i, MOD - 2, MOD)) % MOD;
        }
    }

    cout << f << "\n";
    return 0;
}


