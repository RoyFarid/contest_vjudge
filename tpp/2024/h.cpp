#include <bits/stdc++.h>
using namespace std;
#define inic ios_base::sync_with_stdio(false);
#define inic1 cin.tie(NULL);
#define inic2 cout.tie(NULL);
typedef long long ll;
#define sl '\n'

int main() {
    inic;
    inic1;
    inic2;
    int t = 1;
    //cin >> t;
    while(t--) {
        int n; double p;
        cin >> n >> p;
        vector<double> a(n);
        for (double &x : a) cin >> x;
        double ans = 0, m = 1e18;
        for (int i = n - 1; i >= 0; i--) {
            m = min(m, a[i]);
            //1 ahorrar, p/m comprar;
            ans += 100.0 * max(1.0, p / m);
        }
        cout << fixed << setprecision(10) << ans << sl;
    }
    return 0;
}
