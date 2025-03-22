#include <bits/stdc++.h>
using namespace std;
#define inic ios_base::sync_with_stdio(false);
#define inic1 cin.tie(NULL);
#define inic2 cout.tie(NULL);
#define sl '\n';
typedef long long ll;

int main() {
    inic;
    inic1;
    inic2;
        int n, m;
        cin >> n >> m;
        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }

        while (m--) {
            int l, r, x;
            cin >> l >> r >> x;
            l--, r--, x--;
            
            int cont = 0;
            for (int i = l; i <= r; i++) {
                if (p[i] < p[x]) {
                    cont++;
                }
            }
            if (l + cont == x) {
                cout << "Yes" << sl;
            } else {
                cout << "No" << sl;
            }
        }
    return 0;
}