#include <bits/stdc++.h>
using namespace std;
#define inic ios_base::sync_with_stdio(false);
#define inic1 cin.tie(NULL);
#define inic2 cout.tie(NULL);
typedef long long ll;

ll step(ll cur, ll x) {
        if(cur - x > 0) {
            return cur - x;
        }
        else {
            return cur + x;

        }
}

int main() {
    inic;
    inic1;
    inic2;
    ll n, k ,s;
    cin >> n >> k >> s;
    ll c = 1;
    ll l;

    if(k > s or k * (n - 1) < s)
        cout << "NO";
    else {
        cout << "YES" << endl;
        while(k > 0){
            l = min(n - 1, s - (k - 1));
            c = step(c, l);
            cout << c << " ";
            s -= l;
            k -= 1;
        }
    }
    return 0;
}