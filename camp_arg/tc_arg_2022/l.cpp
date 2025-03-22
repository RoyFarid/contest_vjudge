#include <bits/stdc++.h>
using namespace std;
#define inic ios_base::sync_with_stdio(false);
#define inic1 cin.tie(NULL);
#define inic2 cout.tie(NULL);
#define sl '\n';
typedef long long ll;

ll min_prime_div(ll n) {
    if(n % 2 == 0) return 2;
    for(ll i = 3; i * i <= n; i += 2) {
        if(n % i == 0) return i;
    }
    return n;
}

int main() {
    inic;
    inic1;
    inic2;
    ll n;
    cin >> n;
    ll r = 1;
    ll d = min_prime_div(n);
    n -= d;
    r += n / 2;
    cout << r;
    return 0;
}