#include <bits/stdc++.h>
using namespace std;
#define inic ios_base::sync_with_stdio(false);
#define inic1 cin.tie(NULL);
#define inic2 cout.tie(NULL);
#define sl '\n';
typedef long long ll;

ll dis_c(ll ax, ll ay, ll bx, ll by) {
    ll x = ax-bx;
    ll y = ay-by;
    return x*x + y*y;
}

bool colineal(ll ax, ll ay, ll bx, ll by, ll cx, ll cy) {
    return (bx - ax) * (cy - ay) == (by - ay) * (cx - ax);
}

int main() {
    inic;
    inic1;
    inic2;
    ll ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;
    colineal(ax, ay, bx, by, cx, cy);
    if(dis_c(ax,ay,bx,by) == dis_c(bx,by,cx,cy) && !colineal(ax, ay, bx, by, cx, cy)) {
        cout << "Yes";
    }
    else cout << "No";
    return 0;
}