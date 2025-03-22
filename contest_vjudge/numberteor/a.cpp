#include <bits/stdc++.h>
using namespace std;
#define inic ios_base::sync_with_stdio(false);
#define inic1 cin.tie(NULL);
#define inic2 cout.tie(NULL);
typedef long long ll;

const ll MX = 1e5 + 5;

vector<ll> primos;
ll primerFactor[MX];
bool no_primo[MX];
void criba(ll n) { // n*log(log(n)) n=10^7
    no_primo[0] = no_primo[1] = true;
    for (ll i = 1; i <= n; i++) {
        primerFactor[i] = i;
    }
    for (long long i = 2; i <= n; i++) {
        if (no_primo[i] == false) {
            for (long long j = 2 * i; j <= n; j += i) {
                no_primo[j] = true;
                if (primerFactor[j] == j) {
                    primerFactor[j] = i;
                }
            }
        }
    }

    ll t = 0;
    for (long long i = 2; i <= n; i++) {
        if (no_primo[i] == false) {
            primos.push_back(i);
        }
    }
}

int main() {
    criba(40);
    ll T, N;
    cin >> T;
    while(T--) {
        cin >> N;
        ll prod = 1;
        for(ll x : primos) {
            ll final = x;
            if(final > N) {
                final = 1;
            }
            else {
                while(true) {
                    if(final > N) {
                        final /= x;
                        break;
                    }
                    final *= x;
                }
            }
            prod *= final;
        }
        cout << prod << "\n";
    }
    return 0;
}