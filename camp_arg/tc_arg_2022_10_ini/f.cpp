#include <bits/stdc++.h>
using namespace std;
#define inic ios_base::sync_with_stdio(false)
#define inic1 cin.tie(NULL)
#define inic2 cout.tie(NULL)
#define sl '\n'
typedef long long ll;
const ll MX = 1e9;
int main() {
    inic;
    inic1;
    inic2;
    int n, k;
    cin >> n >> k;
    vector <int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int cont = 1;
    vector <int> conts;
    for(int i = 0; i < n - 1; i++) {
        if(v[i] == v[i + 1]) {
            cont++;
        }
        else {
            conts.push_back(cont);
            cont = 1;
        }
    }
    conts.push_back(cont);
    /* for(int e : conts) {
        cout << e << " ";
    } */
    sort(conts.begin(), conts.end());
    int sz = conts.size();
    int m = conts[sz - 1];
    int plates = m / k;
    if(m % k != 0) plates++;
    plates *= k;
    //cout << plates << sl;
    int sum = 0;
    for(int e : conts) {
        sum += (plates - e);
    }

    cout << sum;
    return 0;
}