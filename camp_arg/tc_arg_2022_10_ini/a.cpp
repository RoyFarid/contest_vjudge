#include <bits/stdc++.h>
using namespace std;
#define inic ios_base::sync_with_stdio(false)
#define inic1 cin.tie(NULL)
#define inic2 cout.tie(NULL)
#define sl '\n'
typedef long long ll;

const ll MX = 1e5 + 5;
bool es_primo[MX];
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
    criba(100000);
    ll n;
    cin >> n;
    if(n <= 2) {
        cout << 1 << sl;
    }
    else {
        cout << 2 << sl;
    }
    for(ll i = 2; i <= n + 1; i++) {
        if(es_primo[i]) {
            cout << 1 << " ";
        }
        else {
            cout << 2 << " ";
        }
    }
    return 0;
}