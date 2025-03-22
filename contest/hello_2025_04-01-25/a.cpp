#include <bits/stdc++.h>
using namespace std;
#define inic ios_base::sync_with_stdio(false);
#define inic1 cin.tie(NULL);
#define inic2 cout.tie(NULL);
typedef long long ll;

int main() {
    inic;
    inic1;
    inic2;
    ll t;
    cin >> t;
    while(t--) {
        ll n, m;
        cin >> n >> m;
            cout << max(n, m) + 1 << "\n";     
    }
    return 0;
       
}