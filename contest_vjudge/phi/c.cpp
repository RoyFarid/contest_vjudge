#include <bits/stdc++.h>
using namespace std;
#define inic ios_base::sync_with_stdio(false)
#define inic1 cin.tie(NULL)
#define inic2 cout.tie(NULL)
#define sl '\n'
typedef long long ll;

const ll MX = 1e9 + 1;
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

/* void preprocesar_phi(ll n) { // O(n log log n)
    for (int i = 0; i <= n; i++) phi[i] = i;
    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i) phi[j] -= phi[j] / i;
        }
    }
} */
int main() {
    inic;
    inic1;
    inic2;
    while(true) {
        ll n;
        cin >> n;
        if(n == 0) {
            break;
        }
        cout << phi(n) << sl;

    }
    return 0;
}