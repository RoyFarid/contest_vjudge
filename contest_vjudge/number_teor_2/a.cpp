#include <bits/stdc++.h>
using namespace std;
#define inic ios_base::sync_with_stdio(false);
#define inic1 cin.tie(NULL);
#define inic2 cout.tie(NULL);
typedef long long ll;

ll extendedGcd(ll a, ll b, ll &x, ll &y) {
	if(b == 0){
		x = a >= 0 ? 1: -1, y = 0;
		return abs(a);
	} else {
		ll x2, y2, g = extendedGcd(b, a % b , x2, y2);
		x = y2, y = x2 - (a / b) * y2;
		return g;
	}
}

bool diophantine(ll a, ll b, ll c, ll &x, ll &y, ll &g) {
    if(a == 0 && b == 0){
		if(c != 0) 
            return false;
		else {
			x = y = g = 0;
			return true;
		}
	} else {
        g = extendedGcd(a, b, x, y);
        if (c % g != 0) 
            return false;
        else {
            x *= c / g, y *= c / g;
            return true;
        }
    }
}

int main() {
    inic;
    inic1;
    inic2;
    ll A, B, C;
    cin >> A >> B >> C;
    C *= -1;
    ll x, y, g;
    if(diophantine(A, B, C, x, y, g)) {
        if( x >= -5e18 && x <= 5e18 && y >= -5e18 && y <= 5e18)
        cout << x << " " << y;

        else 
            cout << "-1";
    }
    else {
        cout << "-1";
    }
    return 0;

}