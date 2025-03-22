#include <bits/stdc++.h>
using namespace std;
#define inic ios_base::sync_with_stdio(false)
#define inic1 cin.tie(NULL)
#define inic2 cout.tie(NULL)
#define sl '\n'
typedef long long ll;

int main() {
    inic;
    inic1;
    inic2;
    int n, L;
    cin >> n >> L;
 
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
 
    for(int i = 0; i < n; i++)
        cin >> b[i];
 
    int dis, nd;
    bool f;
    for(int i = 0; i < n; i++) {
        dis = (a[i] - b[0] + L) % L;
 
        f = true;
        for(int j = 0; j < n && f; j++) {
            nd = (a[(i + j) % n] - b[j] + L) % L;
            if (dis != nd) {
                f = false;
            }
        }
        if (f) {
            break;
        }
    }
    if(f) cout << "YES";
    else cout << "NO";
    return 0;
}