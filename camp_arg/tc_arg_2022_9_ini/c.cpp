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
    string a, b;
    cin >> a >> b;
    if(a == b) {
        cout << -1 << sl;
    }
    else {
        int sz1 = a.size();
        int sz2 = b.size();
        cout << max(sz1, sz2) << sl; 
    }
    return 0; 
}