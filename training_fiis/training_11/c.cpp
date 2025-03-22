#include <bits/stdc++.h>
using namespace std;
#define inic ios_base::sync_with_stdio(false);
#define inic1 cin.tie(NULL);
#define inic2 cout.tie(NULL);
typedef long long ll;

const ll MX = 998244353;

int main() {
    inic;
    inic1;
    inic2;
    ll n;
    cin >> n;
    if(n <= 2) {
        cout << "1";
    }
    else {
        cout << (2*n) % MX;
    }
    return 0;
}