#include <bits/stdc++.h>
using namespace std;
#define inic ios_base::sync_with_stdio(false)
#define inic1 cin.tie(NULL)
#define inic2 cout.tie(NULL)
#define sl '\n'
typedef long long ll;

ll phi(ll n) { // O(sqrt(n))
    ll ans = n;
    ll i = 2;
    while (i * i <= n) {
        if (n % i == 0) {
            while (n % i == 0) n /= i;
            ans -= ans / i;
        }
        i++;
    }
    if (n > 1) ans -= ans / n;
    return ans;
}

ll cant_div(ll n) {
    ll cont = 0;
    for(ll i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            cont++;
            if(i != n / i) {
                cont++;
            }
        }
    }
    return cont;
}

ll ans(ll n) {
    if(n <= 1) return 0;
    return n - phi(n) - cant_div(n) + 1;
}

int main() {
    inic;
    inic1;
    inic2;
    ll n;
    while(cin >> n) {
        cout << ans(n) << sl;

    }
    return 0;
}