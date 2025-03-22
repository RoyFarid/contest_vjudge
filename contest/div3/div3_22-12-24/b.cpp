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
        ll n, a, b, c;
        cin >> n >> a >> b >> c;
        ll days = 3*(n / (a+b+c));
        ll res = n % (a+b+c);
        if(res != 0) {
            if (res > a) {
                if(res > (a+b)) {
                    days += 3;
                }
                else {
                    days+=2;
                }
            }
            else {
                days++;
            }
        }
        cout << days << "\n";
    }
    return 0;
}