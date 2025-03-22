#include <bits/stdc++.h>
using namespace std;
#define inic ios_base::sync_with_stdio(false);
#define inic1 cin.tie(NULL);
#define inic2 cout.tie(NULL);
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int a[n+1], b[n+1];
        ll suma = 0;
        for(int i = 1; i < n + 1; i++) {
            cin >> a[i];
        }
        for(int i = 1; i < n + 1; i++) {
            cin >> b[i];
        }
        for(int i = 1; i < n; i++) {
            if(a[i] > b[i+1]) {
                suma += (a[i]-b[i+1]);
            }
        }
        suma += a[n];
        cout << suma << "\n";
    }
    return 0;
}