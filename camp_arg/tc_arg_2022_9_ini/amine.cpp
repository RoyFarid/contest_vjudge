#include <bits/stdc++.h>
using namespace std;
#define inic ios_base::sync_with_stdio(false)
#define inic1 cin.tie(NULL)
#define inic2 cout.tie(NULL)
#define sl '\n'
typedef long long ll;

int main() {
    int N;
    cin >> N;
    string a, b;
    cin >> a >> b;
    int as = a.size();
    int bs = b.size();
    int cyc = as * bs;
 
    int rojn = 0;
    int rojp = 0;
    int coc = N/cyc;
    int res = N % cyc;
    char n, p;
    for(int i = 0; i < cyc && i < N; i++) {
        n = a[i % as], p = b[i % bs];
        if ((n == 'R' && p == 'S') || (n == 'S' && p == 'P') || (n == 'P' && p == 'R')) {
            rojp += coc;
            if (i < res) {
                rojp++;
            } 
        }
        else if ((p == 'R' && n == 'S') || (p == 'S' && n == 'P') || (p == 'P' && n == 'R')) {
            rojn += coc;
            if (i < res) {
                rojn++;
            }
        }
    }
 
    cout << rojn << " " << rojp;
    return 0;
}
