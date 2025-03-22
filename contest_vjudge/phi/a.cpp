#include <bits/stdc++.h>
using namespace std;
#define inic ios_base::sync_with_stdio(false)
#define inic1 cin.tie(NULL)
#define inic2 cout.tie(NULL)
#define sl '\n'
typedef long long ll;

const ll MX = 1000001;

ll phi[MX];
ll f[MX];
ll ans[MX];
void preprocesar_phi(ll n) { // O(n log log n)
    for (int i = 0; i <= n; i++) phi[i] = i;
    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i) phi[j] -= phi[j] / i;
        }
    }
    for (int i = 1; i <= n; i++) { // O(n log n)
        for (int j = i; j <= n; j += i) {
            f[j] += (i * phi[j/i]);
        }
    }

    for(int i = 1; i <= n; i++) {
        ans[i] = ans[i-1] + f[i] - i;
    }
}
int main() {
    inic;
    inic1;
    inic2;
    preprocesar_phi(1000000);
    while(true) {
        ll n;
        cin >> n;
        if(n == 0) {
            break;
        }
        cout << ans[n] << sl;

    }
    return 0;
}