#include <bits/stdc++.h>
#define debug(x) cout << #x << " = " << x << endl
#define REP(i, n) for (Long i = 0; i < (Long)n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

ll getBit(ll x, ll i) {
    return (x >> i) & 1LL;
}

void turnOn(ll &x, ll i) {
    x = x | (1LL << i);
}

void turnOff(ll &x, ll i) {
    x = x & (~(1LL << i));
}

void changeBit(ll &x, ll i) {
    x = x ^ (1LL << i);
}

int main() {
    return 0;
}