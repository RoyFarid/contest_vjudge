#include <bits/stdc++.h>
using namespace std;
#define inic ios_base::sync_with_stdio(false);
#define inic1 cin.tie(NULL);
#define inic2 cout.tie(NULL);
typedef long long ll;

const ll MX = 1e6 + 5;

bool es_primo[MX];
ll suma[MX];
void criba(ll n) {
    fill(es_primo, es_primo + n + 1, true);
    es_primo[0] = es_primo[1] = false;
    for (ll i = 2; i <= n; i++) {
        if (es_primo[i]) {
            for (ll j = i * i; j <= n; j += i) {
                es_primo[j] = false;
            }
        }
    }
}

int main() {
    inic;
    inic1;
    inic2;
    criba(1000000);
    ll n;
    double element;
    cin >> n;
    while(n--) {
        cin >> element;
        ll raiz = sqrt(element);
        if(raiz * raiz == element && es_primo[raiz]) {
            cout << "YES";
        }
        else {
            cout << "NO";
        }
        cout << "\n";
    }  
    return 0;
}