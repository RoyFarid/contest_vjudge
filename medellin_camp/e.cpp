#include <bits/stdc++.h>
using namespace std;
#define inic ios_base::sync_with_stdio(false)
#define inic1 cin.tie(NULL)
#define inic2 cout.tie(NULL)
#define sl '\n'
typedef long long ll;

const ll MOD = 1e9 + 7;

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

ll mult_mod(ll a, ll b, ll mod) {
    return ((a%mod) * (b%mod)) % mod;
}

int main () {
    inic;
    inic1;
    inic2;
    int n; 
    cin >> n;
    int arr[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector <int> divs;
    int c = arr[0];
    int pos = 0; 
    for(int i = 0; i < n; i++) {
        if(arr[i] > c) {
            c = arr[i];
            int cant_divs = i - pos + 1;
            divs.push_back(cant_divs);
            pos = i;
        }
    }

    ll prod = 1;
    for(int x : divs) {
        prod = mult_mod(prod, x, MOD);
    }

    cout << prod;
    return 0;
}