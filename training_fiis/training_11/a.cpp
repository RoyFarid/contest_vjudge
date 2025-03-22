#include <bits/stdc++.h>
using namespace std;
#define inic ios_base::sync_with_stdio(false);
#define inic1 cin.tie(NULL);
#define inic2 cout.tie(NULL);
typedef long long ll;

const ll MX = 1e9;

int main() {
    inic;
    inic1;
    inic2;
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector <ll> a(n);
        vector <ll> b;
        for(ll i = 0; i < n; i++) {
            cin >> a[i];
            if(i > 0) {
                b.push_back(__gcd(a[i],a[i-1]));
            }
        }
        ll elim = 0;
        bool flag = false;
        for(ll i = 0; i < n - 2; i++) {
            if((b[i] > b[i+1])) {
                if(i == 0) {
                    ll gcd3 = __gcd(a[i+1], a[i+3]);
                    if(gcd3 >= b[i] && b[i+3] >= gcd3) {
                        b[i+1] = gcd3;
                        b[i+2] = gcd3;
                    }
                    else {
                        b[i] = 0;
                    }
                }
                else if(i == n-3) {
                    b[i+1] = MX; 
                }
                else { 
                    ll gcd1 = __gcd(a[i-1], a[i+1]);
                    ll gcd2 = __gcd(a[i], a[i+2]);
                    ll gcd3 = __gcd(a[i+1], a[i+3]);
                    if(gcd3 >= b[i] && b[i+3] >= gcd3) {
                        b[i+1] = gcd3;
                        b[i+2] = gcd3;
                    }
                    else if(gcd2 >= b[i-1] && b[i+2] >= gcd2) {
                        b[i] = gcd2;
                        b[i+1] = gcd2;
                    }
                    else {
                        b[i] = gcd1;
                        b[i-1] = gcd1;
                    }
                }
                break;
            }
        }

        for(auto x : b) {
            cout << x << " ";
        }
        cout << endl;
        bool f = true;
        for(ll i = 0; i < n - 2; i++) {
            if(b[i] > b[i+1]) {
                f = false;
                break;
            }
        }
        if(f) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
            
    }
    return 0;
}