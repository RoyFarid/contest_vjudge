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
    if(a >= mod) {
        a -= mod;
    }
    if(b >= mod) {
        b -= mod;
    }
    if(a+b >= mod) {
        return a + b - mod;
    }
    return a + b;
}

int main() {
    inic;
    inic1;
    inic2;
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
            vector<int> ones, threes;
            vector<ll> two_count(n + 1, 0);
    
            for (int i = 0; i < n; i++) {
                cin >> a[i];
                if (a[i] == 1) {
                    ones.push_back(i);
                } else if (a[i] == 3) {
                    threes.push_back(i);
                }
                if (a[i] == 2) {
                    two_count[i + 1] = two_count[i] + 1;
                } else {
                    two_count[i + 1] = two_count[i];
                }
            }
    
            ll sum = 0;
            for (int i : ones) {
                auto it = lower_bound(threes.begin(), threes.end(), i + 2);
                while (it != threes.end()) {
                    int j = *it;
                    ll count2 = two_count[j] - two_count[i];
                    if (count2 > 0) {
                        sum = suma_mod(sum, dp[count2] - 1, MOD);
                    }
                    ++it;
                }
            }
    
            cout << sum << sl;
        }

    return 0;
}